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
include CMakeFiles/treeHeight.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/treeHeight.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/treeHeight.dir/flags.make

CMakeFiles/treeHeight.dir/treeHeight.cpp.o: CMakeFiles/treeHeight.dir/flags.make
CMakeFiles/treeHeight.dir/treeHeight.cpp.o: ../treeHeight.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/treeHeight.dir/treeHeight.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/treeHeight.dir/treeHeight.cpp.o -c /home/huangtao/linux/sbox/opengl-test/treeHeight.cpp

CMakeFiles/treeHeight.dir/treeHeight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/treeHeight.dir/treeHeight.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/treeHeight.cpp > CMakeFiles/treeHeight.dir/treeHeight.cpp.i

CMakeFiles/treeHeight.dir/treeHeight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/treeHeight.dir/treeHeight.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/treeHeight.cpp -o CMakeFiles/treeHeight.dir/treeHeight.cpp.s

CMakeFiles/treeHeight.dir/treeHeight.cpp.o.requires:
.PHONY : CMakeFiles/treeHeight.dir/treeHeight.cpp.o.requires

CMakeFiles/treeHeight.dir/treeHeight.cpp.o.provides: CMakeFiles/treeHeight.dir/treeHeight.cpp.o.requires
	$(MAKE) -f CMakeFiles/treeHeight.dir/build.make CMakeFiles/treeHeight.dir/treeHeight.cpp.o.provides.build
.PHONY : CMakeFiles/treeHeight.dir/treeHeight.cpp.o.provides

CMakeFiles/treeHeight.dir/treeHeight.cpp.o.provides.build: CMakeFiles/treeHeight.dir/treeHeight.cpp.o

# Object files for target treeHeight
treeHeight_OBJECTS = \
"CMakeFiles/treeHeight.dir/treeHeight.cpp.o"

# External object files for target treeHeight
treeHeight_EXTERNAL_OBJECTS =

treeHeight: CMakeFiles/treeHeight.dir/treeHeight.cpp.o
treeHeight: CMakeFiles/treeHeight.dir/build.make
treeHeight: CMakeFiles/treeHeight.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable treeHeight"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/treeHeight.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/treeHeight.dir/build: treeHeight
.PHONY : CMakeFiles/treeHeight.dir/build

CMakeFiles/treeHeight.dir/requires: CMakeFiles/treeHeight.dir/treeHeight.cpp.o.requires
.PHONY : CMakeFiles/treeHeight.dir/requires

CMakeFiles/treeHeight.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/treeHeight.dir/cmake_clean.cmake
.PHONY : CMakeFiles/treeHeight.dir/clean

CMakeFiles/treeHeight.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/treeHeight.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/treeHeight.dir/depend

