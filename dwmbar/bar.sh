#!/bin/bash

DIR="$HOME/.config/dwmbar/scripts"
COLOR_FOCUS=^c#E06C75^
while [[ true ]]; do
	fecha_hora="$($DIR/clock.sh)"
	mem="$($DIR/memoria.sh)"
	wifi_ip=$($DIR/wifi_ip.sh)
	disk_root=$($DIR/disk_root.sh)
	vol=$($DIR/volume.sh)
	disk_home=$($DIR/disk_home.sh)
	# xsetroot -name " $disk_root $wifi_ip $mem $fecha_hora $vol "
	xsetroot -name " $disk_home  $disk_root  $wifi_ip $mem $fecha_hora $vol "
	sleep 1
done
