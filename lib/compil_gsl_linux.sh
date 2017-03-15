#!/bin/bash
#Only use in case of non-reversible gsl removal.

cd ./gsl-src
make distclean
./configure --prefix=$PWD/../gsl_linux/
make install
rm ../gsl_linux/lib/*.dylib
