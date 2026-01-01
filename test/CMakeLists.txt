
# 从gitpub下载不稳定，还是使用镜像源吧
# 下载 gtest
# include(FetchContent)
# FetchContent_Declare(googletest
#                     GIT_REPOSITORY https://github.com/google/googletest.git
#                     GIT_TAG release-1.4.0
#                     )
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)
# include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR})
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/test*.cpp")
set(testlib olog omem)
foreach(test_file ${TEST_FILES})
    # 获取文件名（不含路径）
    get_filename_component(filename ${test_file} NAME)
    
    # 去除扩展名
    string(REGEX REPLACE "\\.[^.]*$" "" target_test_filename ${filename})
    
    # 去除 "test" 前缀（不区分大小写）
    string(REGEX REPLACE "^[Tt]est_" "" test_name ${target_test_filename})
    string(REGEX REPLACE "^[Tt]est" "" ctest_name ${test_name})
    
    add_executable(${target_test_filename} ${filename})
    target_link_libraries(${target_test_filename} PRIVATE GTest::gtest build_type_selector
                            ${testlib}
    )
    message(STATUS "build_type_selector: ${build_type_selector}")
#    add_test(NAME ${ctest_name} COMMAND ${target_test_filename})
    add_test(NAME ${ctest_name}
        COMMAND ${CMAKE_COMMAND} -E env
            GCOV_PREFIX=${CMAKE_BINARY_DIR}/test/coverage
            GCOV_PREFIX_STRIP=999
            $<TARGET_FILE:${target_test_filename}>
    )

    # message(STATUS "原始文件: ${filename}")
    # message(STATUS "去除扩展名: ${target_test_filename}")
    # message(STATUS "去除test前缀: ${ctest_name}")
endforeach()
message(STATUS "Found test files: ${TEST_FILES}")
