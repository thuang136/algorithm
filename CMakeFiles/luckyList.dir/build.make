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
include CMakeFiles/luckyList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/luckyList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/luckyList.dir/flags.make

CMakeFiles/luckyList.dir/luckyList.cpp.o: CMakeFiles/luckyList.dir/flags.make
CMakeFiles/luckyList.dir/luckyList.cpp.o: luckyList.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/luckyList.dir/luckyList.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/luckyList.dir/luckyList.cpp.o -c /Users/huangtao/Documents/opengl-test/luckyList.cpp

CMakeFiles/luckyList.dir/luckyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/luckyList.dir/luckyList.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/luckyList.cpp > CMakeFiles/luckyList.dir/luckyList.cpp.i

CMakeFiles/luckyList.dir/luckyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/luckyList.dir/luckyList.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/luckyList.cpp -o CMakeFiles/luckyList.dir/luckyList.cpp.s

CMakeFiles/luckyList.dir/luckyList.cpp.o.requires:
.PHONY : CMakeFiles/luckyList.dir/luckyList.cpp.o.requires

CMakeFiles/luckyList.dir/luckyList.cpp.o.provides: CMakeFiles/luckyList.dir/luckyList.cpp.o.requires
	$(MAKE) -f CMakeFiles/luckyList.dir/build.make CMakeFiles/luckyList.dir/luckyList.cpp.o.provides.build
.PHONY : CMakeFiles/luckyList.dir/luckyList.cpp.o.provides

CMakeFiles/luckyList.dir/luckyList.cpp.o.provides.build: CMakeFiles/luckyList.dir/luckyList.cpp.o

# Object files for target luckyList
luckyList_OBJECTS = \
"CMakeFiles/luckyList.dir/luckyList.cpp.o"

# External object files for target luckyList
luckyList_EXTERNAL_OBJECTS =

luckyList: CMakeFiles/luckyList.dir/luckyList.cpp.o
luckyList: CMakeFiles/luckyList.dir/build.make
luckyList: CMakeFiles/luckyList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable luckyList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/luckyList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/luckyList.dir/build: luckyList
.PHONY : CMakeFiles/luckyList.dir/build

CMakeFiles/luckyList.dir/requires: CMakeFiles/luckyList.dir/luckyList.cpp.o.requires
.PHONY : CMakeFiles/luckyList.dir/requires

CMakeFiles/luckyList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/luckyList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/luckyList.dir/clean

CMakeFiles/luckyList.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/luckyList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/luckyList.dir/depend

