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
CMAKE_SOURCE_DIR = /home/alastair/Development/GetBosonOneShot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alastair/Development/GetBosonOneShot

# Include any dependencies generated for this target.
include CMakeFiles/GetBosonOneShot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GetBosonOneShot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GetBosonOneShot.dir/flags.make

CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o: CMakeFiles/GetBosonOneShot.dir/flags.make
CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o: getbosononeshot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastair/Development/GetBosonOneShot/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o -c /home/alastair/Development/GetBosonOneShot/getbosononeshot.cpp

CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alastair/Development/GetBosonOneShot/getbosononeshot.cpp > CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.i

CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alastair/Development/GetBosonOneShot/getbosononeshot.cpp -o CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.s

CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o.requires:

.PHONY : CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o.requires

CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o.provides: CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o.requires
	$(MAKE) -f CMakeFiles/GetBosonOneShot.dir/build.make CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o.provides.build
.PHONY : CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o.provides

CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o.provides.build: CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o


# Object files for target GetBosonOneShot
GetBosonOneShot_OBJECTS = \
"CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o"

# External object files for target GetBosonOneShot
GetBosonOneShot_EXTERNAL_OBJECTS =

GetBosonOneShot: CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o
GetBosonOneShot: CMakeFiles/GetBosonOneShot.dir/build.make
GetBosonOneShot: /usr/local/lib/libopencv_shape.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_stitching.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_superres.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_videostab.so.3.2.0
GetBosonOneShot: /usr/local/lib/libuvc.so
GetBosonOneShot: /usr/local/lib/libopencv_objdetect.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_calib3d.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_features2d.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_flann.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_highgui.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_ml.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_photo.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_video.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_videoio.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_imgproc.so.3.2.0
GetBosonOneShot: /usr/local/lib/libopencv_core.so.3.2.0
GetBosonOneShot: CMakeFiles/GetBosonOneShot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alastair/Development/GetBosonOneShot/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GetBosonOneShot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GetBosonOneShot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GetBosonOneShot.dir/build: GetBosonOneShot

.PHONY : CMakeFiles/GetBosonOneShot.dir/build

CMakeFiles/GetBosonOneShot.dir/requires: CMakeFiles/GetBosonOneShot.dir/getbosononeshot.cpp.o.requires

.PHONY : CMakeFiles/GetBosonOneShot.dir/requires

CMakeFiles/GetBosonOneShot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GetBosonOneShot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GetBosonOneShot.dir/clean

CMakeFiles/GetBosonOneShot.dir/depend:
	cd /home/alastair/Development/GetBosonOneShot && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alastair/Development/GetBosonOneShot /home/alastair/Development/GetBosonOneShot /home/alastair/Development/GetBosonOneShot /home/alastair/Development/GetBosonOneShot /home/alastair/Development/GetBosonOneShot/CMakeFiles/GetBosonOneShot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GetBosonOneShot.dir/depend

