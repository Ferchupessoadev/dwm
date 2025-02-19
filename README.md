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

clone this repo

```bash

git clone https://github.com/Ferchupessoadev/dwm.git

```

build and install

```bash
cd dwm
sudo make clean install
```

copy the file autostart.sh to ~/.local/share/dwm/autostart.sh because dwm will run it

```bash
mkdir -p ~/.local/share/dwm
cp -r autostart.sh ~/.local/share/dwm/autostart.sh
```

copy dwmbar folder to .config/dwmbar because dwm will run it with the autostart.sh

```bash

cp -r dwmbar ~/.config/dwmbar

```

## How create a shortcut in dwm

```C
// config.def.h

static const Key keys[] = {
    // Other key bindings
    // Change the key combination and the command in the SHCMD macro

    { MODKEY, XK_Return, spawn, SHCMD("st") },

    // Other key bindings
};
```
