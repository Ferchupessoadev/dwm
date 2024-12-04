#!/bin/bash

DIR="$HOME/.config/dwmbar/scripts"
while [[ true ]]; do
	fecha_hora="$($DIR/clock.sh)"
	mem="$($DIR/memoria.sh)"
	wifi_ip=$($DIR/wifi_ip.sh)
	disk_root=$($DIR/disk_root.sh)
	vol=$($DIR/volume.sh)
	disk_home=$($DIR/disk_home.sh)
	xsetroot -name " $mem $wifi_ip $fecha_hora $vol "
	sleep 1
done
