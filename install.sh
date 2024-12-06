#!/bin/bash


echo "instalando dependencias de dwm"

sudo apt install build-essential git libx11-dev libxft-dev libxinerama-dev

echo "¿Instalar fuente JetBrains Mono Nerd Font?"

read -p "Con esta fuente, dwm se ve mucho mejor y/n: " option
while [[ $option -ne 'y' ]] && [[ $option -ne 'n' ]] && [[ $option -ne 'Y' ]] && [[ $option -ne 'N' ]]; do
	read -p "Con esta fuente, dwm se ve mucho mejor y/n: " option
done


if [[ "$option" == "n" ]] || [[ "$option" == "N" ]]; then
	exit
fi

echo "Instalando JetBrains"

directory=$(ls ~/.fonts | grep JetBrains)
if [ -z "$directory" ]; then
	mkdir -p ~/.fonts
	if ! command -v wget; then
		echo "No se pudo descargar la fuente"
		sudo apt-get install wget
	fi
	wget https://github.com/ryanoasis/nerd-fonts/releases/download/v2.2.2/JetBrainsMono.zip
	unzip JetBrainsMono.zip -d ~/.fonts
	rm JetBrainsMono.zip
else
	echo "Ya tienes la fuente instalada, hurra!"
fi

echo "Instalando dwm..."

git clone https://github.com/Ferchupessoadev/dwm.git
cd dwm

cp config.def.h config.h
sudo make clean install

echo "instalando autostart.sh"

mkdir -p ~/.local/share/dwm
cp -r autostart.sh ~/.local/share/dwm/autostart.sh

cd ..

echo "Instalación de dwm terminada!"

git clone https://github.com/Ferchupessoadev/dmenu.git

cd dmenu
cp config.def.h config.h
sudo make clean install

cd ..

echo "Instalación de dmenu terminada!"

echo "instalando st(simple terminal)"

git clone https://github.com/Ferchupessoadev/st.git

cd st
cp config.def.h config.h
sudo make clean install

cd ..

echo "Instalación de st terminada!"

cd dwm

cp -r dwmbar/ ~/.config/dwmbar

echo "Instalación de dwmbar terminada!"

echo "Instalación terminada!"
