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
include CMakeFiles/BstIterator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BstIterator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BstIterator.dir/flags.make

CMakeFiles/BstIterator.dir/BstIterator.cpp.o: CMakeFiles/BstIterator.dir/flags.make
CMakeFiles/BstIterator.dir/BstIterator.cpp.o: BstIterator.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/BstIterator.dir/BstIterator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BstIterator.dir/BstIterator.cpp.o -c /Users/huangtao/Documents/opengl-test/BstIterator.cpp

CMakeFiles/BstIterator.dir/BstIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BstIterator.dir/BstIterator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/BstIterator.cpp > CMakeFiles/BstIterator.dir/BstIterator.cpp.i

CMakeFiles/BstIterator.dir/BstIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BstIterator.dir/BstIterator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/BstIterator.cpp -o CMakeFiles/BstIterator.dir/BstIterator.cpp.s

CMakeFiles/BstIterator.dir/BstIterator.cpp.o.requires:
.PHONY : CMakeFiles/BstIterator.dir/BstIterator.cpp.o.requires

CMakeFiles/BstIterator.dir/BstIterator.cpp.o.provides: CMakeFiles/BstIterator.dir/BstIterator.cpp.o.requires
	$(MAKE) -f CMakeFiles/BstIterator.dir/build.make CMakeFiles/BstIterator.dir/BstIterator.cpp.o.provides.build
.PHONY : CMakeFiles/BstIterator.dir/BstIterator.cpp.o.provides

CMakeFiles/BstIterator.dir/BstIterator.cpp.o.provides.build: CMakeFiles/BstIterator.dir/BstIterator.cpp.o

# Object files for target BstIterator
BstIterator_OBJECTS = \
"CMakeFiles/BstIterator.dir/BstIterator.cpp.o"

# External object files for target BstIterator
BstIterator_EXTERNAL_OBJECTS =

BstIterator: CMakeFiles/BstIterator.dir/BstIterator.cpp.o
BstIterator: CMakeFiles/BstIterator.dir/build.make
BstIterator: CMakeFiles/BstIterator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable BstIterator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BstIterator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BstIterator.dir/build: BstIterator
.PHONY : CMakeFiles/BstIterator.dir/build

CMakeFiles/BstIterator.dir/requires: CMakeFiles/BstIterator.dir/BstIterator.cpp.o.requires
.PHONY : CMakeFiles/BstIterator.dir/requires

CMakeFiles/BstIterator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BstIterator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BstIterator.dir/clean

CMakeFiles/BstIterator.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/BstIterator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BstIterator.dir/depend

