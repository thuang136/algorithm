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
include CMakeFiles/marbles.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/marbles.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/marbles.dir/flags.make

CMakeFiles/marbles.dir/marbles.cpp.o: CMakeFiles/marbles.dir/flags.make
CMakeFiles/marbles.dir/marbles.cpp.o: ../marbles.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/marbles.dir/marbles.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/marbles.dir/marbles.cpp.o -c /home/huangtao/linux/sbox/opengl-test/marbles.cpp

CMakeFiles/marbles.dir/marbles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/marbles.dir/marbles.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/marbles.cpp > CMakeFiles/marbles.dir/marbles.cpp.i

CMakeFiles/marbles.dir/marbles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/marbles.dir/marbles.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/marbles.cpp -o CMakeFiles/marbles.dir/marbles.cpp.s

CMakeFiles/marbles.dir/marbles.cpp.o.requires:
.PHONY : CMakeFiles/marbles.dir/marbles.cpp.o.requires

CMakeFiles/marbles.dir/marbles.cpp.o.provides: CMakeFiles/marbles.dir/marbles.cpp.o.requires
	$(MAKE) -f CMakeFiles/marbles.dir/build.make CMakeFiles/marbles.dir/marbles.cpp.o.provides.build
.PHONY : CMakeFiles/marbles.dir/marbles.cpp.o.provides

CMakeFiles/marbles.dir/marbles.cpp.o.provides.build: CMakeFiles/marbles.dir/marbles.cpp.o

# Object files for target marbles
marbles_OBJECTS = \
"CMakeFiles/marbles.dir/marbles.cpp.o"

# External object files for target marbles
marbles_EXTERNAL_OBJECTS =

marbles: CMakeFiles/marbles.dir/marbles.cpp.o
marbles: CMakeFiles/marbles.dir/build.make
marbles: CMakeFiles/marbles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable marbles"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/marbles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/marbles.dir/build: marbles
.PHONY : CMakeFiles/marbles.dir/build

CMakeFiles/marbles.dir/requires: CMakeFiles/marbles.dir/marbles.cpp.o.requires
.PHONY : CMakeFiles/marbles.dir/requires

CMakeFiles/marbles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/marbles.dir/cmake_clean.cmake
.PHONY : CMakeFiles/marbles.dir/clean

CMakeFiles/marbles.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/marbles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/marbles.dir/depend

