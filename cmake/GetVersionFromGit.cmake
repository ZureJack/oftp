
# 查找Git
find_package(Git QUIET)

if(GIT_FOUND AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
    # 获取Git描述
    execute_process(
        COMMAND ${GIT_EXECUTABLE} describe --tags --always
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_DESCRIBE
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    
    # 获取提交哈希
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_SHA
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    
    if(GIT_DESCRIBE)
        set(FTP_GIT_VERSION ${GIT_DESCRIBE})
    endif()
    
    if(GIT_SHA)
        set(FTP_GIT_VERSION_SHA ${GIT_SHA})
    endif()
endif()

# 如果没有获取到Git信息，设置默认值
if(NOT FTP_GIT_VERSION)
    set(FTP_GIT_VERSION "unknown")
endif()

if(NOT FTP_GIT_VERSION_SHA)
    set(FTP_GIT_VERSION_SHA "unknown")
endif()

message(STATUS "Git版本: ${FTP_GIT_VERSION}")
message(STATUS "Git提交: ${FTP_GIT_VERSION_SHA}")