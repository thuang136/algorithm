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
include CMakeFiles/esShapes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/esShapes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/esShapes.dir/flags.make

CMakeFiles/esShapes.dir/esShapes.c.o: CMakeFiles/esShapes.dir/flags.make
CMakeFiles/esShapes.dir/esShapes.c.o: ../esShapes.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/esShapes.dir/esShapes.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/esShapes.dir/esShapes.c.o   -c /home/huangtao/linux/sbox/opengl-test/esShapes.c

CMakeFiles/esShapes.dir/esShapes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/esShapes.dir/esShapes.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/esShapes.c > CMakeFiles/esShapes.dir/esShapes.c.i

CMakeFiles/esShapes.dir/esShapes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/esShapes.dir/esShapes.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/esShapes.c -o CMakeFiles/esShapes.dir/esShapes.c.s

CMakeFiles/esShapes.dir/esShapes.c.o.requires:
.PHONY : CMakeFiles/esShapes.dir/esShapes.c.o.requires

CMakeFiles/esShapes.dir/esShapes.c.o.provides: CMakeFiles/esShapes.dir/esShapes.c.o.requires
	$(MAKE) -f CMakeFiles/esShapes.dir/build.make CMakeFiles/esShapes.dir/esShapes.c.o.provides.build
.PHONY : CMakeFiles/esShapes.dir/esShapes.c.o.provides

CMakeFiles/esShapes.dir/esShapes.c.o.provides.build: CMakeFiles/esShapes.dir/esShapes.c.o

# Object files for target esShapes
esShapes_OBJECTS = \
"CMakeFiles/esShapes.dir/esShapes.c.o"

# External object files for target esShapes
esShapes_EXTERNAL_OBJECTS =

esShapes: CMakeFiles/esShapes.dir/esShapes.c.o
esShapes: CMakeFiles/esShapes.dir/build.make
esShapes: CMakeFiles/esShapes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable esShapes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/esShapes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/esShapes.dir/build: esShapes
.PHONY : CMakeFiles/esShapes.dir/build

CMakeFiles/esShapes.dir/requires: CMakeFiles/esShapes.dir/esShapes.c.o.requires
.PHONY : CMakeFiles/esShapes.dir/requires

CMakeFiles/esShapes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/esShapes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/esShapes.dir/clean

CMakeFiles/esShapes.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/esShapes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/esShapes.dir/depend

