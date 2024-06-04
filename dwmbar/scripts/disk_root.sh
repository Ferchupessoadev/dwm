
color="^c#aaaaaa^"
storage=$(df -h / | awk 'NR==2 {print $3 " / " $2}')
icon="  "
output=" $color [ $icon  $storage ]"
echo $output

