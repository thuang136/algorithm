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
include CMakeFiles/testRef.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testRef.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testRef.dir/flags.make

CMakeFiles/testRef.dir/testRef.cpp.o: CMakeFiles/testRef.dir/flags.make
CMakeFiles/testRef.dir/testRef.cpp.o: ../testRef.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testRef.dir/testRef.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testRef.dir/testRef.cpp.o -c /home/huangtao/linux/sbox/opengl-test/testRef.cpp

CMakeFiles/testRef.dir/testRef.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testRef.dir/testRef.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/testRef.cpp > CMakeFiles/testRef.dir/testRef.cpp.i

CMakeFiles/testRef.dir/testRef.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testRef.dir/testRef.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/testRef.cpp -o CMakeFiles/testRef.dir/testRef.cpp.s

CMakeFiles/testRef.dir/testRef.cpp.o.requires:
.PHONY : CMakeFiles/testRef.dir/testRef.cpp.o.requires

CMakeFiles/testRef.dir/testRef.cpp.o.provides: CMakeFiles/testRef.dir/testRef.cpp.o.requires
	$(MAKE) -f CMakeFiles/testRef.dir/build.make CMakeFiles/testRef.dir/testRef.cpp.o.provides.build
.PHONY : CMakeFiles/testRef.dir/testRef.cpp.o.provides

CMakeFiles/testRef.dir/testRef.cpp.o.provides.build: CMakeFiles/testRef.dir/testRef.cpp.o

# Object files for target testRef
testRef_OBJECTS = \
"CMakeFiles/testRef.dir/testRef.cpp.o"

# External object files for target testRef
testRef_EXTERNAL_OBJECTS =

testRef: CMakeFiles/testRef.dir/testRef.cpp.o
testRef: CMakeFiles/testRef.dir/build.make
testRef: CMakeFiles/testRef.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testRef"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testRef.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testRef.dir/build: testRef
.PHONY : CMakeFiles/testRef.dir/build

CMakeFiles/testRef.dir/requires: CMakeFiles/testRef.dir/testRef.cpp.o.requires
.PHONY : CMakeFiles/testRef.dir/requires

CMakeFiles/testRef.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testRef.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testRef.dir/clean

CMakeFiles/testRef.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/testRef.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testRef.dir/depend
