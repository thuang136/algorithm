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
include CMakeFiles/circulation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/circulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/circulation.dir/flags.make

CMakeFiles/circulation.dir/circulation.cpp.o: CMakeFiles/circulation.dir/flags.make
CMakeFiles/circulation.dir/circulation.cpp.o: ../circulation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/circulation.dir/circulation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/circulation.dir/circulation.cpp.o -c /home/huangtao/linux/sbox/opengl-test/circulation.cpp

CMakeFiles/circulation.dir/circulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/circulation.dir/circulation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/circulation.cpp > CMakeFiles/circulation.dir/circulation.cpp.i

CMakeFiles/circulation.dir/circulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/circulation.dir/circulation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/circulation.cpp -o CMakeFiles/circulation.dir/circulation.cpp.s

CMakeFiles/circulation.dir/circulation.cpp.o.requires:
.PHONY : CMakeFiles/circulation.dir/circulation.cpp.o.requires

CMakeFiles/circulation.dir/circulation.cpp.o.provides: CMakeFiles/circulation.dir/circulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/circulation.dir/build.make CMakeFiles/circulation.dir/circulation.cpp.o.provides.build
.PHONY : CMakeFiles/circulation.dir/circulation.cpp.o.provides

CMakeFiles/circulation.dir/circulation.cpp.o.provides.build: CMakeFiles/circulation.dir/circulation.cpp.o

# Object files for target circulation
circulation_OBJECTS = \
"CMakeFiles/circulation.dir/circulation.cpp.o"

# External object files for target circulation
circulation_EXTERNAL_OBJECTS =

circulation: CMakeFiles/circulation.dir/circulation.cpp.o
circulation: CMakeFiles/circulation.dir/build.make
circulation: CMakeFiles/circulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable circulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/circulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/circulation.dir/build: circulation
.PHONY : CMakeFiles/circulation.dir/build

CMakeFiles/circulation.dir/requires: CMakeFiles/circulation.dir/circulation.cpp.o.requires
.PHONY : CMakeFiles/circulation.dir/requires

CMakeFiles/circulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/circulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/circulation.dir/clean

CMakeFiles/circulation.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/circulation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/circulation.dir/depend

