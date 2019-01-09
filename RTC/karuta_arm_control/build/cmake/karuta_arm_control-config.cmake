# karuta_arm_control CMake config file
#
# This file sets the following variables:
# karuta_arm_control_FOUND - Always TRUE.
# karuta_arm_control_INCLUDE_DIRS - Directories containing the karuta_arm_control include files.
# karuta_arm_control_IDL_DIRS - Directories containing the karuta_arm_control IDL files.
# karuta_arm_control_LIBRARIES - Libraries needed to use karuta_arm_control.
# karuta_arm_control_DEFINITIONS - Compiler flags for karuta_arm_control.
# karuta_arm_control_VERSION - The version of karuta_arm_control found.
# karuta_arm_control_VERSION_MAJOR - The major version of karuta_arm_control found.
# karuta_arm_control_VERSION_MINOR - The minor version of karuta_arm_control found.
# karuta_arm_control_VERSION_REVISION - The revision version of karuta_arm_control found.
# karuta_arm_control_VERSION_CANDIDATE - The candidate version of karuta_arm_control found.

message(STATUS "Found karuta_arm_control-1.0.0")
set(karuta_arm_control_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(karuta_arm_control_INCLUDE_DIRS
#    "/usr/local/include/karuta_arm_control-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(karuta_arm_control_IDL_DIRS
#    "/usr/local/include/karuta_arm_control-1/idl")
set(karuta_arm_control_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(karuta_arm_control_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(karuta_arm_control_LIBRARIES
        "/usr/local//libkaruta_arm_control.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(karuta_arm_control_LIBRARIES
        "/usr/local//libkaruta_arm_control.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(karuta_arm_control_DEFINITIONS ${<dependency>_DEFINITIONS})

set(karuta_arm_control_VERSION 1.0.0)
set(karuta_arm_control_VERSION_MAJOR 1)
set(karuta_arm_control_VERSION_MINOR 0)
set(karuta_arm_control_VERSION_REVISION 0)
set(karuta_arm_control_VERSION_CANDIDATE )

