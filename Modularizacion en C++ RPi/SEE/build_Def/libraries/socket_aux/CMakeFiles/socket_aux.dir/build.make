# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\build_Def"

# Include any dependencies generated for this target.
include libraries/socket_aux/CMakeFiles/socket_aux.dir/depend.make

# Include the progress variables for this target.
include libraries/socket_aux/CMakeFiles/socket_aux.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/socket_aux/CMakeFiles/socket_aux.dir/flags.make

libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj: libraries/socket_aux/CMakeFiles/socket_aux.dir/flags.make
libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj: libraries/socket_aux/CMakeFiles/socket_aux.dir/includes_CXX.rsp
libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj: ../libraries/socket_aux/src/mysocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\build_Def\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj"
	cd /d C:\Users\CRHIST~1\Dropbox\DOCTOR~1\SEMSES~1\SISTEM~1\Git\SISTEM~1\MODULA~1\SEE\BUILD_~2\LIBRAR~1\SOCKET~1 && C:\Qt\Qt5.8.0\Tools\mingw530_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\socket_aux.dir\src\mysocket.cpp.obj -c "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\libraries\socket_aux\src\mysocket.cpp"

libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket_aux.dir/src/mysocket.cpp.i"
	cd /d C:\Users\CRHIST~1\Dropbox\DOCTOR~1\SEMSES~1\SISTEM~1\Git\SISTEM~1\MODULA~1\SEE\BUILD_~2\LIBRAR~1\SOCKET~1 && C:\Qt\Qt5.8.0\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\libraries\socket_aux\src\mysocket.cpp" > CMakeFiles\socket_aux.dir\src\mysocket.cpp.i

libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket_aux.dir/src/mysocket.cpp.s"
	cd /d C:\Users\CRHIST~1\Dropbox\DOCTOR~1\SEMSES~1\SISTEM~1\Git\SISTEM~1\MODULA~1\SEE\BUILD_~2\LIBRAR~1\SOCKET~1 && C:\Qt\Qt5.8.0\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\libraries\socket_aux\src\mysocket.cpp" -o CMakeFiles\socket_aux.dir\src\mysocket.cpp.s

libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj.requires:

.PHONY : libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj.requires

libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj.provides: libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj.requires
	$(MAKE) -f libraries\socket_aux\CMakeFiles\socket_aux.dir\build.make libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj.provides.build
.PHONY : libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj.provides

libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj.provides.build: libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj


# Object files for target socket_aux
socket_aux_OBJECTS = \
"CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj"

# External object files for target socket_aux
socket_aux_EXTERNAL_OBJECTS =

../build_Windows/libsocket_aux.dll: libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj
../build_Windows/libsocket_aux.dll: libraries/socket_aux/CMakeFiles/socket_aux.dir/build.make
../build_Windows/libsocket_aux.dll: ../build_Windows/libthread_aux.dll.a
../build_Windows/libsocket_aux.dll: libraries/socket_aux/CMakeFiles/socket_aux.dir/linklibs.rsp
../build_Windows/libsocket_aux.dll: libraries/socket_aux/CMakeFiles/socket_aux.dir/objects1.rsp
../build_Windows/libsocket_aux.dll: libraries/socket_aux/CMakeFiles/socket_aux.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\build_Def\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ..\..\..\build_Windows\libsocket_aux.dll"
	cd /d C:\Users\CRHIST~1\Dropbox\DOCTOR~1\SEMSES~1\SISTEM~1\Git\SISTEM~1\MODULA~1\SEE\BUILD_~2\LIBRAR~1\SOCKET~1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\socket_aux.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/socket_aux/CMakeFiles/socket_aux.dir/build: ../build_Windows/libsocket_aux.dll

.PHONY : libraries/socket_aux/CMakeFiles/socket_aux.dir/build

libraries/socket_aux/CMakeFiles/socket_aux.dir/requires: libraries/socket_aux/CMakeFiles/socket_aux.dir/src/mysocket.cpp.obj.requires

.PHONY : libraries/socket_aux/CMakeFiles/socket_aux.dir/requires

libraries/socket_aux/CMakeFiles/socket_aux.dir/clean:
	cd /d C:\Users\CRHIST~1\Dropbox\DOCTOR~1\SEMSES~1\SISTEM~1\Git\SISTEM~1\MODULA~1\SEE\BUILD_~2\LIBRAR~1\SOCKET~1 && $(CMAKE_COMMAND) -P CMakeFiles\socket_aux.dir\cmake_clean.cmake
.PHONY : libraries/socket_aux/CMakeFiles/socket_aux.dir/clean

libraries/socket_aux/CMakeFiles/socket_aux.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE" "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\libraries\socket_aux" "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\build_Def" "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\build_Def\libraries\socket_aux" "C:\Users\crhistian\Dropbox\Doctorado Andes\Semsestre 2017-I\Sistemas Embebidos\Git\SistemasEmbebidos_17_1\Modularizacion en C++ RPi\SEE\build_Def\libraries\socket_aux\CMakeFiles\socket_aux.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : libraries/socket_aux/CMakeFiles/socket_aux.dir/depend
