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
include CMakeFiles/callPlugin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/callPlugin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/callPlugin.dir/flags.make

CMakeFiles/callPlugin.dir/callPlugin.cpp.o: CMakeFiles/callPlugin.dir/flags.make
CMakeFiles/callPlugin.dir/callPlugin.cpp.o: callPlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/callPlugin.dir/callPlugin.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/callPlugin.dir/callPlugin.cpp.o -c /Users/huangtao/Documents/opengl-test/callPlugin.cpp

CMakeFiles/callPlugin.dir/callPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/callPlugin.dir/callPlugin.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/callPlugin.cpp > CMakeFiles/callPlugin.dir/callPlugin.cpp.i

CMakeFiles/callPlugin.dir/callPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/callPlugin.dir/callPlugin.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/callPlugin.cpp -o CMakeFiles/callPlugin.dir/callPlugin.cpp.s

CMakeFiles/callPlugin.dir/callPlugin.cpp.o.requires:
.PHONY : CMakeFiles/callPlugin.dir/callPlugin.cpp.o.requires

CMakeFiles/callPlugin.dir/callPlugin.cpp.o.provides: CMakeFiles/callPlugin.dir/callPlugin.cpp.o.requires
	$(MAKE) -f CMakeFiles/callPlugin.dir/build.make CMakeFiles/callPlugin.dir/callPlugin.cpp.o.provides.build
.PHONY : CMakeFiles/callPlugin.dir/callPlugin.cpp.o.provides

CMakeFiles/callPlugin.dir/callPlugin.cpp.o.provides.build: CMakeFiles/callPlugin.dir/callPlugin.cpp.o

# Object files for target callPlugin
callPlugin_OBJECTS = \
"CMakeFiles/callPlugin.dir/callPlugin.cpp.o"

# External object files for target callPlugin
callPlugin_EXTERNAL_OBJECTS =

callPlugin: CMakeFiles/callPlugin.dir/callPlugin.cpp.o
callPlugin: CMakeFiles/callPlugin.dir/build.make
callPlugin: liblibstudent.dylib
callPlugin: CMakeFiles/callPlugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable callPlugin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/callPlugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/callPlugin.dir/build: callPlugin
.PHONY : CMakeFiles/callPlugin.dir/build

CMakeFiles/callPlugin.dir/requires: CMakeFiles/callPlugin.dir/callPlugin.cpp.o.requires
.PHONY : CMakeFiles/callPlugin.dir/requires

CMakeFiles/callPlugin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/callPlugin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/callPlugin.dir/clean

CMakeFiles/callPlugin.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/callPlugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/callPlugin.dir/depend

