#!/bin/bash

DIR="$HOME/.config/dwmbar/scripts"
while [[ true ]]; do
	fecha_hora="$($DIR/clock.sh)"
	batt="$($DIR/batt.sh)"
	mem="$($DIR/memoria.sh)"
	vol="$($DIR/volume.sh)"
	xsetroot -name " $vol  $mem  $batt  $fecha_hora "
	sleep 5
done
