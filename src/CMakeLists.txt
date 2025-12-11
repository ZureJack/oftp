
# Find includes in corresponding build directories.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## Build options
option(FTP_PORTABLE_BUILD "Build portable version")
if(FTP_PORTABLE_BUILD)
    add_definitions(-DPORTABLE_BUILD)
endif()

## Macros.
add_definitions(-DFTP_VERSION="${FTP_VERSION_FULL}")


# include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR})
add_subdirectory(lib)
add_subdirectory(sys)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(dtp)
add_subdirectory(protocol)