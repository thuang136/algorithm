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
include CMakeFiles/firstOrder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/firstOrder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/firstOrder.dir/flags.make

CMakeFiles/firstOrder.dir/firstOrder.cpp.o: CMakeFiles/firstOrder.dir/flags.make
CMakeFiles/firstOrder.dir/firstOrder.cpp.o: firstOrder.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/firstOrder.dir/firstOrder.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/firstOrder.dir/firstOrder.cpp.o -c /Users/huangtao/Documents/opengl-test/firstOrder.cpp

CMakeFiles/firstOrder.dir/firstOrder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstOrder.dir/firstOrder.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/firstOrder.cpp > CMakeFiles/firstOrder.dir/firstOrder.cpp.i

CMakeFiles/firstOrder.dir/firstOrder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstOrder.dir/firstOrder.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/firstOrder.cpp -o CMakeFiles/firstOrder.dir/firstOrder.cpp.s

CMakeFiles/firstOrder.dir/firstOrder.cpp.o.requires:
.PHONY : CMakeFiles/firstOrder.dir/firstOrder.cpp.o.requires

CMakeFiles/firstOrder.dir/firstOrder.cpp.o.provides: CMakeFiles/firstOrder.dir/firstOrder.cpp.o.requires
	$(MAKE) -f CMakeFiles/firstOrder.dir/build.make CMakeFiles/firstOrder.dir/firstOrder.cpp.o.provides.build
.PHONY : CMakeFiles/firstOrder.dir/firstOrder.cpp.o.provides

CMakeFiles/firstOrder.dir/firstOrder.cpp.o.provides.build: CMakeFiles/firstOrder.dir/firstOrder.cpp.o

# Object files for target firstOrder
firstOrder_OBJECTS = \
"CMakeFiles/firstOrder.dir/firstOrder.cpp.o"

# External object files for target firstOrder
firstOrder_EXTERNAL_OBJECTS =

firstOrder: CMakeFiles/firstOrder.dir/firstOrder.cpp.o
firstOrder: CMakeFiles/firstOrder.dir/build.make
firstOrder: CMakeFiles/firstOrder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable firstOrder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/firstOrder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/firstOrder.dir/build: firstOrder
.PHONY : CMakeFiles/firstOrder.dir/build

CMakeFiles/firstOrder.dir/requires: CMakeFiles/firstOrder.dir/firstOrder.cpp.o.requires
.PHONY : CMakeFiles/firstOrder.dir/requires

CMakeFiles/firstOrder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/firstOrder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/firstOrder.dir/clean

CMakeFiles/firstOrder.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/firstOrder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/firstOrder.dir/depend

