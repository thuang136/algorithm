# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.2.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.2.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/huangtao/Documents/opengl-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/huangtao/Documents/opengl-test

# Include any dependencies generated for this target.
include CMakeFiles/intersection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/intersection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/intersection.dir/flags.make

CMakeFiles/intersection.dir/intersection.cpp.o: CMakeFiles/intersection.dir/flags.make
CMakeFiles/intersection.dir/intersection.cpp.o: intersection.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/intersection.dir/intersection.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/intersection.dir/intersection.cpp.o -c /Users/huangtao/Documents/opengl-test/intersection.cpp

CMakeFiles/intersection.dir/intersection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/intersection.dir/intersection.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/intersection.cpp > CMakeFiles/intersection.dir/intersection.cpp.i

CMakeFiles/intersection.dir/intersection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/intersection.dir/intersection.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/intersection.cpp -o CMakeFiles/intersection.dir/intersection.cpp.s

CMakeFiles/intersection.dir/intersection.cpp.o.requires:
.PHONY : CMakeFiles/intersection.dir/intersection.cpp.o.requires

CMakeFiles/intersection.dir/intersection.cpp.o.provides: CMakeFiles/intersection.dir/intersection.cpp.o.requires
	$(MAKE) -f CMakeFiles/intersection.dir/build.make CMakeFiles/intersection.dir/intersection.cpp.o.provides.build
.PHONY : CMakeFiles/intersection.dir/intersection.cpp.o.provides

CMakeFiles/intersection.dir/intersection.cpp.o.provides.build: CMakeFiles/intersection.dir/intersection.cpp.o

# Object files for target intersection
intersection_OBJECTS = \
"CMakeFiles/intersection.dir/intersection.cpp.o"

# External object files for target intersection
intersection_EXTERNAL_OBJECTS =

intersection: CMakeFiles/intersection.dir/intersection.cpp.o
intersection: CMakeFiles/intersection.dir/build.make
intersection: CMakeFiles/intersection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable intersection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/intersection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/intersection.dir/build: intersection
.PHONY : CMakeFiles/intersection.dir/build

CMakeFiles/intersection.dir/requires: CMakeFiles/intersection.dir/intersection.cpp.o.requires
.PHONY : CMakeFiles/intersection.dir/requires

CMakeFiles/intersection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/intersection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/intersection.dir/clean

CMakeFiles/intersection.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/intersection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/intersection.dir/depend

