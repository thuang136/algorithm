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
include CMakeFiles/StrTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StrTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StrTest.dir/flags.make

CMakeFiles/StrTest.dir/StrTest.cpp.o: CMakeFiles/StrTest.dir/flags.make
CMakeFiles/StrTest.dir/StrTest.cpp.o: StrTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/StrTest.dir/StrTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/StrTest.dir/StrTest.cpp.o -c /Users/huangtao/Documents/opengl-test/StrTest.cpp

CMakeFiles/StrTest.dir/StrTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StrTest.dir/StrTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/StrTest.cpp > CMakeFiles/StrTest.dir/StrTest.cpp.i

CMakeFiles/StrTest.dir/StrTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StrTest.dir/StrTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/StrTest.cpp -o CMakeFiles/StrTest.dir/StrTest.cpp.s

CMakeFiles/StrTest.dir/StrTest.cpp.o.requires:
.PHONY : CMakeFiles/StrTest.dir/StrTest.cpp.o.requires

CMakeFiles/StrTest.dir/StrTest.cpp.o.provides: CMakeFiles/StrTest.dir/StrTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/StrTest.dir/build.make CMakeFiles/StrTest.dir/StrTest.cpp.o.provides.build
.PHONY : CMakeFiles/StrTest.dir/StrTest.cpp.o.provides

CMakeFiles/StrTest.dir/StrTest.cpp.o.provides.build: CMakeFiles/StrTest.dir/StrTest.cpp.o

# Object files for target StrTest
StrTest_OBJECTS = \
"CMakeFiles/StrTest.dir/StrTest.cpp.o"

# External object files for target StrTest
StrTest_EXTERNAL_OBJECTS =

StrTest: CMakeFiles/StrTest.dir/StrTest.cpp.o
StrTest: CMakeFiles/StrTest.dir/build.make
StrTest: CMakeFiles/StrTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable StrTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StrTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StrTest.dir/build: StrTest
.PHONY : CMakeFiles/StrTest.dir/build

CMakeFiles/StrTest.dir/requires: CMakeFiles/StrTest.dir/StrTest.cpp.o.requires
.PHONY : CMakeFiles/StrTest.dir/requires

CMakeFiles/StrTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StrTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StrTest.dir/clean

CMakeFiles/StrTest.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/StrTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StrTest.dir/depend

