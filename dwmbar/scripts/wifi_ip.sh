#!/bin/bash

color="^c#00b300^"
ip=$(hostname -I)
output=" $color [ IP: $ip ] "
echo $output
