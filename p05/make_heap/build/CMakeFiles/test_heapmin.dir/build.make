# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/datos/informatica/ed/practicas/p5/make_heap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/datos/informatica/ed/practicas/p5/make_heap/build

# Include any dependencies generated for this target.
include CMakeFiles/test_heapmin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_heapmin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_heapmin.dir/flags.make

CMakeFiles/test_heapmin.dir/test_heapmin.cpp.o: CMakeFiles/test_heapmin.dir/flags.make
CMakeFiles/test_heapmin.dir/test_heapmin.cpp.o: ../test_heapmin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/datos/informatica/ed/practicas/p5/make_heap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_heapmin.dir/test_heapmin.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_heapmin.dir/test_heapmin.cpp.o -c /mnt/datos/informatica/ed/practicas/p5/make_heap/test_heapmin.cpp

CMakeFiles/test_heapmin.dir/test_heapmin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_heapmin.dir/test_heapmin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/datos/informatica/ed/practicas/p5/make_heap/test_heapmin.cpp > CMakeFiles/test_heapmin.dir/test_heapmin.cpp.i

CMakeFiles/test_heapmin.dir/test_heapmin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_heapmin.dir/test_heapmin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/datos/informatica/ed/practicas/p5/make_heap/test_heapmin.cpp -o CMakeFiles/test_heapmin.dir/test_heapmin.cpp.s

# Object files for target test_heapmin
test_heapmin_OBJECTS = \
"CMakeFiles/test_heapmin.dir/test_heapmin.cpp.o"

# External object files for target test_heapmin
test_heapmin_EXTERNAL_OBJECTS =

test_heapmin: CMakeFiles/test_heapmin.dir/test_heapmin.cpp.o
test_heapmin: CMakeFiles/test_heapmin.dir/build.make
test_heapmin: CMakeFiles/test_heapmin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/datos/informatica/ed/practicas/p5/make_heap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_heapmin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_heapmin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_heapmin.dir/build: test_heapmin

.PHONY : CMakeFiles/test_heapmin.dir/build

CMakeFiles/test_heapmin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_heapmin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_heapmin.dir/clean

CMakeFiles/test_heapmin.dir/depend:
	cd /mnt/datos/informatica/ed/practicas/p5/make_heap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/datos/informatica/ed/practicas/p5/make_heap /mnt/datos/informatica/ed/practicas/p5/make_heap /mnt/datos/informatica/ed/practicas/p5/make_heap/build /mnt/datos/informatica/ed/practicas/p5/make_heap/build /mnt/datos/informatica/ed/practicas/p5/make_heap/build/CMakeFiles/test_heapmin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_heapmin.dir/depend

