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
include CMakeFiles/city.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/city.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/city.dir/flags.make

CMakeFiles/city.dir/city.cpp.o: CMakeFiles/city.dir/flags.make
CMakeFiles/city.dir/city.cpp.o: ../city.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/city.dir/city.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/city.dir/city.cpp.o -c /home/huangtao/linux/sbox/opengl-test/city.cpp

CMakeFiles/city.dir/city.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/city.dir/city.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangtao/linux/sbox/opengl-test/city.cpp > CMakeFiles/city.dir/city.cpp.i

CMakeFiles/city.dir/city.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/city.dir/city.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangtao/linux/sbox/opengl-test/city.cpp -o CMakeFiles/city.dir/city.cpp.s

CMakeFiles/city.dir/city.cpp.o.requires:
.PHONY : CMakeFiles/city.dir/city.cpp.o.requires

CMakeFiles/city.dir/city.cpp.o.provides: CMakeFiles/city.dir/city.cpp.o.requires
	$(MAKE) -f CMakeFiles/city.dir/build.make CMakeFiles/city.dir/city.cpp.o.provides.build
.PHONY : CMakeFiles/city.dir/city.cpp.o.provides

CMakeFiles/city.dir/city.cpp.o.provides.build: CMakeFiles/city.dir/city.cpp.o

# Object files for target city
city_OBJECTS = \
"CMakeFiles/city.dir/city.cpp.o"

# External object files for target city
city_EXTERNAL_OBJECTS =

city: CMakeFiles/city.dir/city.cpp.o
city: CMakeFiles/city.dir/build.make
city: CMakeFiles/city.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable city"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/city.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/city.dir/build: city
.PHONY : CMakeFiles/city.dir/build

CMakeFiles/city.dir/requires: CMakeFiles/city.dir/city.cpp.o.requires
.PHONY : CMakeFiles/city.dir/requires

CMakeFiles/city.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/city.dir/cmake_clean.cmake
.PHONY : CMakeFiles/city.dir/clean

CMakeFiles/city.dir/depend:
	cd /home/huangtao/linux/sbox/opengl-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build /home/huangtao/linux/sbox/opengl-test/build/CMakeFiles/city.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/city.dir/depend
