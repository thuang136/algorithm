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
include CMakeFiles/testGlew.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testGlew.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testGlew.dir/flags.make

CMakeFiles/testGlew.dir/testGlew.cpp.o: CMakeFiles/testGlew.dir/flags.make
CMakeFiles/testGlew.dir/testGlew.cpp.o: ../testGlew.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testGlew.dir/testGlew.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testGlew.dir/testGlew.cpp.o -c /home/huangtao/linux/sbox/opengl-test/testGlew.cpp

CMakeFiles/testGlew.dir/testGlew.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testGlew.dir/testGlew.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/testGlew.cpp > CMakeFiles/testGlew.dir/testGlew.cpp.i

CMakeFiles/testGlew.dir/testGlew.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testGlew.dir/testGlew.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/testGlew.cpp -o CMakeFiles/testGlew.dir/testGlew.cpp.s

CMakeFiles/testGlew.dir/testGlew.cpp.o.requires:
.PHONY : CMakeFiles/testGlew.dir/testGlew.cpp.o.requires

CMakeFiles/testGlew.dir/testGlew.cpp.o.provides: CMakeFiles/testGlew.dir/testGlew.cpp.o.requires
	$(MAKE) -f CMakeFiles/testGlew.dir/build.make CMakeFiles/testGlew.dir/testGlew.cpp.o.provides.build
.PHONY : CMakeFiles/testGlew.dir/testGlew.cpp.o.provides

CMakeFiles/testGlew.dir/testGlew.cpp.o.provides.build: CMakeFiles/testGlew.dir/testGlew.cpp.o

# Object files for target testGlew
testGlew_OBJECTS = \
"CMakeFiles/testGlew.dir/testGlew.cpp.o"

# External object files for target testGlew
testGlew_EXTERNAL_OBJECTS =

testGlew: CMakeFiles/testGlew.dir/testGlew.cpp.o
testGlew: CMakeFiles/testGlew.dir/build.make
testGlew: CMakeFiles/testGlew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testGlew"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testGlew.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testGlew.dir/build: testGlew
.PHONY : CMakeFiles/testGlew.dir/build

CMakeFiles/testGlew.dir/requires: CMakeFiles/testGlew.dir/testGlew.cpp.o.requires
.PHONY : CMakeFiles/testGlew.dir/requires

CMakeFiles/testGlew.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testGlew.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testGlew.dir/clean

CMakeFiles/testGlew.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/testGlew.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testGlew.dir/depend

