# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huangtao/linux/sbox/opengl-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huangtao/linux/sbox/opengl-test/build

# Include any dependencies generated for this target.
include CMakeFiles/pixelBuffer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pixelBuffer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pixelBuffer.dir/flags.make

CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o: CMakeFiles/pixelBuffer.dir/flags.make
CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o: ../pixelBuffer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o -c /home/huangtao/linux/sbox/opengl-test/pixelBuffer.cpp

CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/pixelBuffer.cpp > CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.i

CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/pixelBuffer.cpp -o CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.s

CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o.requires:
.PHONY : CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o.requires

CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o.provides: CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/pixelBuffer.dir/build.make CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o.provides.build
.PHONY : CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o.provides

CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o.provides.build: CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o

# Object files for target pixelBuffer
pixelBuffer_OBJECTS = \
"CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o"

# External object files for target pixelBuffer
pixelBuffer_EXTERNAL_OBJECTS =

pixelBuffer: CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o
pixelBuffer: CMakeFiles/pixelBuffer.dir/build.make
pixelBuffer: CMakeFiles/pixelBuffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable pixelBuffer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pixelBuffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pixelBuffer.dir/build: pixelBuffer
.PHONY : CMakeFiles/pixelBuffer.dir/build

CMakeFiles/pixelBuffer.dir/requires: CMakeFiles/pixelBuffer.dir/pixelBuffer.cpp.o.requires
.PHONY : CMakeFiles/pixelBuffer.dir/requires

CMakeFiles/pixelBuffer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pixelBuffer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pixelBuffer.dir/clean

CMakeFiles/pixelBuffer.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/pixelBuffer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pixelBuffer.dir/depend

