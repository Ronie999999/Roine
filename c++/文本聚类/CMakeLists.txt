cmake_minimum_required(VERSION 3.16)
project(homework)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework main.cpp split.cpp split.h word_frequency.cpp word_frequency.h matrix.cpp matrix.h k_means.cpp k_means.h stemmer.cpp stemmer.h)