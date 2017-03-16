#!/bin/bash
#Only use in case of non-reversible gsl removal.

installdir="$PWD/gsl/"
cd ./gsl-src
make clean
./configure --prefix=$installdir
make
echo "Make ENDED!"
sleep 5
make install
echo "Make install ENDED!"
rm -f ../gsl/lib/*.dylib
