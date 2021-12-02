cmake_minimum_required(VERSION 3.20)
project(SemanticAnalyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compile the passed source files into an executable 
add_executable(SemanticAnalyzer src/main.cpp src/Word.cpp include/Word.h src/Sentence.cpp include/Sentence.h src/Analyzer.cpp include/Analyzer.h)

# Set the output directory for executables
set_target_properties(SemanticAnalyzer
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
