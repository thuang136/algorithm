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
include CMakeFiles/grid.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/grid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/grid.dir/flags.make

CMakeFiles/grid.dir/grid.cpp.o: CMakeFiles/grid.dir/flags.make
CMakeFiles/grid.dir/grid.cpp.o: ../grid.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/grid.dir/grid.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/grid.dir/grid.cpp.o -c /home/huangtao/linux/sbox/opengl-test/grid.cpp

CMakeFiles/grid.dir/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grid.dir/grid.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/grid.cpp > CMakeFiles/grid.dir/grid.cpp.i

CMakeFiles/grid.dir/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grid.dir/grid.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/grid.cpp -o CMakeFiles/grid.dir/grid.cpp.s

CMakeFiles/grid.dir/grid.cpp.o.requires:
.PHONY : CMakeFiles/grid.dir/grid.cpp.o.requires

CMakeFiles/grid.dir/grid.cpp.o.provides: CMakeFiles/grid.dir/grid.cpp.o.requires
	$(MAKE) -f CMakeFiles/grid.dir/build.make CMakeFiles/grid.dir/grid.cpp.o.provides.build
.PHONY : CMakeFiles/grid.dir/grid.cpp.o.provides

CMakeFiles/grid.dir/grid.cpp.o.provides.build: CMakeFiles/grid.dir/grid.cpp.o

# Object files for target grid
grid_OBJECTS = \
"CMakeFiles/grid.dir/grid.cpp.o"

# External object files for target grid
grid_EXTERNAL_OBJECTS =

grid: CMakeFiles/grid.dir/grid.cpp.o
grid: CMakeFiles/grid.dir/build.make
grid: CMakeFiles/grid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable grid"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/grid.dir/build: grid
.PHONY : CMakeFiles/grid.dir/build

CMakeFiles/grid.dir/requires: CMakeFiles/grid.dir/grid.cpp.o.requires
.PHONY : CMakeFiles/grid.dir/requires

CMakeFiles/grid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/grid.dir/cmake_clean.cmake
.PHONY : CMakeFiles/grid.dir/clean

CMakeFiles/grid.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/grid.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/grid.dir/depend

