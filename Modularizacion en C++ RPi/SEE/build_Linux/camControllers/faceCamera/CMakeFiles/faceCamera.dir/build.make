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
include camControllers/faceCamera/CMakeFiles/faceCamera.dir/depend.make

# Include the progress variables for this target.
include camControllers/faceCamera/CMakeFiles/faceCamera.dir/progress.make

# Include the compile flags for this target's objects.
include camControllers/faceCamera/CMakeFiles/faceCamera.dir/flags.make

camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o: camControllers/faceCamera/CMakeFiles/faceCamera.dir/flags.make
camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o: ../camControllers/faceCamera/src/mysemaphore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/killan/QtProjects/SEE/build_Linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o"
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/faceCamera && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o -c /home/killan/QtProjects/SEE/camControllers/faceCamera/src/mysemaphore.cpp

camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.i"
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/faceCamera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/killan/QtProjects/SEE/camControllers/faceCamera/src/mysemaphore.cpp > CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.i

camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.s"
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/faceCamera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/killan/QtProjects/SEE/camControllers/faceCamera/src/mysemaphore.cpp -o CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.s

camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o.requires:

.PHONY : camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o.requires

camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o.provides: camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o.requires
	$(MAKE) -f camControllers/faceCamera/CMakeFiles/faceCamera.dir/build.make camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o.provides.build
.PHONY : camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o.provides

camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o.provides.build: camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o


# Object files for target faceCamera
faceCamera_OBJECTS = \
"CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o"

# External object files for target faceCamera
faceCamera_EXTERNAL_OBJECTS =

libfaceCamera.so: camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o
libfaceCamera.so: camControllers/faceCamera/CMakeFiles/faceCamera.dir/build.make
libfaceCamera.so: camControllers/faceCamera/CMakeFiles/faceCamera.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/killan/QtProjects/SEE/build_Linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../libfaceCamera.so"
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/faceCamera && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/faceCamera.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
camControllers/faceCamera/CMakeFiles/faceCamera.dir/build: libfaceCamera.so

.PHONY : camControllers/faceCamera/CMakeFiles/faceCamera.dir/build

camControllers/faceCamera/CMakeFiles/faceCamera.dir/requires: camControllers/faceCamera/CMakeFiles/faceCamera.dir/src/mysemaphore.cpp.o.requires

.PHONY : camControllers/faceCamera/CMakeFiles/faceCamera.dir/requires

camControllers/faceCamera/CMakeFiles/faceCamera.dir/clean:
	cd /home/killan/QtProjects/SEE/build_Linux/camControllers/faceCamera && $(CMAKE_COMMAND) -P CMakeFiles/faceCamera.dir/cmake_clean.cmake
.PHONY : camControllers/faceCamera/CMakeFiles/faceCamera.dir/clean

camControllers/faceCamera/CMakeFiles/faceCamera.dir/depend:
	cd /home/killan/QtProjects/SEE/build_Linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/killan/QtProjects/SEE /home/killan/QtProjects/SEE/camControllers/faceCamera /home/killan/QtProjects/SEE/build_Linux /home/killan/QtProjects/SEE/build_Linux/camControllers/faceCamera /home/killan/QtProjects/SEE/build_Linux/camControllers/faceCamera/CMakeFiles/faceCamera.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : camControllers/faceCamera/CMakeFiles/faceCamera.dir/depend

