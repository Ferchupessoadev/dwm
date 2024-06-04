#!/bin/bash

color="^c#b3b300^"
# color="^c#dddddd^"
text="$(free -h | awk '/^Mem/ { print $3"/"$2 }' | sed s/i//g)"
echo "$color [ Ram: $text ]"
