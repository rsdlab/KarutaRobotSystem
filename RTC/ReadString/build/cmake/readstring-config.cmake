# ReadString CMake config file
#
# This file sets the following variables:
# ReadString_FOUND - Always TRUE.
# ReadString_INCLUDE_DIRS - Directories containing the ReadString include files.
# ReadString_IDL_DIRS - Directories containing the ReadString IDL files.
# ReadString_LIBRARIES - Libraries needed to use ReadString.
# ReadString_DEFINITIONS - Compiler flags for ReadString.
# ReadString_VERSION - The version of ReadString found.
# ReadString_VERSION_MAJOR - The major version of ReadString found.
# ReadString_VERSION_MINOR - The minor version of ReadString found.
# ReadString_VERSION_REVISION - The revision version of ReadString found.
# ReadString_VERSION_CANDIDATE - The candidate version of ReadString found.

message(STATUS "Found ReadString-1.0.0")
set(ReadString_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(ReadString_INCLUDE_DIRS
#    "/usr/local/include/readstring-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(ReadString_IDL_DIRS
#    "/usr/local/include/readstring-1/idl")
set(ReadString_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(ReadString_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(ReadString_LIBRARIES
        "/usr/local//libreadstring.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(ReadString_LIBRARIES
        "/usr/local//libreadstring.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(ReadString_DEFINITIONS ${<dependency>_DEFINITIONS})

set(ReadString_VERSION 1.0.0)
set(ReadString_VERSION_MAJOR 1)
set(ReadString_VERSION_MINOR 0)
set(ReadString_VERSION_REVISION 0)
set(ReadString_VERSION_CANDIDATE )

