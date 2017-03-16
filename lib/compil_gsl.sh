#!/bin/bash
#Only use in case of non-reversible gsl removal.

installdir="$PWD/gsl_`uname -s`/"
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
