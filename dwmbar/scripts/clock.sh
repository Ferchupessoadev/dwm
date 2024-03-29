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


clock=$(date "+  %d/%m/%Y $icon %I:%M%p")
clock_format="^c#ffffff^$clock "
echo $clock_format
