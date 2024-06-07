#!/bin/bash

color="^c#00b300^^b#000000^"
ip=$(hostname -I)
# output=" $color [ IP: $ip ] "
output=" $color IP: $ip ^d^"
echo $output
