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
include CMakeFiles/cairo_roundRectangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cairo_roundRectangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cairo_roundRectangle.dir/flags.make

CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o: CMakeFiles/cairo_roundRectangle.dir/flags.make
CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o: ../cairo_roundRectangle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o -c /home/huangtao/linux/sbox/opengl-test/cairo_roundRectangle.cpp

CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/cairo_roundRectangle.cpp > CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.i

CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/cairo_roundRectangle.cpp -o CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.s

CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o.requires:
.PHONY : CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o.requires

CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o.provides: CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/cairo_roundRectangle.dir/build.make CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o.provides.build
.PHONY : CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o.provides

CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o.provides.build: CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o

# Object files for target cairo_roundRectangle
cairo_roundRectangle_OBJECTS = \
"CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o"

# External object files for target cairo_roundRectangle
cairo_roundRectangle_EXTERNAL_OBJECTS =

cairo_roundRectangle: CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o
cairo_roundRectangle: CMakeFiles/cairo_roundRectangle.dir/build.make
cairo_roundRectangle: CMakeFiles/cairo_roundRectangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cairo_roundRectangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cairo_roundRectangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cairo_roundRectangle.dir/build: cairo_roundRectangle
.PHONY : CMakeFiles/cairo_roundRectangle.dir/build

CMakeFiles/cairo_roundRectangle.dir/requires: CMakeFiles/cairo_roundRectangle.dir/cairo_roundRectangle.cpp.o.requires
.PHONY : CMakeFiles/cairo_roundRectangle.dir/requires

CMakeFiles/cairo_roundRectangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cairo_roundRectangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cairo_roundRectangle.dir/clean

CMakeFiles/cairo_roundRectangle.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/cairo_roundRectangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cairo_roundRectangle.dir/depend

