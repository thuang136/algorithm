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
include CMakeFiles/midCircle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/midCircle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/midCircle.dir/flags.make

CMakeFiles/midCircle.dir/midCircle.cpp.o: CMakeFiles/midCircle.dir/flags.make
CMakeFiles/midCircle.dir/midCircle.cpp.o: midCircle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/midCircle.dir/midCircle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/midCircle.dir/midCircle.cpp.o -c /Users/huangtao/Documents/opengl-test/midCircle.cpp

CMakeFiles/midCircle.dir/midCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/midCircle.dir/midCircle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/midCircle.cpp > CMakeFiles/midCircle.dir/midCircle.cpp.i

CMakeFiles/midCircle.dir/midCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/midCircle.dir/midCircle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/midCircle.cpp -o CMakeFiles/midCircle.dir/midCircle.cpp.s

CMakeFiles/midCircle.dir/midCircle.cpp.o.requires:
.PHONY : CMakeFiles/midCircle.dir/midCircle.cpp.o.requires

CMakeFiles/midCircle.dir/midCircle.cpp.o.provides: CMakeFiles/midCircle.dir/midCircle.cpp.o.requires
	$(MAKE) -f CMakeFiles/midCircle.dir/build.make CMakeFiles/midCircle.dir/midCircle.cpp.o.provides.build
.PHONY : CMakeFiles/midCircle.dir/midCircle.cpp.o.provides

CMakeFiles/midCircle.dir/midCircle.cpp.o.provides.build: CMakeFiles/midCircle.dir/midCircle.cpp.o

# Object files for target midCircle
midCircle_OBJECTS = \
"CMakeFiles/midCircle.dir/midCircle.cpp.o"

# External object files for target midCircle
midCircle_EXTERNAL_OBJECTS =

midCircle: CMakeFiles/midCircle.dir/midCircle.cpp.o
midCircle: CMakeFiles/midCircle.dir/build.make
midCircle: CMakeFiles/midCircle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable midCircle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/midCircle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/midCircle.dir/build: midCircle
.PHONY : CMakeFiles/midCircle.dir/build

CMakeFiles/midCircle.dir/requires: CMakeFiles/midCircle.dir/midCircle.cpp.o.requires
.PHONY : CMakeFiles/midCircle.dir/requires

CMakeFiles/midCircle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/midCircle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/midCircle.dir/clean

CMakeFiles/midCircle.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/midCircle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/midCircle.dir/depend

