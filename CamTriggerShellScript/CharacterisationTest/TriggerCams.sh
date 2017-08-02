#/bin/sh

echo "Taking pics"

fswebcam -d /dev/video0 --no-banner "$1cam0"
fswebcam -d /dev/video1 --no-banner "$1cam1"

pylepton_capture -f "$1cam2.png"