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
include CMakeFiles/textureShader.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/textureShader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/textureShader.dir/flags.make

CMakeFiles/textureShader.dir/textureShader.cpp.o: CMakeFiles/textureShader.dir/flags.make
CMakeFiles/textureShader.dir/textureShader.cpp.o: textureShader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/huangtao/Documents/opengl-test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/textureShader.dir/textureShader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/textureShader.dir/textureShader.cpp.o -c /Users/huangtao/Documents/opengl-test/textureShader.cpp

CMakeFiles/textureShader.dir/textureShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textureShader.dir/textureShader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/huangtao/Documents/opengl-test/textureShader.cpp > CMakeFiles/textureShader.dir/textureShader.cpp.i

CMakeFiles/textureShader.dir/textureShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textureShader.dir/textureShader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/huangtao/Documents/opengl-test/textureShader.cpp -o CMakeFiles/textureShader.dir/textureShader.cpp.s

CMakeFiles/textureShader.dir/textureShader.cpp.o.requires:
.PHONY : CMakeFiles/textureShader.dir/textureShader.cpp.o.requires

CMakeFiles/textureShader.dir/textureShader.cpp.o.provides: CMakeFiles/textureShader.dir/textureShader.cpp.o.requires
	$(MAKE) -f CMakeFiles/textureShader.dir/build.make CMakeFiles/textureShader.dir/textureShader.cpp.o.provides.build
.PHONY : CMakeFiles/textureShader.dir/textureShader.cpp.o.provides

CMakeFiles/textureShader.dir/textureShader.cpp.o.provides.build: CMakeFiles/textureShader.dir/textureShader.cpp.o

# Object files for target textureShader
textureShader_OBJECTS = \
"CMakeFiles/textureShader.dir/textureShader.cpp.o"

# External object files for target textureShader
textureShader_EXTERNAL_OBJECTS =

textureShader: CMakeFiles/textureShader.dir/textureShader.cpp.o
textureShader: CMakeFiles/textureShader.dir/build.make
textureShader: CMakeFiles/textureShader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable textureShader"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/textureShader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/textureShader.dir/build: textureShader
.PHONY : CMakeFiles/textureShader.dir/build

CMakeFiles/textureShader.dir/requires: CMakeFiles/textureShader.dir/textureShader.cpp.o.requires
.PHONY : CMakeFiles/textureShader.dir/requires

CMakeFiles/textureShader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/textureShader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/textureShader.dir/clean

CMakeFiles/textureShader.dir/depend:
	cd /Users/huangtao/Documents/opengl-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test /Users/huangtao/Documents/opengl-test/CMakeFiles/textureShader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/textureShader.dir/depend

