#!/bin/bash

cd lib
g++ -c libeo.cpp -o libeo.o
ar rvs libeo.a libeo.o
rm libeo.o
