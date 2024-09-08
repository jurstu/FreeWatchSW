#!/bin/sh
./build.sh
echo `pwd`
cd bild
picotool load -f main.uf2
