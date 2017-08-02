#!/bin/sh

echo "Taking pics"

STRING1=$1

echo $STRING1


fswebcam -d /dev/video0 --no-banner "$1cam0" 

fswebcam -d /dev/video1 --no-banner "$1cam1"

fswebcam -d /dev/video2 --no-banner "$1cam2"

#pylepton_capture "$1cam3.png"
