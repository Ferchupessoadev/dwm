# My Build of DWM - Dynamic Window Manager

![build of DWM](./screenshot_dwm.png)

## How to Install DWM

### First, Install Dependencies

#### Debian/Ubuntu
```bash
sudo apt install build-essential git libx11-dev libxft-dev libxinerama-dev
```

#### Arch Linux
```bash
sudo pacman -S base-devel git libx11 libxft libxinerama
```

#### Fedora
```bash
sudo dnf install @development-tools git libX11-devel libXft-devel libXinerama-devel
```

#### Void Linux
```bash
sudo xbps-install -S base-devel git libX11-devel libXft-devel libXinerama-devel
```

### Clone This Repository
```bash
git clone https://github.com/Ferchupessoadev/dwm.git
```

### Build and Install
```bash
cd dwm
sudo make clean install
```

### Autostart Scripts
Copy the `autostart.sh` file to `~/.local/share/dwm/autostart.sh` because DWM will run it:
```bash
mkdir -p ~/.local/share/dwm
cp -r autostart.sh ~/.local/share/dwm/autostart.sh
```

Copy the `dwmbar` folder to `~/.config/dwmbar` because `autostart.sh` will run it:
```bash
cp -r dwmbar ~/.config/dwmbar
```

## Running DWM with a Display Manager
If you use a display manager (e.g., LightDM, GDM, SDDM), create a session file:

Create `/usr/share/xsessions/dwm.desktop` with the following content:
```ini
[Desktop Entry]
Name=DWM
Comment=Dynamic Window Manager
Exec=dwm
Type=Application
```

## How to Create a Shortcut in DWM

```C
// config.def.h

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, SHCMD("dmenu_run")},
    {MODKEY, XK_r, spawn, SHCMD("dmenu_run_desktop -c -l 10")},
    {MODKEY, XK_Return, spawn, SHCMD("st")},
    {MODKEY, XK_g, spawn, SHCMD("chromium")},
    // others keys
};
```

