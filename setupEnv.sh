#/bin/sh

sudo apt update
sudo apt install -y git wget libusb-1.0-0-dev

cd ~/
echo `pwd`
mkdir pico
cd pico



git clone https://github.com/raspberrypi/pico-sdk.git --branch master
cd pico-sdk 
git submodule update --init
cd ..
git clone https://github.com/raspberrypi/pico-examples.git --branch master



sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential


# change this to whatever shell you use, 
# for bash change .zshrc to .bashrc
sh_file="/home/$USER/.zshrc"


touch $sh_file

echo "export PICO_SDK_PATH=~/pico/pico-sdk" >> $sh_file
echo "export PICO_EXAMPLES_PATH=~/pico/pico-examples" >> $sh_file
#echo "export PICO_EXTRAS_PATH=~/pico/pico-extras" >> $sh_file
#echo "export PICO_PLAYGROUND_PATH=~/pico/pico-playground" >> $sh_file





# picotool 

git clone https://github.com/raspberrypi/picotool.git --branch master
cd picotool
sudo cp udev/99-picotool.rules /etc/udev/rules.d/
mkdir build 
cd build 
export PICO_SDK_PATH=/home/$USER/pico/pico-sdk
cmake ../
make
sudo make install 




