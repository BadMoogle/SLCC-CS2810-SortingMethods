# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dharper/projects/SortingMethods

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dharper/projects/SortingMethods/build

# Include any dependencies generated for this target.
include CMakeFiles/sortingmethods.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sortingmethods.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sortingmethods.dir/flags.make

CMakeFiles/sortingmethods.dir/main.cpp.o: CMakeFiles/sortingmethods.dir/flags.make
CMakeFiles/sortingmethods.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dharper/projects/SortingMethods/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sortingmethods.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sortingmethods.dir/main.cpp.o -c /home/dharper/projects/SortingMethods/main.cpp

CMakeFiles/sortingmethods.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sortingmethods.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dharper/projects/SortingMethods/main.cpp > CMakeFiles/sortingmethods.dir/main.cpp.i

CMakeFiles/sortingmethods.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sortingmethods.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dharper/projects/SortingMethods/main.cpp -o CMakeFiles/sortingmethods.dir/main.cpp.s

CMakeFiles/sortingmethods.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/sortingmethods.dir/main.cpp.o.requires

CMakeFiles/sortingmethods.dir/main.cpp.o.provides: CMakeFiles/sortingmethods.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sortingmethods.dir/build.make CMakeFiles/sortingmethods.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/sortingmethods.dir/main.cpp.o.provides

CMakeFiles/sortingmethods.dir/main.cpp.o.provides.build: CMakeFiles/sortingmethods.dir/main.cpp.o

# Object files for target sortingmethods
sortingmethods_OBJECTS = \
"CMakeFiles/sortingmethods.dir/main.cpp.o"

# External object files for target sortingmethods
sortingmethods_EXTERNAL_OBJECTS =

sortingmethods: CMakeFiles/sortingmethods.dir/main.cpp.o
sortingmethods: CMakeFiles/sortingmethods.dir/build.make
sortingmethods: CMakeFiles/sortingmethods.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sortingmethods"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sortingmethods.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sortingmethods.dir/build: sortingmethods
.PHONY : CMakeFiles/sortingmethods.dir/build

CMakeFiles/sortingmethods.dir/requires: CMakeFiles/sortingmethods.dir/main.cpp.o.requires
.PHONY : CMakeFiles/sortingmethods.dir/requires

CMakeFiles/sortingmethods.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sortingmethods.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sortingmethods.dir/clean

CMakeFiles/sortingmethods.dir/depend:
	cd /home/dharper/projects/SortingMethods/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dharper/projects/SortingMethods /home/dharper/projects/SortingMethods /home/dharper/projects/SortingMethods/build /home/dharper/projects/SortingMethods/build /home/dharper/projects/SortingMethods/build/CMakeFiles/sortingmethods.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sortingmethods.dir/depend

