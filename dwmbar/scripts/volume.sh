#!/bin/bash

# colors
COL_VERMEL="#32a852"
COL_TARONJA="#f0660a"
COL_GROC="#f0dd0a"
COL_BLANC="#ff0000"

# script per al volum sense utilitzar "amixer"
# utilitza "pactl"

case $BLOCK_BUTTON in
    1) pactl set-sink-mute @DEFAULT_SINK@ toggle ;;
esac

# això mostra el volum actual
vol() {
	pactl list sinks | grep 'Volumen:' | head -n 1 | awk -F/ '{print $2}'
}

str() {
    echo "^c$COL_TARONJA^$1"
}

# primer comprovam si està mutejat
if [ "$(pacmd list-sinks | awk '/muted/ { print $2 }')" = "yes" ]; then
	#str "SILENCIAT"
	str "  "
	exit 0
fi;

# en cas que no estigui mutejat no haurà sortit
v=$(vol)
if [ "$v" -gt "100%" ]; then str "$v"
elif [ "$v" -ge "50%" ]; then str "$v"
else str "$v"; fi
