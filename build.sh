#!/bin/bash

cp config.def.h config.h
sudo make install clean
pkill dwm
