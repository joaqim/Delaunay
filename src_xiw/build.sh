#!/bin/bash
rm main &>/dev/null &
rm test.bmp &>/dev/null &
set e
make main -j6
./main 10
cp "test.bmp" ~/Downloads/Documents/ &>/dev/null &
