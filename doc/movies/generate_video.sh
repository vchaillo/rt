#!/bin/bash

framerate=25
images=images/*.bmp
time=`date +"%Y%m%e_%H%M%S"`
ffmpeg=../../lib/ffmpeg/ffmpeg_Linux/bin/ffmpeg 

cat $images | $ffmpeg -framerate $framerate -f image2pipe -i - $time.mkv
