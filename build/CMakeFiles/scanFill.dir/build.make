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
include CMakeFiles/scanFill.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scanFill.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scanFill.dir/flags.make

CMakeFiles/scanFill.dir/scanFill.cpp.o: CMakeFiles/scanFill.dir/flags.make
CMakeFiles/scanFill.dir/scanFill.cpp.o: ../scanFill.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/scanFill.dir/scanFill.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/scanFill.dir/scanFill.cpp.o -c /home/huangtao/linux/sbox/opengl-test/scanFill.cpp

CMakeFiles/scanFill.dir/scanFill.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scanFill.dir/scanFill.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/scanFill.cpp > CMakeFiles/scanFill.dir/scanFill.cpp.i

CMakeFiles/scanFill.dir/scanFill.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scanFill.dir/scanFill.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/scanFill.cpp -o CMakeFiles/scanFill.dir/scanFill.cpp.s

CMakeFiles/scanFill.dir/scanFill.cpp.o.requires:
.PHONY : CMakeFiles/scanFill.dir/scanFill.cpp.o.requires

CMakeFiles/scanFill.dir/scanFill.cpp.o.provides: CMakeFiles/scanFill.dir/scanFill.cpp.o.requires
	$(MAKE) -f CMakeFiles/scanFill.dir/build.make CMakeFiles/scanFill.dir/scanFill.cpp.o.provides.build
.PHONY : CMakeFiles/scanFill.dir/scanFill.cpp.o.provides

CMakeFiles/scanFill.dir/scanFill.cpp.o.provides.build: CMakeFiles/scanFill.dir/scanFill.cpp.o

# Object files for target scanFill
scanFill_OBJECTS = \
"CMakeFiles/scanFill.dir/scanFill.cpp.o"

# External object files for target scanFill
scanFill_EXTERNAL_OBJECTS =

scanFill: CMakeFiles/scanFill.dir/scanFill.cpp.o
scanFill: CMakeFiles/scanFill.dir/build.make
scanFill: CMakeFiles/scanFill.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable scanFill"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scanFill.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scanFill.dir/build: scanFill
.PHONY : CMakeFiles/scanFill.dir/build

CMakeFiles/scanFill.dir/requires: CMakeFiles/scanFill.dir/scanFill.cpp.o.requires
.PHONY : CMakeFiles/scanFill.dir/requires

CMakeFiles/scanFill.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scanFill.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scanFill.dir/clean

CMakeFiles/scanFill.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/scanFill.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scanFill.dir/depend

