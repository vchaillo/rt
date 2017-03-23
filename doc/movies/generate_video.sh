#!/bin/bash

framerate=25
images=images/*.bmp
time=`date +"%Y%m%e_%H%M%S"`

cat $images | ffmpeg -framerate $framerate -f image2pipe -i - $time.mkv
