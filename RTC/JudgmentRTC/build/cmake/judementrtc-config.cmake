# JudementRTC CMake config file
#
# This file sets the following variables:
# JudementRTC_FOUND - Always TRUE.
# JudementRTC_INCLUDE_DIRS - Directories containing the JudementRTC include files.
# JudementRTC_IDL_DIRS - Directories containing the JudementRTC IDL files.
# JudementRTC_LIBRARIES - Libraries needed to use JudementRTC.
# JudementRTC_DEFINITIONS - Compiler flags for JudementRTC.
# JudementRTC_VERSION - The version of JudementRTC found.
# JudementRTC_VERSION_MAJOR - The major version of JudementRTC found.
# JudementRTC_VERSION_MINOR - The minor version of JudementRTC found.
# JudementRTC_VERSION_REVISION - The revision version of JudementRTC found.
# JudementRTC_VERSION_CANDIDATE - The candidate version of JudementRTC found.

message(STATUS "Found JudementRTC-1.0.0")
set(JudementRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(JudementRTC_INCLUDE_DIRS
#    "/usr/local/include/judementrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(JudementRTC_IDL_DIRS
#    "/usr/local/include/judementrtc-1/idl")
set(JudementRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(JudementRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(JudementRTC_LIBRARIES
        "/usr/local//libjudementrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(JudementRTC_LIBRARIES
        "/usr/local//libjudementrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(JudementRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(JudementRTC_VERSION 1.0.0)
set(JudementRTC_VERSION_MAJOR 1)
set(JudementRTC_VERSION_MINOR 0)
set(JudementRTC_VERSION_REVISION 0)
set(JudementRTC_VERSION_CANDIDATE )

