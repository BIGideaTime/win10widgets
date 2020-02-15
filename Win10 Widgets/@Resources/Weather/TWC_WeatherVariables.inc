; � 2019 by Xxenium
; Code portions borrowed from JSMorley

; Modified by Eclectic Tech Jan 18, 2020 :: Combined variables to work as an @include file for TWC weather data retrieval

; ################# ONE-TIME SETUP INSTRUCTIONS #############################

; Getting and setting your LocationCode can be done one of a couple of ways.
; 
; Go to https://weather.com/
; Search for your city by name.
; Use the long number at the end of the resulting URL, for example:
; https://weather.com/weather/today/l/d6ddc64611fafe9e42246c9121cca4035cc4a4558e28cf0c6e0982a7ef837329
; The LocationCode would be d6ddc64611fafe9e42246c9121cca4035cc4a4558e28cf0c6e0982a7ef837329
; Copy and enter that as the value for LocationCode below.
;
; Alternatively, in the USA, you can simply use your ZipCode as the LocationCode.
; The weather.com CountryRegion codes (e.g.; USNY0996) will also work as the LocationCode.
; NOTE: Imperial/Metric values displayed are determined based on the language selected; 

; If another language or unit(s) of measures are desired, simply go to https://weather.com/
; Using the controls at the top of the page, set your country, language, and units of measure as desired.
; Copy and enter the LangLoc from the resulting URL, and the long number at the end as the LocationCode.

; For example, French would be LangLoc=fr-FR

; Note that simply changing from imperial F to metric C units of measure while keeping the 
; langage as English can be done by using en-GB as the LangLoc.

[Variables]

LocationCode=USNY0996

LangLoc=en-US

; =====================================
; Don't change anything below here.
; =====================================

WeatherUpdateRate=6000

; Current Weather Data
URL=https://weather.com/#LangLoc#/weather/today/l/#LocationCode#

; Hour by hour
URL2=https://weather.com/#LangLoc#/weather/hourbyhour/l/#LocationCode#

; Forecast and Details
URL3=https://weather.com/#LangLoc#/weather/tenday/l/#LocationCode#

Days=7
Hours=2

Location=(?siU)(?(?=.*<h1 class="h4 today_nowcard-location").* className="h4 today_nowcard-location">(.*)<span class=".*" className=".*"></span></h1>)

TempUnit=(?siU)<span class="icon icon-font iconset-ui icon-globe" className="icon icon-font iconset-ui icon-globe"></span><span>.*</span><span class="styles__borderLeft__2zhrE">(.*)</span>

