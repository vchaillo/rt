#!/bin/bash

system=`uname -s`
if [ $system != "Linux"  ];then
		system='MACOS'
	fi
	installdir="$PWD/ffmpeg_$system/"
	cd ./ffmpeg-src
	make clean
	./configure --disable-yasm --prefix=$installdir
	sleep 5
	make
	echo "Make ENDED!"
	sleep 5
	make install
	echo "Make install ENDED!"
	echo "Cleaning..."
	make distclean
	rm -f $installdir/lib/*.dylib
	rm -f $installdir/lib/*.so*
