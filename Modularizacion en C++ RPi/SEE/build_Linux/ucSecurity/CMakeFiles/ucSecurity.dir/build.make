# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/killan/QtProjects/SEE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/killan/QtProjects/SEE/build_Linux

# Include any dependencies generated for this target.
include ucSecurity/CMakeFiles/ucSecurity.dir/depend.make

# Include the progress variables for this target.
include ucSecurity/CMakeFiles/ucSecurity.dir/progress.make

# Include the compile flags for this target's objects.
include ucSecurity/CMakeFiles/ucSecurity.dir/flags.make

ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o: ucSecurity/CMakeFiles/ucSecurity.dir/flags.make
ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o: ../ucSecurity/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/killan/QtProjects/SEE/build_Linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o"
	cd /home/killan/QtProjects/SEE/build_Linux/ucSecurity && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ucSecurity.dir/src/main.cpp.o -c /home/killan/QtProjects/SEE/ucSecurity/src/main.cpp

ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ucSecurity.dir/src/main.cpp.i"
	cd /home/killan/QtProjects/SEE/build_Linux/ucSecurity && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/killan/QtProjects/SEE/ucSecurity/src/main.cpp > CMakeFiles/ucSecurity.dir/src/main.cpp.i

ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ucSecurity.dir/src/main.cpp.s"
	cd /home/killan/QtProjects/SEE/build_Linux/ucSecurity && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/killan/QtProjects/SEE/ucSecurity/src/main.cpp -o CMakeFiles/ucSecurity.dir/src/main.cpp.s

ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o.requires:

.PHONY : ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o.requires

ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o.provides: ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o.requires
	$(MAKE) -f ucSecurity/CMakeFiles/ucSecurity.dir/build.make ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o.provides.build
.PHONY : ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o.provides

ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o.provides.build: ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o


# Object files for target ucSecurity
ucSecurity_OBJECTS = \
"CMakeFiles/ucSecurity.dir/src/main.cpp.o"

# External object files for target ucSecurity
ucSecurity_EXTERNAL_OBJECTS =

Deploy/ucSecurity: ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o
Deploy/ucSecurity: ucSecurity/CMakeFiles/ucSecurity.dir/build.make
Deploy/ucSecurity: ucSecurity/CMakeFiles/ucSecurity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/killan/QtProjects/SEE/build_Linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../Deploy/ucSecurity"
	cd /home/killan/QtProjects/SEE/build_Linux/ucSecurity && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ucSecurity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ucSecurity/CMakeFiles/ucSecurity.dir/build: Deploy/ucSecurity

.PHONY : ucSecurity/CMakeFiles/ucSecurity.dir/build

ucSecurity/CMakeFiles/ucSecurity.dir/requires: ucSecurity/CMakeFiles/ucSecurity.dir/src/main.cpp.o.requires

.PHONY : ucSecurity/CMakeFiles/ucSecurity.dir/requires

ucSecurity/CMakeFiles/ucSecurity.dir/clean:
	cd /home/killan/QtProjects/SEE/build_Linux/ucSecurity && $(CMAKE_COMMAND) -P CMakeFiles/ucSecurity.dir/cmake_clean.cmake
.PHONY : ucSecurity/CMakeFiles/ucSecurity.dir/clean

ucSecurity/CMakeFiles/ucSecurity.dir/depend:
	cd /home/killan/QtProjects/SEE/build_Linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/killan/QtProjects/SEE /home/killan/QtProjects/SEE/ucSecurity /home/killan/QtProjects/SEE/build_Linux /home/killan/QtProjects/SEE/build_Linux/ucSecurity /home/killan/QtProjects/SEE/build_Linux/ucSecurity/CMakeFiles/ucSecurity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ucSecurity/CMakeFiles/ucSecurity.dir/depend

