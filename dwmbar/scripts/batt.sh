#!/bin/bash

COL_VERMEL="#32a852"
COL_TARONJA="#f0660a"
COL_GROC="#f0dd0a"
COL_BLANC="#ff0000"

colors() {
    [ "$1" -lt "15" ] && printf "$COL_VERMELL" && exit
    [ "$1" -lt "35" ] && printf "$COL_TARONJA" && exit
    [ "$1" -lt "60" ] && printf "$COL_GROC"    && exit
    printf "$COL_BLANC"
}

icona() {
    [ "$1" -lt "15" ] && printf "" && exit
    [ "$1" -lt "35" ] && printf "" && exit
    [ "$1" -lt "60" ] && printf "" && exit
    [ "$1" -lt "80" ] && printf "" && exit
    printf ""
}

IC_CURRENT="^c$COL_GROC^"
IC_PLUG="^c$COL_BLANC^"

acpi > /tmp/acpi_info
while read line; do
    percent="$(echo "$line" | awk -F ', ' '{print $2}' | sed 's/.$//')"

    if echo "$line" | grep "Discharging," > /dev/null; then
        # DESCARREGANT
        printf "^c$(colors "$percent")^"
        printf "$(icona "$percent") "
        printf "$percent%%"

        time_left="$(echo "$line" | awk '{print $5}' | sed "s/:[0-9][0-9]$//g")"
        printf " ($time_left)"

    elif echo "$line" | grep "Full" > /dev/null; then
        # COMPLETAMENT CARREGADA
        printf "$IC_PLUG 100%%"

    elif ! echo "$line" | grep "Unknown" > /dev/null; then
        # CARREGANT
        printf "$IC_CURRENT $IC_PLUG $percent%%"

    fi
done < /tmp/acpi_info
