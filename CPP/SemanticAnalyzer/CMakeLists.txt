cmake_minimum_required(VERSION 3.20)
project(SemanticAnalyzer)

set(CMAKE_CXX_STANDARD 17)

add_executable(SemanticAnalyzer src/main.cpp src/Word.cpp include/Word.h src/Sentance.cpp include/Sentance.h)
