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
CMAKE_SOURCE_DIR = /home/alastair/Development/GetBoson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alastair/Development/GetBoson

# Include any dependencies generated for this target.
include CMakeFiles/GetBoson.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GetBoson.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GetBoson.dir/flags.make

CMakeFiles/GetBoson.dir/getboson.cpp.o: CMakeFiles/GetBoson.dir/flags.make
CMakeFiles/GetBoson.dir/getboson.cpp.o: getboson.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastair/Development/GetBoson/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GetBoson.dir/getboson.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GetBoson.dir/getboson.cpp.o -c /home/alastair/Development/GetBoson/getboson.cpp

CMakeFiles/GetBoson.dir/getboson.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GetBoson.dir/getboson.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alastair/Development/GetBoson/getboson.cpp > CMakeFiles/GetBoson.dir/getboson.cpp.i

CMakeFiles/GetBoson.dir/getboson.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GetBoson.dir/getboson.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alastair/Development/GetBoson/getboson.cpp -o CMakeFiles/GetBoson.dir/getboson.cpp.s

CMakeFiles/GetBoson.dir/getboson.cpp.o.requires:

.PHONY : CMakeFiles/GetBoson.dir/getboson.cpp.o.requires

CMakeFiles/GetBoson.dir/getboson.cpp.o.provides: CMakeFiles/GetBoson.dir/getboson.cpp.o.requires
	$(MAKE) -f CMakeFiles/GetBoson.dir/build.make CMakeFiles/GetBoson.dir/getboson.cpp.o.provides.build
.PHONY : CMakeFiles/GetBoson.dir/getboson.cpp.o.provides

CMakeFiles/GetBoson.dir/getboson.cpp.o.provides.build: CMakeFiles/GetBoson.dir/getboson.cpp.o


# Object files for target GetBoson
GetBoson_OBJECTS = \
"CMakeFiles/GetBoson.dir/getboson.cpp.o"

# External object files for target GetBoson
GetBoson_EXTERNAL_OBJECTS =

GetBoson: CMakeFiles/GetBoson.dir/getboson.cpp.o
GetBoson: CMakeFiles/GetBoson.dir/build.make
GetBoson: /usr/local/lib/libopencv_shape.so.3.2.0
GetBoson: /usr/local/lib/libopencv_stitching.so.3.2.0
GetBoson: /usr/local/lib/libopencv_superres.so.3.2.0
GetBoson: /usr/local/lib/libopencv_videostab.so.3.2.0
GetBoson: /usr/local/lib/libuvc.so
GetBoson: /usr/local/lib/libopencv_objdetect.so.3.2.0
GetBoson: /usr/local/lib/libopencv_calib3d.so.3.2.0
GetBoson: /usr/local/lib/libopencv_features2d.so.3.2.0
GetBoson: /usr/local/lib/libopencv_flann.so.3.2.0
GetBoson: /usr/local/lib/libopencv_highgui.so.3.2.0
GetBoson: /usr/local/lib/libopencv_ml.so.3.2.0
GetBoson: /usr/local/lib/libopencv_photo.so.3.2.0
GetBoson: /usr/local/lib/libopencv_video.so.3.2.0
GetBoson: /usr/local/lib/libopencv_videoio.so.3.2.0
GetBoson: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
GetBoson: /usr/local/lib/libopencv_imgproc.so.3.2.0
GetBoson: /usr/local/lib/libopencv_core.so.3.2.0
GetBoson: CMakeFiles/GetBoson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alastair/Development/GetBoson/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GetBoson"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GetBoson.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GetBoson.dir/build: GetBoson

.PHONY : CMakeFiles/GetBoson.dir/build

CMakeFiles/GetBoson.dir/requires: CMakeFiles/GetBoson.dir/getboson.cpp.o.requires

.PHONY : CMakeFiles/GetBoson.dir/requires

CMakeFiles/GetBoson.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GetBoson.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GetBoson.dir/clean

CMakeFiles/GetBoson.dir/depend:
	cd /home/alastair/Development/GetBoson && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alastair/Development/GetBoson /home/alastair/Development/GetBoson /home/alastair/Development/GetBoson /home/alastair/Development/GetBoson /home/alastair/Development/GetBoson/CMakeFiles/GetBoson.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GetBoson.dir/depend

