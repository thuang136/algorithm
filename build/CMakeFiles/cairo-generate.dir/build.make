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
include CMakeFiles/cairo-generate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cairo-generate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cairo-generate.dir/flags.make

CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o: CMakeFiles/cairo-generate.dir/flags.make
CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o: ../cairo-generate.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o -c /home/huangtao/linux/sbox/opengl-test/cairo-generate.cpp

CMakeFiles/cairo-generate.dir/cairo-generate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cairo-generate.dir/cairo-generate.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/cairo-generate.cpp > CMakeFiles/cairo-generate.dir/cairo-generate.cpp.i

CMakeFiles/cairo-generate.dir/cairo-generate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cairo-generate.dir/cairo-generate.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/cairo-generate.cpp -o CMakeFiles/cairo-generate.dir/cairo-generate.cpp.s

CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o.requires:
.PHONY : CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o.requires

CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o.provides: CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o.requires
	$(MAKE) -f CMakeFiles/cairo-generate.dir/build.make CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o.provides.build
.PHONY : CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o.provides

CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o.provides.build: CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o

# Object files for target cairo-generate
cairo__generate_OBJECTS = \
"CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o"

# External object files for target cairo-generate
cairo__generate_EXTERNAL_OBJECTS =

cairo-generate: CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o
cairo-generate: CMakeFiles/cairo-generate.dir/build.make
cairo-generate: CMakeFiles/cairo-generate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cairo-generate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cairo-generate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cairo-generate.dir/build: cairo-generate
.PHONY : CMakeFiles/cairo-generate.dir/build

CMakeFiles/cairo-generate.dir/requires: CMakeFiles/cairo-generate.dir/cairo-generate.cpp.o.requires
.PHONY : CMakeFiles/cairo-generate.dir/requires

CMakeFiles/cairo-generate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cairo-generate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cairo-generate.dir/clean

CMakeFiles/cairo-generate.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/cairo-generate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cairo-generate.dir/depend

