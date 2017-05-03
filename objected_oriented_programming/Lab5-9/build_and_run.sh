#!/bin/bash

g++ -std=c++14 -Wall utilities/functions.cpp tests/tests.cpp exceptions/repository_exception.cpp exceptions/controller_exception.cpp controller/controller.cpp domain/movie.cpp repository/html_repository.cpp repository/file_repository.cpp repository/repository.cpp ui/ui.cpp main.cpp -o main

./main

rm main
