cmake_minimum_required(VERSION 3.22)


project(FTP VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)



configure_file(${PROJECT_SOURCE_DIR}/config/config.h.in config.h)

#CMake options
set(CMAKE_ERROR_DEPRECATED TRUE)

#Custom options
set(RELEASE_VERSION FALSE)
set(PROJECT_COMMANY_NAME "ZureJack")
set(PROJECT_COPYRIGHT "© 2025 ZureJack")
set(PROJECT_DESCRIPTION "A simple ftp server & client.")
set(PROJECT_HOMEPAGE_URL "https://github.com/ZureJack/oftp")

# Determine version for dev builds.
if(NOT RELEASE_VERSION)
    message(NOTICE "Building unreleased code. Proceed at your own risk!")

    include(${PROJECT_SOURCE_DIR}/cmake/GetVersionFromGit.cmake)
    if(FTP_GIT_VERSION_SHA)
        # 后续出版本时再取消注释
        # if(NOT PROJECT_VERSION_PATCH EQUAL FTP_GIT_VERSION_PATCH_NEXT)
        #     message(FATAL_ERROR "Incorrect patch version! Forgot to bump?")
        # endif()

        set(FTP_VERSION_SUFFIX "-dev.${FTP_GIT_VERSION_AHEAD}+${FTP_GIT_VERSION_SHA}")
    else()
        set(FTP_VERSION_SUFFIX "-dev")
    endif()
endif()

set(FTP_VERSION_FULL "${FTP_VERSION}${FTP_VERSION_SUFFIX}")
option(BUILD_TESTING "Enable testing and build tests" OFF)

# A custom target to print the full version.
# Usage: cmake --build build --target ftp_version
add_custom_target(ftp_version
    COMMAND ${CMAKE_COMMAND} -E echo "FTP version: ${FTP_VERSION_FULL}"
    VERBATIM
)

include(${PROJECT_SOURCE_DIR}/cmake/build_type_selector.cmake)
add_subdirectory(src)
add_subdirectory(tools)

enable_testing()
add_subdirectory(test)