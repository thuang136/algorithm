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
include CMakeFiles/command.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/command.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/command.dir/flags.make

CMakeFiles/command.dir/command.cpp.o: CMakeFiles/command.dir/flags.make
CMakeFiles/command.dir/command.cpp.o: command.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/command.dir/command.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/command.dir/command.cpp.o -c /Users/huangtao/Documents/opengl-test/command.cpp

CMakeFiles/command.dir/command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/command.dir/command.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/command.cpp > CMakeFiles/command.dir/command.cpp.i

CMakeFiles/command.dir/command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/command.dir/command.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/command.cpp -o CMakeFiles/command.dir/command.cpp.s

CMakeFiles/command.dir/command.cpp.o.requires:
.PHONY : CMakeFiles/command.dir/command.cpp.o.requires

CMakeFiles/command.dir/command.cpp.o.provides: CMakeFiles/command.dir/command.cpp.o.requires
	$(MAKE) -f CMakeFiles/command.dir/build.make CMakeFiles/command.dir/command.cpp.o.provides.build
.PHONY : CMakeFiles/command.dir/command.cpp.o.provides

CMakeFiles/command.dir/command.cpp.o.provides.build: CMakeFiles/command.dir/command.cpp.o

# Object files for target command
command_OBJECTS = \
"CMakeFiles/command.dir/command.cpp.o"

# External object files for target command
command_EXTERNAL_OBJECTS =

command: CMakeFiles/command.dir/command.cpp.o
command: CMakeFiles/command.dir/build.make
command: CMakeFiles/command.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable command"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/command.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/command.dir/build: command
.PHONY : CMakeFiles/command.dir/build

CMakeFiles/command.dir/requires: CMakeFiles/command.dir/command.cpp.o.requires
.PHONY : CMakeFiles/command.dir/requires

CMakeFiles/command.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/command.dir/cmake_clean.cmake
.PHONY : CMakeFiles/command.dir/clean

CMakeFiles/command.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/command.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/command.dir/depend
