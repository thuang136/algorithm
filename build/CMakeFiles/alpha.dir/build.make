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
include CMakeFiles/alpha.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alpha.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alpha.dir/flags.make

CMakeFiles/alpha.dir/alpha.cpp.o: CMakeFiles/alpha.dir/flags.make
CMakeFiles/alpha.dir/alpha.cpp.o: ../alpha.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/alpha.dir/alpha.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/alpha.dir/alpha.cpp.o -c /home/huangtao/linux/sbox/opengl-test/alpha.cpp

CMakeFiles/alpha.dir/alpha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alpha.dir/alpha.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/alpha.cpp > CMakeFiles/alpha.dir/alpha.cpp.i

CMakeFiles/alpha.dir/alpha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alpha.dir/alpha.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/alpha.cpp -o CMakeFiles/alpha.dir/alpha.cpp.s

CMakeFiles/alpha.dir/alpha.cpp.o.requires:
.PHONY : CMakeFiles/alpha.dir/alpha.cpp.o.requires

CMakeFiles/alpha.dir/alpha.cpp.o.provides: CMakeFiles/alpha.dir/alpha.cpp.o.requires
	$(MAKE) -f CMakeFiles/alpha.dir/build.make CMakeFiles/alpha.dir/alpha.cpp.o.provides.build
.PHONY : CMakeFiles/alpha.dir/alpha.cpp.o.provides

CMakeFiles/alpha.dir/alpha.cpp.o.provides.build: CMakeFiles/alpha.dir/alpha.cpp.o

# Object files for target alpha
alpha_OBJECTS = \
"CMakeFiles/alpha.dir/alpha.cpp.o"

# External object files for target alpha
alpha_EXTERNAL_OBJECTS =

alpha: CMakeFiles/alpha.dir/alpha.cpp.o
alpha: CMakeFiles/alpha.dir/build.make
alpha: CMakeFiles/alpha.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable alpha"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alpha.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alpha.dir/build: alpha
.PHONY : CMakeFiles/alpha.dir/build

CMakeFiles/alpha.dir/requires: CMakeFiles/alpha.dir/alpha.cpp.o.requires
.PHONY : CMakeFiles/alpha.dir/requires

CMakeFiles/alpha.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/alpha.dir/cmake_clean.cmake
.PHONY : CMakeFiles/alpha.dir/clean

CMakeFiles/alpha.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/alpha.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alpha.dir/depend

