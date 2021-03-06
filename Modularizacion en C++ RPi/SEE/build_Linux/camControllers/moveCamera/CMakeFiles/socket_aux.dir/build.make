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
include camControllers/moveCamera/CMakeFiles/socket_aux.dir/depend.make

# Include the progress variables for this target.
include camControllers/moveCamera/CMakeFiles/socket_aux.dir/progress.make

# Include the compile flags for this target's objects.
include camControllers/moveCamera/CMakeFiles/socket_aux.dir/flags.make

camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o: camControllers/moveCamera/CMakeFiles/socket_aux.dir/flags.make
camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o: ../camControllers/moveCamera/src/mysocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/killan/QtProjects/SEE/build_Linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o"
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/moveCamera && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket_aux.dir/src/mysocket.cpp.o -c /home/killan/QtProjects/SEE/camControllers/moveCamera/src/mysocket.cpp

camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket_aux.dir/src/mysocket.cpp.i"
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/moveCamera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/killan/QtProjects/SEE/camControllers/moveCamera/src/mysocket.cpp > CMakeFiles/socket_aux.dir/src/mysocket.cpp.i

camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket_aux.dir/src/mysocket.cpp.s"
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/moveCamera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/killan/QtProjects/SEE/camControllers/moveCamera/src/mysocket.cpp -o CMakeFiles/socket_aux.dir/src/mysocket.cpp.s

camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o.requires:

.PHONY : camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o.requires

camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o.provides: camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o.requires
	$(MAKE) -f camControllers/moveCamera/CMakeFiles/socket_aux.dir/build.make camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o.provides.build
.PHONY : camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o.provides

camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o.provides.build: camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o


# Object files for target socket_aux
socket_aux_OBJECTS = \
"CMakeFiles/socket_aux.dir/src/mysocket.cpp.o"

# External object files for target socket_aux
socket_aux_EXTERNAL_OBJECTS =

libsocket_aux.so: camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o
libsocket_aux.so: camControllers/moveCamera/CMakeFiles/socket_aux.dir/build.make
libsocket_aux.so: camControllers/moveCamera/CMakeFiles/socket_aux.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/killan/QtProjects/SEE/build_Linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../libsocket_aux.so"
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/moveCamera && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/socket_aux.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
camControllers/moveCamera/CMakeFiles/socket_aux.dir/build: libsocket_aux.so

.PHONY : camControllers/moveCamera/CMakeFiles/socket_aux.dir/build

camControllers/moveCamera/CMakeFiles/socket_aux.dir/requires: camControllers/moveCamera/CMakeFiles/socket_aux.dir/src/mysocket.cpp.o.requires

.PHONY : camControllers/moveCamera/CMakeFiles/socket_aux.dir/requires

camControllers/moveCamera/CMakeFiles/socket_aux.dir/clean:
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/moveCamera && $(CMAKE_COMMAND) -P CMakeFiles/socket_aux.dir/cmake_clean.cmake
.PHONY : camControllers/moveCamera/CMakeFiles/socket_aux.dir/clean

camControllers/moveCamera/CMakeFiles/socket_aux.dir/depend:
	cd /home/killan/QtProjects/SEE/build_Linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/killan/QtProjects/SEE /home/killan/QtProjects/SEE/camControllers/moveCamera /home/killan/QtProjects/SEE/build_Linux /home/killan/QtProjects/SEE/build_Linux/camControllers/moveCamera /home/killan/QtProjects/SEE/build_Linux/camControllers/moveCamera/CMakeFiles/socket_aux.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : camControllers/moveCamera/CMakeFiles/socket_aux.dir/depend

