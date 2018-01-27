cmake_minimum_required(VERSION 3.9)
project(lab2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab2
        dictionary.cc
        dictionary.h
        #reader.cpp
        spell.cc
        word.cc
        word.h)
