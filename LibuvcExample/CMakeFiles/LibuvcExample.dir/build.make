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
CMAKE_SOURCE_DIR = /home/alastair/Development/LibuvcExample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alastair/Development/LibuvcExample

# Include any dependencies generated for this target.
include CMakeFiles/LibuvcExample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LibuvcExample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LibuvcExample.dir/flags.make

CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o: CMakeFiles/LibuvcExample.dir/flags.make
CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o: LibuvcExample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastair/Development/LibuvcExample/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o -c /home/alastair/Development/LibuvcExample/LibuvcExample.cpp

CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alastair/Development/LibuvcExample/LibuvcExample.cpp > CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.i

CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alastair/Development/LibuvcExample/LibuvcExample.cpp -o CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.s

CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o.requires:

.PHONY : CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o.requires

CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o.provides: CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o.requires
	$(MAKE) -f CMakeFiles/LibuvcExample.dir/build.make CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o.provides.build
.PHONY : CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o.provides

CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o.provides.build: CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o


# Object files for target LibuvcExample
LibuvcExample_OBJECTS = \
"CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o"

# External object files for target LibuvcExample
LibuvcExample_EXTERNAL_OBJECTS =

LibuvcExample: CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o
LibuvcExample: CMakeFiles/LibuvcExample.dir/build.make
LibuvcExample: /usr/local/lib/libopencv_shape.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_stitching.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_superres.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_videostab.so.3.2.0
LibuvcExample: /usr/local/lib/x86_64-linux-gnu/libuvc.so
LibuvcExample: /usr/local/lib/libopencv_objdetect.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_calib3d.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_features2d.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_flann.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_highgui.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_ml.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_photo.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_video.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_videoio.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_imgproc.so.3.2.0
LibuvcExample: /usr/local/lib/libopencv_core.so.3.2.0
LibuvcExample: CMakeFiles/LibuvcExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alastair/Development/LibuvcExample/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LibuvcExample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LibuvcExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LibuvcExample.dir/build: LibuvcExample

.PHONY : CMakeFiles/LibuvcExample.dir/build

CMakeFiles/LibuvcExample.dir/requires: CMakeFiles/LibuvcExample.dir/LibuvcExample.cpp.o.requires

.PHONY : CMakeFiles/LibuvcExample.dir/requires

CMakeFiles/LibuvcExample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LibuvcExample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LibuvcExample.dir/clean

CMakeFiles/LibuvcExample.dir/depend:
	cd /home/alastair/Development/LibuvcExample && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alastair/Development/LibuvcExample /home/alastair/Development/LibuvcExample /home/alastair/Development/LibuvcExample /home/alastair/Development/LibuvcExample /home/alastair/Development/LibuvcExample/CMakeFiles/LibuvcExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LibuvcExample.dir/depend

