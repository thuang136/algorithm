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
include CMakeFiles/thread1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/thread1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thread1.dir/flags.make

CMakeFiles/thread1.dir/thread1.cpp.o: CMakeFiles/thread1.dir/flags.make
CMakeFiles/thread1.dir/thread1.cpp.o: ../thread1.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/thread1.dir/thread1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/thread1.dir/thread1.cpp.o -c /home/huangtao/linux/sbox/opengl-test/thread1.cpp

CMakeFiles/thread1.dir/thread1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread1.dir/thread1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/thread1.cpp > CMakeFiles/thread1.dir/thread1.cpp.i

CMakeFiles/thread1.dir/thread1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread1.dir/thread1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/thread1.cpp -o CMakeFiles/thread1.dir/thread1.cpp.s

CMakeFiles/thread1.dir/thread1.cpp.o.requires:
.PHONY : CMakeFiles/thread1.dir/thread1.cpp.o.requires

CMakeFiles/thread1.dir/thread1.cpp.o.provides: CMakeFiles/thread1.dir/thread1.cpp.o.requires
	$(MAKE) -f CMakeFiles/thread1.dir/build.make CMakeFiles/thread1.dir/thread1.cpp.o.provides.build
.PHONY : CMakeFiles/thread1.dir/thread1.cpp.o.provides

CMakeFiles/thread1.dir/thread1.cpp.o.provides.build: CMakeFiles/thread1.dir/thread1.cpp.o

# Object files for target thread1
thread1_OBJECTS = \
"CMakeFiles/thread1.dir/thread1.cpp.o"

# External object files for target thread1
thread1_EXTERNAL_OBJECTS =

thread1: CMakeFiles/thread1.dir/thread1.cpp.o
thread1: CMakeFiles/thread1.dir/build.make
thread1: CMakeFiles/thread1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable thread1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thread1.dir/build: thread1
.PHONY : CMakeFiles/thread1.dir/build

CMakeFiles/thread1.dir/requires: CMakeFiles/thread1.dir/thread1.cpp.o.requires
.PHONY : CMakeFiles/thread1.dir/requires

CMakeFiles/thread1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thread1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thread1.dir/clean

CMakeFiles/thread1.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/thread1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thread1.dir/depend

