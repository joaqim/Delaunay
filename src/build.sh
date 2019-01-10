#!/bin/bash
rm main &>/dev/null &
rm test.bmp &>/dev/null &
set e
make main -j6 -I .
./main 10
