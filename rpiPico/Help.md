# FreeWatchSW

usefull commands:
- sudo picotool info -f
- sudo picotool save -f main.uf2
- picotool save -f main.uf2      in build
- cmake ../ ; make -j4 ; picotool load -f main.uf2      in build
- minicom -D /dev/ttyACM0 -b 115200

