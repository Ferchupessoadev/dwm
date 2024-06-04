#!/bin/bash

DIR="$HOME/.config/dwmbar/scripts"
while [[ true ]]; do
	fecha_hora="$($DIR/clock.sh)"
	mem="$($DIR/memoria.sh)"
	wifi_ip=$($DIR/wifi_ip.sh)
	disk_root=$($DIR/disk_root.sh)
	vol=$($DIR/volume.sh)
	xsetroot -name " $disk_root $wifi_ip $mem $fecha_hora $vol "
	sleep 1
done
