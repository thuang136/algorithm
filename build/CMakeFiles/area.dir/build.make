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
include CMakeFiles/area.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/area.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/area.dir/flags.make

CMakeFiles/area.dir/area.cpp.o: CMakeFiles/area.dir/flags.make
CMakeFiles/area.dir/area.cpp.o: ../area.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/area.dir/area.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/area.dir/area.cpp.o -c /home/huangtao/linux/sbox/opengl-test/area.cpp

CMakeFiles/area.dir/area.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/area.dir/area.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/area.cpp > CMakeFiles/area.dir/area.cpp.i

CMakeFiles/area.dir/area.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/area.dir/area.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/area.cpp -o CMakeFiles/area.dir/area.cpp.s

CMakeFiles/area.dir/area.cpp.o.requires:
.PHONY : CMakeFiles/area.dir/area.cpp.o.requires

CMakeFiles/area.dir/area.cpp.o.provides: CMakeFiles/area.dir/area.cpp.o.requires
	$(MAKE) -f CMakeFiles/area.dir/build.make CMakeFiles/area.dir/area.cpp.o.provides.build
.PHONY : CMakeFiles/area.dir/area.cpp.o.provides

CMakeFiles/area.dir/area.cpp.o.provides.build: CMakeFiles/area.dir/area.cpp.o

# Object files for target area
area_OBJECTS = \
"CMakeFiles/area.dir/area.cpp.o"

# External object files for target area
area_EXTERNAL_OBJECTS =

area: CMakeFiles/area.dir/area.cpp.o
area: CMakeFiles/area.dir/build.make
area: CMakeFiles/area.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable area"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/area.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/area.dir/build: area
.PHONY : CMakeFiles/area.dir/build

CMakeFiles/area.dir/requires: CMakeFiles/area.dir/area.cpp.o.requires
.PHONY : CMakeFiles/area.dir/requires

CMakeFiles/area.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/area.dir/cmake_clean.cmake
.PHONY : CMakeFiles/area.dir/clean

CMakeFiles/area.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/area.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/area.dir/depend

