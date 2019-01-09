# NumberPlate CMake config file
#
# This file sets the following variables:
# NumberPlate_FOUND - Always TRUE.
# NumberPlate_INCLUDE_DIRS - Directories containing the NumberPlate include files.
# NumberPlate_IDL_DIRS - Directories containing the NumberPlate IDL files.
# NumberPlate_LIBRARIES - Libraries needed to use NumberPlate.
# NumberPlate_DEFINITIONS - Compiler flags for NumberPlate.
# NumberPlate_VERSION - The version of NumberPlate found.
# NumberPlate_VERSION_MAJOR - The major version of NumberPlate found.
# NumberPlate_VERSION_MINOR - The minor version of NumberPlate found.
# NumberPlate_VERSION_REVISION - The revision version of NumberPlate found.
# NumberPlate_VERSION_CANDIDATE - The candidate version of NumberPlate found.

message(STATUS "Found NumberPlate-1.0.0")
set(NumberPlate_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(NumberPlate_INCLUDE_DIRS
#    "/usr/local/include/numberplate-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(NumberPlate_IDL_DIRS
#    "/usr/local/include/numberplate-1/idl")
set(NumberPlate_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(NumberPlate_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(NumberPlate_LIBRARIES
        "/usr/local//libnumberplate.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(NumberPlate_LIBRARIES
        "/usr/local//libnumberplate.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(NumberPlate_DEFINITIONS ${<dependency>_DEFINITIONS})

set(NumberPlate_VERSION 1.0.0)
set(NumberPlate_VERSION_MAJOR 1)
set(NumberPlate_VERSION_MINOR 0)
set(NumberPlate_VERSION_REVISION 0)
set(NumberPlate_VERSION_CANDIDATE )

