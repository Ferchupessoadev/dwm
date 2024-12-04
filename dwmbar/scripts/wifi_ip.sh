#!/bin/bash

ip=$(hostname -I)
# output=" $color [ IP: $ip ] "
output=" :$ip "
echo $output
