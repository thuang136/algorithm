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
include CMakeFiles/hayPoint.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hayPoint.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hayPoint.dir/flags.make

CMakeFiles/hayPoint.dir/hayPoint.cpp.o: CMakeFiles/hayPoint.dir/flags.make
CMakeFiles/hayPoint.dir/hayPoint.cpp.o: hayPoint.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hayPoint.dir/hayPoint.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hayPoint.dir/hayPoint.cpp.o -c /Users/huangtao/Documents/opengl-test/hayPoint.cpp

CMakeFiles/hayPoint.dir/hayPoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hayPoint.dir/hayPoint.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/hayPoint.cpp > CMakeFiles/hayPoint.dir/hayPoint.cpp.i

CMakeFiles/hayPoint.dir/hayPoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hayPoint.dir/hayPoint.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/hayPoint.cpp -o CMakeFiles/hayPoint.dir/hayPoint.cpp.s

CMakeFiles/hayPoint.dir/hayPoint.cpp.o.requires:
.PHONY : CMakeFiles/hayPoint.dir/hayPoint.cpp.o.requires

CMakeFiles/hayPoint.dir/hayPoint.cpp.o.provides: CMakeFiles/hayPoint.dir/hayPoint.cpp.o.requires
	$(MAKE) -f CMakeFiles/hayPoint.dir/build.make CMakeFiles/hayPoint.dir/hayPoint.cpp.o.provides.build
.PHONY : CMakeFiles/hayPoint.dir/hayPoint.cpp.o.provides

CMakeFiles/hayPoint.dir/hayPoint.cpp.o.provides.build: CMakeFiles/hayPoint.dir/hayPoint.cpp.o

# Object files for target hayPoint
hayPoint_OBJECTS = \
"CMakeFiles/hayPoint.dir/hayPoint.cpp.o"

# External object files for target hayPoint
hayPoint_EXTERNAL_OBJECTS =

hayPoint: CMakeFiles/hayPoint.dir/hayPoint.cpp.o
hayPoint: CMakeFiles/hayPoint.dir/build.make
hayPoint: CMakeFiles/hayPoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable hayPoint"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hayPoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hayPoint.dir/build: hayPoint
.PHONY : CMakeFiles/hayPoint.dir/build

CMakeFiles/hayPoint.dir/requires: CMakeFiles/hayPoint.dir/hayPoint.cpp.o.requires
.PHONY : CMakeFiles/hayPoint.dir/requires

CMakeFiles/hayPoint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hayPoint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hayPoint.dir/clean

CMakeFiles/hayPoint.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/hayPoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hayPoint.dir/depend
