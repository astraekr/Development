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
CMAKE_SOURCE_DIR = "/home/alastair/Development/Image Rectification/ImageRectification"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/alastair/Development/Image Rectification/ImageRectification-build"

# Include any dependencies generated for this target.
include CMakeFiles/ImageRectification.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageRectification.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageRectification.dir/flags.make

CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o: CMakeFiles/ImageRectification.dir/flags.make
CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o: /home/alastair/Development/Image\ Rectification/ImageRectification/ImageRectification.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alastair/Development/Image Rectification/ImageRectification-build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o -c "/home/alastair/Development/Image Rectification/ImageRectification/ImageRectification.cpp"

CMakeFiles/ImageRectification.dir/ImageRectification.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageRectification.dir/ImageRectification.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alastair/Development/Image Rectification/ImageRectification/ImageRectification.cpp" > CMakeFiles/ImageRectification.dir/ImageRectification.cpp.i

CMakeFiles/ImageRectification.dir/ImageRectification.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageRectification.dir/ImageRectification.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alastair/Development/Image Rectification/ImageRectification/ImageRectification.cpp" -o CMakeFiles/ImageRectification.dir/ImageRectification.cpp.s

CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o.requires:

.PHONY : CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o.requires

CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o.provides: CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o.requires
	$(MAKE) -f CMakeFiles/ImageRectification.dir/build.make CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o.provides.build
.PHONY : CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o.provides

CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o.provides.build: CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o


# Object files for target ImageRectification
ImageRectification_OBJECTS = \
"CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o"

# External object files for target ImageRectification
ImageRectification_EXTERNAL_OBJECTS =

ImageRectification: CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o
ImageRectification: CMakeFiles/ImageRectification.dir/build.make
ImageRectification: /usr/local/lib/libopencv_shape.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_stitching.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_superres.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_videostab.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_objdetect.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_calib3d.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_features2d.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_flann.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_highgui.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_ml.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_photo.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_video.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_videoio.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_imgproc.so.3.2.0
ImageRectification: /usr/local/lib/libopencv_core.so.3.2.0
ImageRectification: CMakeFiles/ImageRectification.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/alastair/Development/Image Rectification/ImageRectification-build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ImageRectification"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageRectification.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageRectification.dir/build: ImageRectification

.PHONY : CMakeFiles/ImageRectification.dir/build

CMakeFiles/ImageRectification.dir/requires: CMakeFiles/ImageRectification.dir/ImageRectification.cpp.o.requires

.PHONY : CMakeFiles/ImageRectification.dir/requires

CMakeFiles/ImageRectification.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageRectification.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageRectification.dir/clean

CMakeFiles/ImageRectification.dir/depend:
	cd "/home/alastair/Development/Image Rectification/ImageRectification-build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/alastair/Development/Image Rectification/ImageRectification" "/home/alastair/Development/Image Rectification/ImageRectification" "/home/alastair/Development/Image Rectification/ImageRectification-build" "/home/alastair/Development/Image Rectification/ImageRectification-build" "/home/alastair/Development/Image Rectification/ImageRectification-build/CMakeFiles/ImageRectification.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ImageRectification.dir/depend

