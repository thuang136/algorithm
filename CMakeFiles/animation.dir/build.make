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
include CMakeFiles/animation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/animation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/animation.dir/flags.make

CMakeFiles/animation.dir/animation.cpp.o: CMakeFiles/animation.dir/flags.make
CMakeFiles/animation.dir/animation.cpp.o: animation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/animation.dir/animation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/animation.dir/animation.cpp.o -c /Users/huangtao/Documents/opengl-test/animation.cpp

CMakeFiles/animation.dir/animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/animation.dir/animation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/animation.cpp > CMakeFiles/animation.dir/animation.cpp.i

CMakeFiles/animation.dir/animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/animation.dir/animation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/animation.cpp -o CMakeFiles/animation.dir/animation.cpp.s

CMakeFiles/animation.dir/animation.cpp.o.requires:
.PHONY : CMakeFiles/animation.dir/animation.cpp.o.requires

CMakeFiles/animation.dir/animation.cpp.o.provides: CMakeFiles/animation.dir/animation.cpp.o.requires
	$(MAKE) -f CMakeFiles/animation.dir/build.make CMakeFiles/animation.dir/animation.cpp.o.provides.build
.PHONY : CMakeFiles/animation.dir/animation.cpp.o.provides

CMakeFiles/animation.dir/animation.cpp.o.provides.build: CMakeFiles/animation.dir/animation.cpp.o

# Object files for target animation
animation_OBJECTS = \
"CMakeFiles/animation.dir/animation.cpp.o"

# External object files for target animation
animation_EXTERNAL_OBJECTS =

animation: CMakeFiles/animation.dir/animation.cpp.o
animation: CMakeFiles/animation.dir/build.make
animation: CMakeFiles/animation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable animation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/animation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/animation.dir/build: animation
.PHONY : CMakeFiles/animation.dir/build

CMakeFiles/animation.dir/requires: CMakeFiles/animation.dir/animation.cpp.o.requires
.PHONY : CMakeFiles/animation.dir/requires

CMakeFiles/animation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/animation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/animation.dir/clean

CMakeFiles/animation.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/animation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/animation.dir/depend
