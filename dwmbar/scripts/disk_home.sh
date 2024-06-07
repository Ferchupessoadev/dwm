#!/bin/bash

color="^c#aaaaaa^^b#000000^"
space_available=$(df -h ~ | awk 'NR==2 {print $4}')
space_all=$(df -h ~ | awk 'NR==2 {print $2}')
icon=""
output="^c#000000^  $color $icon $space_available/$space_all ^d^"
echo $output
