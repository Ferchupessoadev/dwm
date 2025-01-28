# My build of Dwm - Dynamic window manager

![build of Dwm](./screenshot_dwm.png)

## How to install dwm

### First, install dependencies

## Debian/Ubuntu
```bash

sudo apt install build-essential git libx11-dev libxft-dev libxinerama-dev

```

## Archlinux
```bash

sudo pacman -S base-devel git libx11 libxft libxinerama

```

## Fedora
```bash

sudo dnf install @development-tools git libX11-devel libXft-devel libXinerama-devel

```

## void linux
```bash

sudo xbps-install -S base-devel git libX11-devel libXft-devel libXinerama-devel

```

then clone this repo

```bash

git clone https://github.com/Ferchupessoadev/dwm.git

```

then build and install

```bash
cd dwm
sudo make clean install
```

then copy the file autostart.sh to ~/.local/share/dwm/autostart.sh

```bash
mkdir -p ~/.local/share/dwm
cp -r autostart.sh ~/.local/share/dwm/autostart.sh
```

then copy dwmbar folder to .config/dwmbar

```bash

cp -r dwmbar ~/.config/dwmbar

```
