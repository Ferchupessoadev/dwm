
color="^c#aaaaaa^^b#000000^"
storage=$(df -h / | awk 'NR==2 {print $3 " / " $2}')
icon="  "
# output=" $color [ $icon  $storage ]"
output="$color $icon $storage ^d^"
echo $output