NOW=(?siU)(?(?=.*</div></span><p class="today_nowcard-).*timestamp"><span>(.*)<!----> </span><span>(.*)</span>).*(?(?=.*<div class="today_nowcard-section today_nowcard-condition"><div class="condition-icon wx-weather-icon vector).*"><icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon icon-svg icon-svg-.* .* icon-.*">.*</icon></div>)(?(?=.*<div class="today_nowcard-temp").*><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<div class="today_nowcard-phrase).*">(.*)</div>)(?(?=.*<div class="today_nowcard-feels).*"><span class="btn-text">(.*)<!----> </span><span class="deg-feels" className="deg-feels">(.*)<sup>(.*)</sup></span>).*(?(?=.*<div class="today_nowcard-hilo").*><span class="btn-text">.*<!----> </span><span class="deg-hilo-nowcard"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<span class="btn-text">.*<!---->).* </span><span class="deg-hilo-nowcard"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<div class="today_nowcard-sidecar component panel"><table><caption>(.*)</caption><tbody>).*<tr><th>(.*)</th><td><span class="">(.*)</span></td></tr><tr><th>(.*)</th><td><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span></span></span></td></tr><tr><th>.*</th><td><span class="">.*<sup>.*</sup></span></td></tr><tr><th>(.*)</th><td><span class="">(.*)<!---->.*</span></td></tr><tr><th>(.*)</th><td><span class="">(.*)</span></td>)

36HOURS=(?siU)(?(?=.*<div class="today-daypart daypart-0).*  selected" id="daypart-0" data-track-string="today-looking-ahead_lookingAhead0hours" className="today-daypart daypart-0  selected"><div class="today-daypart-content" className="today-daypart-content"><div class="today-daypart-top"><span class="today-daypart-title" id="dp0-daypartName">(.*)</span>)(?(?=.*<span class="today-daypart-wxphrase").* id="dp0-phrase">(.*)</span></div>)(?(?=.*<div class="condition-icon wx-weather-icon").* aria-hidden="true" id="la-part0-icon"><icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon icon-svg icon-svg-.* .* icon-.*">.*</icon></div>)(?(?=.*<div class="today-daypart-hilo" id="dp0-).*highLow">(.*)</div>)(?(?=.*<div class="today-daypart-temp").*><span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*<div class="today-daypart-precip").*><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class="precip-val" className="precip-val"><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="today-daypart daypart-1").* id="daypart-1" data-track-string="today-looking-ahead_lookingAhead12hours" className="today-daypart daypart-1"><div class="today-daypart-content" className="today-daypart-content"><div class="today-daypart-top"><span class="today-daypart-title" id="dp1-daypartName">(.*)</span>)(?(?=.*<span class="today-daypart-wxphrase").* id="dp1-phrase">(.*)</span></div>)(?(?=.*<div class="condition-icon wx-weather-icon").* aria-hidden="true" id="la-part1-icon"><icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon icon-svg icon-svg-.* .* icon-.*">.*</icon></div>)(?(?=.*<div class="today-daypart-hilo" id="dp1-).*highLow">(.*)</div>)(?(?=.*<div class="today-daypart-temp").*><span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*<div class="today-daypart-precip").*><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class="precip-val" className="precip-val"><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="today-daypart daypart-2").* id="daypart-2" data-track-string="today-looking-ahead_lookingAhead24hours" className="today-daypart daypart-2"><div class="today-daypart-content" className="today-daypart-content"><div class="today-daypart-top"><span class="today-daypart-title" id="dp2-daypartName">(.*)</span>)(?(?=.*<span class="today-daypart-wxphrase").* id="dp2-phrase">(.*)</span></div>)(?(?=.*<div class="condition-icon wx-weather-icon").* aria-hidden="true" id="la-part2-icon"><icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon icon-svg icon-svg-.* .* icon-.*">.*</icon></div>)(?(?=.*<div class="today-daypart-hilo" id="dp2-).*highLow">(.*)</div>)(?(?=.*<div class="today-daypart-temp").*><span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*<div class="today-daypart-precip").*><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class="precip-val" className="precip-val"><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="today-daypart daypart-3").* id="daypart-3" data-track-string="today-looking-ahead_lookingAhead36hours" className="today-daypart daypart-3"><div class="today-daypart-content" className="today-daypart-content"><div class="today-daypart-top"><span class="today-daypart-title" id="dp3-daypartName">(.*)</span>)(?(?=.*<span class="today-daypart-wxphrase").* id="dp3-phrase">(.*)</span></div>)(?(?=.*<div class="condition-icon wx-weather-icon").* aria-hidden="true" id="la-part3-icon"><icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon icon-svg icon-svg-.* .* icon-.*">.*</icon></div>)(?(?=.*<div class="today-daypart-hilo" id="dp3-).*highLow">(.*)</div>)(?(?=.*<div class="today-daypart-temp").*><span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*<div class="today-daypart-precip").*><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class="precip-val" className="precip-val"><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="today-daypart daypart-4").* id="daypart-4" data-track-string="today-looking-ahead_lookingAhead48hours" className="today-daypart daypart-4"><div class="today-daypart-content" className="today-daypart-content"><div class="today-daypart-top"><span class="today-daypart-title" id="dp4-daypartName">(.*)</span>)(?(?=.*<span class="today-daypart-wxphrase").* id="dp4-phrase">(.*)</span></div>)(?(?=.*<div class="condition-icon wx-weather-icon").* aria-hidden="true" id="la-part4-icon"><icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon icon-svg icon-svg-.* .* icon-.*">.*</icon></div>)(?(?=.*<div class="today-daypart-hilo" id="dp4-).*highLow">(.*)</div>)(?(?=.*<div class="today-daypart-temp").*><span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*<div class="today-daypart-precip").*><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class="precip-val" className="precip-val"><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>)

Hourly=(?siU)(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*<div class="hourly-time").*><span class="dsx-date">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky").* className="twc-table-shadow sticky"></div></div><div class="hourly-date">(.*)</div>).*(?(?=.*<td class="hidden-cell-sm description" headers="description").* data-track-string="ls_hourly_ls_hourly_toggle" className="hidden-cell-sm description"><span>(.*)</span>)(?(?=.*</td><td class="temp" headers="temp").* data-track-string="ls_hourly_ls_hourly_toggle" className="temp"><span class="">(.*)<sup>(.*)</sup></span>).*(?(?=.*<td class="precip" headers="precip").* data-track-string="ls_hourly_ls_hourly_toggle" className="precip"><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*

