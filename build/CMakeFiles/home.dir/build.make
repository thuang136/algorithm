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
include CMakeFiles/home.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/home.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/home.dir/flags.make

CMakeFiles/home.dir/home.cpp.o: CMakeFiles/home.dir/flags.make
CMakeFiles/home.dir/home.cpp.o: ../home.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/home.dir/home.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/home.dir/home.cpp.o -c /home/huangtao/linux/sbox/opengl-test/home.cpp

CMakeFiles/home.dir/home.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/home.dir/home.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/home.cpp > CMakeFiles/home.dir/home.cpp.i

CMakeFiles/home.dir/home.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/home.dir/home.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/home.cpp -o CMakeFiles/home.dir/home.cpp.s

CMakeFiles/home.dir/home.cpp.o.requires:
.PHONY : CMakeFiles/home.dir/home.cpp.o.requires

CMakeFiles/home.dir/home.cpp.o.provides: CMakeFiles/home.dir/home.cpp.o.requires
	$(MAKE) -f CMakeFiles/home.dir/build.make CMakeFiles/home.dir/home.cpp.o.provides.build
.PHONY : CMakeFiles/home.dir/home.cpp.o.provides

CMakeFiles/home.dir/home.cpp.o.provides.build: CMakeFiles/home.dir/home.cpp.o

# Object files for target home
home_OBJECTS = \
"CMakeFiles/home.dir/home.cpp.o"

# External object files for target home
home_EXTERNAL_OBJECTS =

home: CMakeFiles/home.dir/home.cpp.o
home: CMakeFiles/home.dir/build.make
home: CMakeFiles/home.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable home"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/home.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/home.dir/build: home
.PHONY : CMakeFiles/home.dir/build

CMakeFiles/home.dir/requires: CMakeFiles/home.dir/home.cpp.o.requires
.PHONY : CMakeFiles/home.dir/requires

CMakeFiles/home.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/home.dir/cmake_clean.cmake
.PHONY : CMakeFiles/home.dir/clean

CMakeFiles/home.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/home.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/home.dir/depend

