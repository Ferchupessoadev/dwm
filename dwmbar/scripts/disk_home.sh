#!/bin/bash

space_available=$(df -h ~ | awk 'NR==2 {print $4}')
space_all=$(df -h ~ | awk 'NR==2 {print $2}')
icon=""
output=" $icon $space_available/$space_all"
echo $output
