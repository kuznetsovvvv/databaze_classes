# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/misha/dev/first-databaze/databaze

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/misha/dev/first-databaze/databaze/build

# Include any dependencies generated for this target.
include CMakeFiles/dz2_2sem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dz2_2sem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dz2_2sem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dz2_2sem.dir/flags.make

CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o: CMakeFiles/dz2_2sem.dir/flags.make
CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o: ../dz2_2sem.cpp
CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o: CMakeFiles/dz2_2sem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/dev/first-databaze/databaze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o -MF CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o.d -o CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o -c /home/misha/dev/first-databaze/databaze/dz2_2sem.cpp

CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/misha/dev/first-databaze/databaze/dz2_2sem.cpp > CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.i

CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/misha/dev/first-databaze/databaze/dz2_2sem.cpp -o CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.s

# Object files for target dz2_2sem
dz2_2sem_OBJECTS = \
"CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o"

# External object files for target dz2_2sem
dz2_2sem_EXTERNAL_OBJECTS =

dz2_2sem: CMakeFiles/dz2_2sem.dir/dz2_2sem.cpp.o
dz2_2sem: CMakeFiles/dz2_2sem.dir/build.make
dz2_2sem: includes_dir/libincludes.a
dz2_2sem: CMakeFiles/dz2_2sem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/misha/dev/first-databaze/databaze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dz2_2sem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dz2_2sem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dz2_2sem.dir/build: dz2_2sem
.PHONY : CMakeFiles/dz2_2sem.dir/build

CMakeFiles/dz2_2sem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dz2_2sem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dz2_2sem.dir/clean

CMakeFiles/dz2_2sem.dir/depend:
	cd /home/misha/dev/first-databaze/databaze/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/misha/dev/first-databaze/databaze /home/misha/dev/first-databaze/databaze /home/misha/dev/first-databaze/databaze/build /home/misha/dev/first-databaze/databaze/build /home/misha/dev/first-databaze/databaze/build/CMakeFiles/dz2_2sem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dz2_2sem.dir/depend

