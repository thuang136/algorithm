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
include CMakeFiles/mergeSortedArray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mergeSortedArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mergeSortedArray.dir/flags.make

CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o: CMakeFiles/mergeSortedArray.dir/flags.make
CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o: ../mergeSortedArray.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o -c /home/huangtao/linux/sbox/opengl-test/mergeSortedArray.cpp

CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/mergeSortedArray.cpp > CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.i

CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/mergeSortedArray.cpp -o CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.s

CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o.requires:
.PHONY : CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o.requires

CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o.provides: CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o.requires
	$(MAKE) -f CMakeFiles/mergeSortedArray.dir/build.make CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o.provides.build
.PHONY : CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o.provides

CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o.provides.build: CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o

# Object files for target mergeSortedArray
mergeSortedArray_OBJECTS = \
"CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o"

# External object files for target mergeSortedArray
mergeSortedArray_EXTERNAL_OBJECTS =

mergeSortedArray: CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o
mergeSortedArray: CMakeFiles/mergeSortedArray.dir/build.make
mergeSortedArray: CMakeFiles/mergeSortedArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable mergeSortedArray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mergeSortedArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mergeSortedArray.dir/build: mergeSortedArray
.PHONY : CMakeFiles/mergeSortedArray.dir/build

CMakeFiles/mergeSortedArray.dir/requires: CMakeFiles/mergeSortedArray.dir/mergeSortedArray.cpp.o.requires
.PHONY : CMakeFiles/mergeSortedArray.dir/requires

CMakeFiles/mergeSortedArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mergeSortedArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mergeSortedArray.dir/clean

CMakeFiles/mergeSortedArray.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/mergeSortedArray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mergeSortedArray.dir/depend

