cmake_minimum_required(VERSION 3.20)
project(Html)

set(CMAKE_CXX_STANDARD 17)

add_executable(Html src/main.cpp include/HtmlTag.h src/HtmlTag.cpp src/HtmlValidator.cpp include/HtmlValidator.h)