Forecast=(?siU)(?(?=.*</td><td class="twc-sticky-col" headers="day" .* className="twc-sticky-col").*><div><div><span class="date-time">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky" className="twc-table-shadow sticky").*></div></div><span class="day-detail clearfix">(.*)</span></div>)(?(?=.*</td><td class="description" .* className="description").*><span>(.*)</span>).*(?(?=.*</td><td class="precip" .* className="precip").*><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*</td><td class="twc-sticky-col" headers="day" .* className="twc-sticky-col").*><div><div><span class="date-time">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky" className="twc-table-shadow sticky").*></div></div><span class="day-detail clearfix">(.*)</span></div>)(?(?=.*</td><td class="description" .* className="description").*><span>(.*)</span>)(?(?=.*</td><td class="temp" .* className="temp").*><div><span class="">(.*)<sup>(.*)</sup></span>.*<span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*</td><td class="precip" .* className="precip").*><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*</td><td class="twc-sticky-col" headers="day" .* className="twc-sticky-col").*><div><div><span class="date-time">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky" className="twc-table-shadow sticky").*></div></div><span class="day-detail clearfix">(.*)</span></div>)(?(?=.*</td><td class="description" .* className="description").*><span>(.*)</span>)(?(?=.*</td><td class="temp" .* className="temp").*><div><span class="">(.*)<sup>(.*)</sup></span>.*<span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*</td><td class="precip" .* className="precip").*><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*</td><td class="twc-sticky-col" headers="day" .* className="twc-sticky-col").*><div><div><span class="date-time">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky" className="twc-table-shadow sticky").*></div></div><span class="day-detail clearfix">(.*)</span></div>)(?(?=.*</td><td class="description" .* className="description").*><span>(.*)</span>)(?(?=.*</td><td class="temp" .* className="temp").*><div><span class="">(.*)<sup>(.*)</sup></span>.*<span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*</td><td class="precip" .* className="precip").*><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*</td><td class="twc-sticky-col" headers="day" .* className="twc-sticky-col").*><div><div><span class="date-time">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky" className="twc-table-shadow sticky").*></div></div><span class="day-detail clearfix">(.*)</span></div>)(?(?=.*</td><td class="description" .* className="description").*><span>(.*)</span>)(?(?=.*</td><td class="temp" .* className="temp").*><div><span class="">(.*)<sup>(.*)</sup></span>.*<span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*</td><td class="precip" .* className="precip").*><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*</td><td class="twc-sticky-col" headers="day" .* className="twc-sticky-col").*><div><div><span class="date-time">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky" className="twc-table-shadow sticky").*></div></div><span class="day-detail clearfix">(.*)</span></div>)(?(?=.*</td><td class="description" .* className="description").*><span>(.*)</span>)(?(?=.*</td><td class="temp" .* className="temp").*><div><span class="">(.*)<sup>(.*)</sup></span>.*<span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*</td><td class="precip" .* className="precip").*><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*</td><td class="twc-sticky-col" headers="day" .* className="twc-sticky-col").*><div><div><span class="date-time">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky" className="twc-table-shadow sticky").*></div></div><span class="day-detail clearfix">(.*)</span></div>)(?(?=.*</td><td class="description" .* className="description").*><span>(.*)</span>)(?(?=.*</td><td class="temp" .* className="temp").*><div><span class="">(.*)<sup>(.*)</sup></span>.*<span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*</td><td class="precip" .* className="precip").*><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*(?(?=.*</td><td class="twc-sticky-col" headers="day" .* className="twc-sticky-col").*><div><div><span class="date-time">(.*)</span>)(?(?=.*<icon class="icon icon-svg icon-svg-.* .* icon-(.*)" className="icon).* icon-svg icon-svg-.* .* icon-.*">.*</icon>)(?(?=.*<div class="twc-table-shadow sticky" className="twc-table-shadow sticky").*></div></div><span class="day-detail clearfix">(.*)</span></div>)(?(?=.*</td><td class="description" .* className="description").*><span>(.*)</span>)(?(?=.*</td><td class="temp" .* className="temp").*><div><span class="">(.*)<sup>(.*)</sup></span>.*<span class="">(.*)<sup>(.*)</sup></span></div>)(?(?=.*</td><td class="precip" .* className="precip").*><div><span class="icon icon-font iconset-weather-data icon-drop-1" className="icon icon-font iconset-weather-data icon-drop-1"></span><span class=""><span>(.*)<span class="Percentage__percentSymbol__2Q_AR">(.*)</span>).*

SUN=(?siU)(?(?=.*<span class="wx-detail-label show-sm">.*</span).*<span class="wx-dsxdate" id="dp0-details-(.*)">(.*)</span>.*<span class="wx-dsxdate" id="dp0-details-(.*)">(.*)</span>)

Details=(?siU)(?(?=.*<td class="twc-sticky-col" headers="day" title="(.*)").* .* className="twc-sticky-col"><div>).*(?(?=.*<td class="twc-sticky-col" headers="day" title="(.*)").* .* className="twc-sticky-col"><div>).*(?(?=.*<td class="twc-sticky-col" headers="day" title="(.*)").* .* className="twc-sticky-col"><div>).*(?(?=.*<td class="twc-sticky-col" headers="day" title="(.*)").* .* className="twc-sticky-col"><div>).*(?(?=.*<td class="twc-sticky-col" headers="day" title="(.*)").* .* className="twc-sticky-col"><div>).*(?(?=.*<td class="twc-sticky-col" headers="day" title="(.*)").* .* className="twc-sticky-col"><div>).*(?(?=.*<td class="twc-sticky-col" headers="day" title="(.*)").* .* className="twc-sticky-col"><div>).*(?(?=.*<td class="twc-sticky-col" headers="day" title="(.*)").* .* className="twc-sticky-col"><div>)

DetailsT=(?siU)(?(?=.*div class="dp-details" id="dp0-details").* className="dp-details"><span class="today-wx-descrip" id="dp0-details-narrative">(.*)</span>)


; � 2019 by Xxenium