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
include CMakeFiles/reverseList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reverseList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reverseList.dir/flags.make

CMakeFiles/reverseList.dir/reverseList.cpp.o: CMakeFiles/reverseList.dir/flags.make
CMakeFiles/reverseList.dir/reverseList.cpp.o: reverseList.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/reverseList.dir/reverseList.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/reverseList.dir/reverseList.cpp.o -c /Users/huangtao/Documents/opengl-test/reverseList.cpp

CMakeFiles/reverseList.dir/reverseList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reverseList.dir/reverseList.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/reverseList.cpp > CMakeFiles/reverseList.dir/reverseList.cpp.i

CMakeFiles/reverseList.dir/reverseList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reverseList.dir/reverseList.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/reverseList.cpp -o CMakeFiles/reverseList.dir/reverseList.cpp.s

CMakeFiles/reverseList.dir/reverseList.cpp.o.requires:
.PHONY : CMakeFiles/reverseList.dir/reverseList.cpp.o.requires

CMakeFiles/reverseList.dir/reverseList.cpp.o.provides: CMakeFiles/reverseList.dir/reverseList.cpp.o.requires
	$(MAKE) -f CMakeFiles/reverseList.dir/build.make CMakeFiles/reverseList.dir/reverseList.cpp.o.provides.build
.PHONY : CMakeFiles/reverseList.dir/reverseList.cpp.o.provides

CMakeFiles/reverseList.dir/reverseList.cpp.o.provides.build: CMakeFiles/reverseList.dir/reverseList.cpp.o

# Object files for target reverseList
reverseList_OBJECTS = \
"CMakeFiles/reverseList.dir/reverseList.cpp.o"

# External object files for target reverseList
reverseList_EXTERNAL_OBJECTS =

reverseList: CMakeFiles/reverseList.dir/reverseList.cpp.o
reverseList: CMakeFiles/reverseList.dir/build.make
reverseList: CMakeFiles/reverseList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable reverseList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reverseList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reverseList.dir/build: reverseList
.PHONY : CMakeFiles/reverseList.dir/build

CMakeFiles/reverseList.dir/requires: CMakeFiles/reverseList.dir/reverseList.cpp.o.requires
.PHONY : CMakeFiles/reverseList.dir/requires

CMakeFiles/reverseList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reverseList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reverseList.dir/clean

CMakeFiles/reverseList.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/reverseList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reverseList.dir/depend

