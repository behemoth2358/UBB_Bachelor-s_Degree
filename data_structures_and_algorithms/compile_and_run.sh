#!/bin/bash

g++ -std=c++14 tests.cpp problem.cpp -o main

./main $@

rm main
