#!/bin/bash

clock=$(date '+%I')

case "$clock" in
	"00") icon="󱑖" ;;
	"01") icon="󱑋" ;;
	"02") icon="󱑌" ;;
	"03") icon="󱑍" ;;
	"04") icon="󱑎" ;;
	"05") icon="󱑏" ;;
	"06") icon="󱑐" ;;
	"07") icon="󱑑" ;;
	"08") icon="󱑒" ;;
	"09") icon="󱑓" ;;
	"10") icon="󱑔" ;;
	"11") icon="󱑕" ;;
	"12") icon="󱑖" ;;
esac
color=^c#ffff80^^b#000000^
calendar_icon="   "
clock_date=$(date "+ %d/%m/%Y")
clock_time=$(date "+ %I:%M%p")
# clock_format="^c#ffff80^ [ $calendar_icon $clock_date $icon $clock_time ]"
clock_format="$color $calendar_icon $clock_date $icon $clock_time ^d^"
echo $clock_format
