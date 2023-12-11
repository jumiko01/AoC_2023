cmake_minimum_required(VERSION 3.14)

project(AoC)


message("")
message("                        OPTIONS")
message("---------------------------------------------------------------")
message("  name    settings (default ^^^^)")
message("")
message("> LogLevel           NONE INFO ERROR DEBUG")
message("                     ^^^^")
message("")
message("")
message(" select option with 'cmake -Dname=setting'")
message("---------------------------------------------------------------")
message("")

option(RunCPPCheck "RunCPPCheck" OFF)
option(BuildUnitTests "BuildUnitTests" OFF)
option(GenerateDoxygenDoc "GenerateDoxygenDoc" OFF)
option(GeneratePDFDoc "GeneratePDFDoc" OFF)

# call "cmake -DLOG_LEVEL=DEBUG .." with the desired log level to enable debugging
set(LogLevel "DEBUG" CACHE STRING "Option for setting the log level (NONE, INFO, ERROR, DEBUG) for the build.")
set_property(CACHE LogLevel PROPERTY STRINGS NONE INFO ERROR DEBUG)

if(LogLevel)
    if(${LogLevel} STREQUAL "DEBUG")
        add_definitions(-DLOG_LEVEL=3)
        message(STATUS "Compiling with DEBUG log level")
    elseif(${LogLevel} STREQUAL "ERROR")
        add_definitions(-DLOG_LEVEL=2)
        message(STATUS "Compiling with ERROR log level")
    elseif(${LogLevel} STREQUAL "INFO")
        add_definitions(-DLOG_LEVEL=1)
        message(STATUS "Ccompiling with INFO log level")
    else()
        add_definitions(-DLOG_LEVEL=0)
        message(STATUS "Compiling without logging")
    endif()
endif()

message("### USER COMMENT: configuring main.exe ###")

add_executable(main
    main.cpp
    01.cpp
    02.cpp
    03.cpp
    xx.cpp
)

target_include_directories(main PRIVATE
#    D:/msys64/usr/lib/gcc/x86_64-pc-msys/11.3.0/include/c++/
    ../Lib/
 )


set_target_properties(main PROPERTIES CXX_STANDARD 11)
target_compile_options(main PRIVATE -Wall)
