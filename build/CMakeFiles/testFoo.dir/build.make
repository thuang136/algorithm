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
include CMakeFiles/testFoo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testFoo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testFoo.dir/flags.make

CMakeFiles/testFoo.dir/testFoo.cpp.o: CMakeFiles/testFoo.dir/flags.make
CMakeFiles/testFoo.dir/testFoo.cpp.o: ../testFoo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testFoo.dir/testFoo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testFoo.dir/testFoo.cpp.o -c /home/huangtao/linux/sbox/opengl-test/testFoo.cpp

CMakeFiles/testFoo.dir/testFoo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testFoo.dir/testFoo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/testFoo.cpp > CMakeFiles/testFoo.dir/testFoo.cpp.i

CMakeFiles/testFoo.dir/testFoo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testFoo.dir/testFoo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/testFoo.cpp -o CMakeFiles/testFoo.dir/testFoo.cpp.s

CMakeFiles/testFoo.dir/testFoo.cpp.o.requires:
.PHONY : CMakeFiles/testFoo.dir/testFoo.cpp.o.requires

CMakeFiles/testFoo.dir/testFoo.cpp.o.provides: CMakeFiles/testFoo.dir/testFoo.cpp.o.requires
	$(MAKE) -f CMakeFiles/testFoo.dir/build.make CMakeFiles/testFoo.dir/testFoo.cpp.o.provides.build
.PHONY : CMakeFiles/testFoo.dir/testFoo.cpp.o.provides

CMakeFiles/testFoo.dir/testFoo.cpp.o.provides.build: CMakeFiles/testFoo.dir/testFoo.cpp.o

# Object files for target testFoo
testFoo_OBJECTS = \
"CMakeFiles/testFoo.dir/testFoo.cpp.o"

# External object files for target testFoo
testFoo_EXTERNAL_OBJECTS =

testFoo: CMakeFiles/testFoo.dir/testFoo.cpp.o
testFoo: CMakeFiles/testFoo.dir/build.make
testFoo: CMakeFiles/testFoo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testFoo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testFoo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testFoo.dir/build: testFoo
.PHONY : CMakeFiles/testFoo.dir/build

CMakeFiles/testFoo.dir/requires: CMakeFiles/testFoo.dir/testFoo.cpp.o.requires
.PHONY : CMakeFiles/testFoo.dir/requires

CMakeFiles/testFoo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testFoo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testFoo.dir/clean

CMakeFiles/testFoo.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/testFoo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testFoo.dir/depend

