add_library(compile_options INTERFACE)
target_compile_options(compile_options INTERFACE
    -Wall
    -Wextra
    -Wpedantic
)
target_compile_features(compile_options INTERFACE cxx_std_17)
# Release 配置
add_library(compile_options_release INTERFACE)
target_link_libraries(compile_options_release INTERFACE compile_options)
target_compile_options(compile_options_release INTERFACE
    -Wall
    -Wextra
    -Wpedantic
    -O2
)

# Debug 配置
add_library(compile_options_debug INTERFACE)
target_link_libraries(compile_options_debug INTERFACE compile_options)
target_compile_options(compile_options_debug INTERFACE
    -Wall
    -Wextra
    -Wpedantic
    -O0
    -g3
    -ggdb
    -DDEBUG_BUILD
    # Sanitizers（错误检测）
    # -fsanitize=address     # 地址检查器
    # -fsanitize=undefined   # 未定义行为检查器
    # -fsanitize=leak        # 内存泄漏检查器
    # -fsanitize=bounds      # 数组边界检查
    # -fsanitize=null        # 空指针检查
    
    # 调试辅助
    -fno-omit-frame-pointer   # 保留帧指针
    -fno-inline               # 禁用内联
    -fno-optimize-sibling-calls  # 禁用尾调用优化
    -fstack-protector-all    # 栈保护
    -fno-common              # 防止公共变量
)

# Test 配置
add_library(compile_options_test INTERFACE)
target_link_libraries(compile_options_test INTERFACE compile_options)
target_compile_options(compile_options_test INTERFACE
    -Wall
    -Wextra
    -Wpedantic
    -O0
    -g
    -DTEST_BUILD
    -fprofile-arcs
    -ftest-coverage
    --coverage
)
target_link_options(compile_options_test INTERFACE 
    -fprofile-arcs
    -ftest-coverage
    --coverage
)

add_library(build_type_selector INTERFACE)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(build_type_selector INTERFACE compile_options_debug)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_link_libraries(build_type_selector INTERFACE compile_options_release)
elseif(CMAKE_BUILD_TYPE STREQUAL "Test")
    target_link_libraries(build_type_selector INTERFACE compile_options_test)
else()
    # 默认使用 Debug
    target_link_libraries(build_type_selector INTERFACE compile_options_debug)
endif()

message(STATUS "Selected compile options: ${SELECTED_COMPILE_OPTIONS}")

