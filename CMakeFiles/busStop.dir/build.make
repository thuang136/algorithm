# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.2.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.2.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/huangtao/Documents/opengl-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/huangtao/Documents/opengl-test

# Include any dependencies generated for this target.
include CMakeFiles/busStop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/busStop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/busStop.dir/flags.make

CMakeFiles/busStop.dir/busStop.cpp.o: CMakeFiles/busStop.dir/flags.make
CMakeFiles/busStop.dir/busStop.cpp.o: busStop.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/busStop.dir/busStop.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/busStop.dir/busStop.cpp.o -c /Users/huangtao/Documents/opengl-test/busStop.cpp

CMakeFiles/busStop.dir/busStop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/busStop.dir/busStop.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/busStop.cpp > CMakeFiles/busStop.dir/busStop.cpp.i

CMakeFiles/busStop.dir/busStop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/busStop.dir/busStop.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/busStop.cpp -o CMakeFiles/busStop.dir/busStop.cpp.s

CMakeFiles/busStop.dir/busStop.cpp.o.requires:
.PHONY : CMakeFiles/busStop.dir/busStop.cpp.o.requires

CMakeFiles/busStop.dir/busStop.cpp.o.provides: CMakeFiles/busStop.dir/busStop.cpp.o.requires
	$(MAKE) -f CMakeFiles/busStop.dir/build.make CMakeFiles/busStop.dir/busStop.cpp.o.provides.build
.PHONY : CMakeFiles/busStop.dir/busStop.cpp.o.provides

CMakeFiles/busStop.dir/busStop.cpp.o.provides.build: CMakeFiles/busStop.dir/busStop.cpp.o

# Object files for target busStop
busStop_OBJECTS = \
"CMakeFiles/busStop.dir/busStop.cpp.o"

# External object files for target busStop
busStop_EXTERNAL_OBJECTS =

busStop: CMakeFiles/busStop.dir/busStop.cpp.o
busStop: CMakeFiles/busStop.dir/build.make
busStop: CMakeFiles/busStop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable busStop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/busStop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/busStop.dir/build: busStop
.PHONY : CMakeFiles/busStop.dir/build

CMakeFiles/busStop.dir/requires: CMakeFiles/busStop.dir/busStop.cpp.o.requires
.PHONY : CMakeFiles/busStop.dir/requires

CMakeFiles/busStop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/busStop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/busStop.dir/clean

CMakeFiles/busStop.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/busStop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/busStop.dir/depend

