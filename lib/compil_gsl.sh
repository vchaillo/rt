#!/bin/bash
#Only use in case of non-reversible gsl removal.

cd ./gsl-src
./configure --prefix=$PWD/../gsl/
make install
rm ../gsl/lib/*.dylib
