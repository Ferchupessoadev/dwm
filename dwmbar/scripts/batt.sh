#!/bin/bash


icon() {
    [ "$1" -lt "15" ] && printf "" && exit
    [ "$1" -lt "35" ] && printf "" && exit
    [ "$1" -lt "60" ] && printf "" && exit
    [ "$1" -lt "80" ] && printf "" && exit
    printf ""
}

IC_CURRENT=""
IC_PLUG=""

acpi > /tmp/acpi_info
while read line; do
    percent="$(echo "$line" | awk -F ', ' '{print $2}' | sed 's/.$//')"

    if echo "$line" | grep "Discharging," > /dev/null; then
        # DESCARREGANT
        printf "$(icon "$percent") "
        printf "$percent%%"

        time_left="$(echo "$line" | awk '{print $5}' | sed "s/:[0-9][0-9]$//g")"
        printf " ($time_left)"

    elif echo "$line" | grep "Full" > /dev/null; then
        # COMPLETAMENT CARREGADA
        printf "$IC_PLUG 100%%"

    elif ! echo "$line" | grep "Unknown" > /dev/null; then
        # CARREGANT
        printf "$IC_PLUG $percent%%"

    fi
done < /tmp/acpi_info
