#!/bin/bash
#Only use in case of non-reversible gsl removal.

system=`uname -s`
if [ $system != "Linux"  ];then
	system='Macos'
fi
installdir="$PWD/gsl_$system/"
cd ./gsl-src
make clean
./configure --prefix=$installdir
make
echo "Make ENDED!"
sleep 5
make install
echo "Make install ENDED!"
echo "Cleaning..."
make distclean
rm -f $installdir/lib/*.dylib
rm -f $installdir/lib/*.so*
