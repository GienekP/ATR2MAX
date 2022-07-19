#!/bin/sh

gcc -Wall -o SectorMap SectorMap.c
./SectorMap

./mads starter128m.asm -o:starter128m.bin
./mads starter256m.asm -o:starter256m.bin

xxd -cols 16 -i starter128m.bin > starter128m.h
xxd -cols 16 -i starter256m.bin > starter256m.h

gcc -Wall -o atr2max atr2max.c
./atr2max
