# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mstewart/EECE_2080/EECE_2080_Lab_04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mstewart/EECE_2080/EECE_2080_Lab_04

# Include any dependencies generated for this target.
include CMakeFiles/applibrary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/applibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/applibrary.dir/flags.make

CMakeFiles/applibrary.dir/Recursion.cpp.o: CMakeFiles/applibrary.dir/flags.make
CMakeFiles/applibrary.dir/Recursion.cpp.o: Recursion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mstewart/EECE_2080/EECE_2080_Lab_04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/applibrary.dir/Recursion.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/applibrary.dir/Recursion.cpp.o -c /home/mstewart/EECE_2080/EECE_2080_Lab_04/Recursion.cpp

CMakeFiles/applibrary.dir/Recursion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/applibrary.dir/Recursion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mstewart/EECE_2080/EECE_2080_Lab_04/Recursion.cpp > CMakeFiles/applibrary.dir/Recursion.cpp.i

CMakeFiles/applibrary.dir/Recursion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/applibrary.dir/Recursion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mstewart/EECE_2080/EECE_2080_Lab_04/Recursion.cpp -o CMakeFiles/applibrary.dir/Recursion.cpp.s

# Object files for target applibrary
applibrary_OBJECTS = \
"CMakeFiles/applibrary.dir/Recursion.cpp.o"

# External object files for target applibrary
applibrary_EXTERNAL_OBJECTS =

libapplibrary.a: CMakeFiles/applibrary.dir/Recursion.cpp.o
libapplibrary.a: CMakeFiles/applibrary.dir/build.make
libapplibrary.a: CMakeFiles/applibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mstewart/EECE_2080/EECE_2080_Lab_04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libapplibrary.a"
	$(CMAKE_COMMAND) -P CMakeFiles/applibrary.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/applibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/applibrary.dir/build: libapplibrary.a

.PHONY : CMakeFiles/applibrary.dir/build

CMakeFiles/applibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/applibrary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/applibrary.dir/clean

CMakeFiles/applibrary.dir/depend:
	cd /home/mstewart/EECE_2080/EECE_2080_Lab_04 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mstewart/EECE_2080/EECE_2080_Lab_04 /home/mstewart/EECE_2080/EECE_2080_Lab_04 /home/mstewart/EECE_2080/EECE_2080_Lab_04 /home/mstewart/EECE_2080/EECE_2080_Lab_04 /home/mstewart/EECE_2080/EECE_2080_Lab_04/CMakeFiles/applibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/applibrary.dir/depend

