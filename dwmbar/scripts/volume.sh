#!/bin/bash

# colors
COL_VERMEL="#32a852"
COL_TARONJA="#f0660a"
COL_GROC="#f0dd0a"
COL_BLANC="#ff0000"


case $BLOCK_BUTTON in
    1) pactl set-sink-mute @DEFAULT_SINK@ toggle ;;
esac

vol() {
    pactl list sinks | grep 'Volumen:' | head -n 1 | awk '{print $5}' | sed 's/%//'
}

str() {
    echo "$1"
}

if [ "$(pactl list sinks | awk '/Mute:/ {print $2}')" = "yes" ]; then
    #str "SILENCIAT"
    str "  "
    exit 0
fi

v=$(vol)
if [ "$v" -gt "100" ]; then 
    str "  100% "
elif [ "$v" -ge "50" ]; then 
    str " 󰕾 $v% "
else 
    str "  $v% "
fi
