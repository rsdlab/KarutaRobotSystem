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
CMAKE_SOURCE_DIR = /home/rsdlab/workspace/ReadString

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rsdlab/workspace/ReadString/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ReadString.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ReadString.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ReadString.dir/flags.make

src/CMakeFiles/ReadString.dir/ReadString.cpp.o: src/CMakeFiles/ReadString.dir/flags.make
src/CMakeFiles/ReadString.dir/ReadString.cpp.o: ../src/ReadString.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsdlab/workspace/ReadString/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ReadString.dir/ReadString.cpp.o"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReadString.dir/ReadString.cpp.o -c /home/rsdlab/workspace/ReadString/src/ReadString.cpp

src/CMakeFiles/ReadString.dir/ReadString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReadString.dir/ReadString.cpp.i"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rsdlab/workspace/ReadString/src/ReadString.cpp > CMakeFiles/ReadString.dir/ReadString.cpp.i

src/CMakeFiles/ReadString.dir/ReadString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReadString.dir/ReadString.cpp.s"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rsdlab/workspace/ReadString/src/ReadString.cpp -o CMakeFiles/ReadString.dir/ReadString.cpp.s

src/CMakeFiles/ReadString.dir/ReadString.cpp.o.requires:

.PHONY : src/CMakeFiles/ReadString.dir/ReadString.cpp.o.requires

src/CMakeFiles/ReadString.dir/ReadString.cpp.o.provides: src/CMakeFiles/ReadString.dir/ReadString.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ReadString.dir/build.make src/CMakeFiles/ReadString.dir/ReadString.cpp.o.provides.build
.PHONY : src/CMakeFiles/ReadString.dir/ReadString.cpp.o.provides

src/CMakeFiles/ReadString.dir/ReadString.cpp.o.provides.build: src/CMakeFiles/ReadString.dir/ReadString.cpp.o


src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o: src/CMakeFiles/ReadString.dir/flags.make
src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o: idl/BasicDataTypeSK.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsdlab/workspace/ReadString/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o -c /home/rsdlab/workspace/ReadString/build/idl/BasicDataTypeSK.cc

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.i"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rsdlab/workspace/ReadString/build/idl/BasicDataTypeSK.cc > CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.i

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.s"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rsdlab/workspace/ReadString/build/idl/BasicDataTypeSK.cc -o CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.s

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o.requires:

.PHONY : src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o.requires

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o.provides: src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o.requires
	$(MAKE) -f src/CMakeFiles/ReadString.dir/build.make src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o.provides.build
.PHONY : src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o.provides

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o.provides.build: src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o


src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o: src/CMakeFiles/ReadString.dir/flags.make
src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o: idl/BasicDataTypeDynSK.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsdlab/workspace/ReadString/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o -c /home/rsdlab/workspace/ReadString/build/idl/BasicDataTypeDynSK.cc

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.i"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rsdlab/workspace/ReadString/build/idl/BasicDataTypeDynSK.cc > CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.i

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.s"
	cd /home/rsdlab/workspace/ReadString/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rsdlab/workspace/ReadString/build/idl/BasicDataTypeDynSK.cc -o CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.s

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o.requires:

.PHONY : src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o.requires

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o.provides: src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o.requires
	$(MAKE) -f src/CMakeFiles/ReadString.dir/build.make src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o.provides.build
.PHONY : src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o.provides

src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o.provides.build: src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o


# Object files for target ReadString
ReadString_OBJECTS = \
"CMakeFiles/ReadString.dir/ReadString.cpp.o" \
"CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o" \
"CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o"

# External object files for target ReadString
ReadString_EXTERNAL_OBJECTS =

src/ReadString.so: src/CMakeFiles/ReadString.dir/ReadString.cpp.o
src/ReadString.so: src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o
src/ReadString.so: src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o
src/ReadString.so: src/CMakeFiles/ReadString.dir/build.make
src/ReadString.so: /usr/local/lib/libopencv_cudabgsegm.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudaobjdetect.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudastereo.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_stitching.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_superres.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_videostab.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_aruco.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_bgsegm.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_bioinspired.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_ccalib.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_dpm.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_freetype.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_fuzzy.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_hdf.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_line_descriptor.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_optflow.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_reg.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_saliency.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_stereo.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_structured_light.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_surface_matching.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_tracking.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_xfeatures2d.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_ximgproc.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_xobjdetect.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_xphoto.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudafeatures2d.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_shape.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudacodec.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudaoptflow.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudalegacy.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudawarping.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_phase_unwrapping.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_rgbd.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_calib3d.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_video.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_datasets.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_dnn.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_face.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_plot.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_text.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_features2d.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_flann.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_objdetect.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_ml.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_highgui.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_photo.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudaimgproc.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudafilters.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudaarithm.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_videoio.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_imgproc.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_core.so.3.2.0
src/ReadString.so: /usr/local/lib/libopencv_cudev.so.3.2.0
src/ReadString.so: src/CMakeFiles/ReadString.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rsdlab/workspace/ReadString/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ReadString.so"
	cd /home/rsdlab/workspace/ReadString/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReadString.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ReadString.dir/build: src/ReadString.so

.PHONY : src/CMakeFiles/ReadString.dir/build

src/CMakeFiles/ReadString.dir/requires: src/CMakeFiles/ReadString.dir/ReadString.cpp.o.requires
src/CMakeFiles/ReadString.dir/requires: src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeSK.cc.o.requires
src/CMakeFiles/ReadString.dir/requires: src/CMakeFiles/ReadString.dir/__/idl/BasicDataTypeDynSK.cc.o.requires

.PHONY : src/CMakeFiles/ReadString.dir/requires

src/CMakeFiles/ReadString.dir/clean:
	cd /home/rsdlab/workspace/ReadString/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ReadString.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ReadString.dir/clean

src/CMakeFiles/ReadString.dir/depend:
	cd /home/rsdlab/workspace/ReadString/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rsdlab/workspace/ReadString /home/rsdlab/workspace/ReadString/src /home/rsdlab/workspace/ReadString/build /home/rsdlab/workspace/ReadString/build/src /home/rsdlab/workspace/ReadString/build/src/CMakeFiles/ReadString.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ReadString.dir/depend

