# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "D:\clion\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\clion\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\c++\homework10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\c++\homework10\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/homework10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/homework10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework10.dir/flags.make

CMakeFiles/homework10.dir/main.cpp.obj: CMakeFiles/homework10.dir/flags.make
CMakeFiles/homework10.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\c++\homework10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homework10.dir/main.cpp.obj"
	D:\qt\Tools\mingw730_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\homework10.dir\main.cpp.obj -c E:\c++\homework10\main.cpp

CMakeFiles/homework10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework10.dir/main.cpp.i"
	D:\qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c++\homework10\main.cpp > CMakeFiles\homework10.dir\main.cpp.i

CMakeFiles/homework10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework10.dir/main.cpp.s"
	D:\qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c++\homework10\main.cpp -o CMakeFiles\homework10.dir\main.cpp.s

# Object files for target homework10
homework10_OBJECTS = \
"CMakeFiles/homework10.dir/main.cpp.obj"

# External object files for target homework10
homework10_EXTERNAL_OBJECTS =

homework10.exe: CMakeFiles/homework10.dir/main.cpp.obj
homework10.exe: CMakeFiles/homework10.dir/build.make
homework10.exe: CMakeFiles/homework10.dir/linklibs.rsp
homework10.exe: CMakeFiles/homework10.dir/objects1.rsp
homework10.exe: CMakeFiles/homework10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\c++\homework10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable homework10.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\homework10.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homework10.dir/build: homework10.exe

.PHONY : CMakeFiles/homework10.dir/build

CMakeFiles/homework10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\homework10.dir\cmake_clean.cmake
.PHONY : CMakeFiles/homework10.dir/clean

CMakeFiles/homework10.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\c++\homework10 E:\c++\homework10 E:\c++\homework10\cmake-build-debug E:\c++\homework10\cmake-build-debug E:\c++\homework10\cmake-build-debug\CMakeFiles\homework10.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework10.dir/depend

