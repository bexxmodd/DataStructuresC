# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SemanticAnalyzer.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/SemanticAnalyzer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SemanticAnalyzer.dir/flags.make

CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.o: CMakeFiles/SemanticAnalyzer.dir/flags.make
CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.o -c /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/main.cpp

CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/main.cpp > CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.i

CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/main.cpp -o CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.s

CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.o: CMakeFiles/SemanticAnalyzer.dir/flags.make
CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.o: ../src/Word.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.o -c /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Word.cpp

CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Word.cpp > CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.i

CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Word.cpp -o CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.s

CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.o: CMakeFiles/SemanticAnalyzer.dir/flags.make
CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.o: ../src/Sentence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.o -c /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Sentence.cpp

CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Sentence.cpp > CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.i

CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Sentence.cpp -o CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.s

CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.o: CMakeFiles/SemanticAnalyzer.dir/flags.make
CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.o: ../src/Analyzer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.o -c /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Analyzer.cpp

CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Analyzer.cpp > CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.i

CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/src/Analyzer.cpp -o CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.s

# Object files for target SemanticAnalyzer
SemanticAnalyzer_OBJECTS = \
"CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.o" \
"CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.o" \
"CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.o" \
"CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.o"

# External object files for target SemanticAnalyzer
SemanticAnalyzer_EXTERNAL_OBJECTS =

../bin/SemanticAnalyzer: CMakeFiles/SemanticAnalyzer.dir/src/main.cpp.o
../bin/SemanticAnalyzer: CMakeFiles/SemanticAnalyzer.dir/src/Word.cpp.o
../bin/SemanticAnalyzer: CMakeFiles/SemanticAnalyzer.dir/src/Sentence.cpp.o
../bin/SemanticAnalyzer: CMakeFiles/SemanticAnalyzer.dir/src/Analyzer.cpp.o
../bin/SemanticAnalyzer: CMakeFiles/SemanticAnalyzer.dir/build.make
../bin/SemanticAnalyzer: CMakeFiles/SemanticAnalyzer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../bin/SemanticAnalyzer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SemanticAnalyzer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SemanticAnalyzer.dir/build: ../bin/SemanticAnalyzer
.PHONY : CMakeFiles/SemanticAnalyzer.dir/build

CMakeFiles/SemanticAnalyzer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SemanticAnalyzer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SemanticAnalyzer.dir/clean

CMakeFiles/SemanticAnalyzer.dir/depend:
	cd /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug /home/bexx/Projects/DataStructuresC/CPP/SemanticAnalyzer/cmake-build-debug/CMakeFiles/SemanticAnalyzer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SemanticAnalyzer.dir/depend

