# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /opt/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fahr/git/walknet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fahr/git/walknet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/walknet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/walknet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/walknet.dir/flags.make

CMakeFiles/walknet.dir/main.cpp.o: CMakeFiles/walknet.dir/flags.make
CMakeFiles/walknet.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fahr/git/walknet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/walknet.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/walknet.dir/main.cpp.o -c /home/fahr/git/walknet/main.cpp

CMakeFiles/walknet.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/walknet.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fahr/git/walknet/main.cpp > CMakeFiles/walknet.dir/main.cpp.i

CMakeFiles/walknet.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/walknet.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fahr/git/walknet/main.cpp -o CMakeFiles/walknet.dir/main.cpp.s

# Object files for target walknet
walknet_OBJECTS = \
"CMakeFiles/walknet.dir/main.cpp.o"

# External object files for target walknet
walknet_EXTERNAL_OBJECTS =

walknet: CMakeFiles/walknet.dir/main.cpp.o
walknet: CMakeFiles/walknet.dir/build.make
walknet: /usr/lib/x86_64-linux-gnu/libsfml-system.so
walknet: /usr/lib/x86_64-linux-gnu/libsfml-window.so
walknet: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
walknet: /usr/lib/x86_64-linux-gnu/libsfml-network.so
walknet: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
walknet: CMakeFiles/walknet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fahr/git/walknet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable walknet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/walknet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/walknet.dir/build: walknet

.PHONY : CMakeFiles/walknet.dir/build

CMakeFiles/walknet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/walknet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/walknet.dir/clean

CMakeFiles/walknet.dir/depend:
	cd /home/fahr/git/walknet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fahr/git/walknet /home/fahr/git/walknet /home/fahr/git/walknet/cmake-build-debug /home/fahr/git/walknet/cmake-build-debug /home/fahr/git/walknet/cmake-build-debug/CMakeFiles/walknet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/walknet.dir/depend

