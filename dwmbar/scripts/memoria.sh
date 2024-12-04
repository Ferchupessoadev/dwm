#!/bin/bash

# color="^c#dddddd^"
text="$(free -h | awk '/^Mem/ { print $3"/"$2 }' | sed s/i//g)"
# echo "$color [ Ram: $text ]"
echo "  :$text "
