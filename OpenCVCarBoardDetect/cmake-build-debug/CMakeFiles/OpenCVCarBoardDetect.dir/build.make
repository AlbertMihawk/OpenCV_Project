# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenCVCarBoardDetect.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenCVCarBoardDetect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenCVCarBoardDetect.dir/flags.make

CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.o: CMakeFiles/OpenCVCarBoardDetect.dir/flags.make
CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.o -c /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/main.cpp

CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/main.cpp > CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.i

CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/main.cpp -o CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.s

# Object files for target OpenCVCarBoardDetect
OpenCVCarBoardDetect_OBJECTS = \
"CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.o"

# External object files for target OpenCVCarBoardDetect
OpenCVCarBoardDetect_EXTERNAL_OBJECTS =

OpenCVCarBoardDetect: CMakeFiles/OpenCVCarBoardDetect.dir/main.cpp.o
OpenCVCarBoardDetect: CMakeFiles/OpenCVCarBoardDetect.dir/build.make
OpenCVCarBoardDetect: CMakeFiles/OpenCVCarBoardDetect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OpenCVCarBoardDetect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenCVCarBoardDetect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenCVCarBoardDetect.dir/build: OpenCVCarBoardDetect

.PHONY : CMakeFiles/OpenCVCarBoardDetect.dir/build

CMakeFiles/OpenCVCarBoardDetect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenCVCarBoardDetect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenCVCarBoardDetect.dir/clean

CMakeFiles/OpenCVCarBoardDetect.dir/depend:
	cd /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/cmake-build-debug /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/cmake-build-debug /Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/cmake-build-debug/CMakeFiles/OpenCVCarBoardDetect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenCVCarBoardDetect.dir/depend

