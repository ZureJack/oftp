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
    -fsanitize=address     # 地址检查器
    -fsanitize=undefined   # 未定义行为检查器
    -fsanitize=leak        # 内存泄漏检查器
    -fsanitize=bounds      # 数组边界检查
    -fsanitize=null        # 空指针检查
    
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
    -O2
    -g
    -DTEST_BUILD
    -fprofile-arcs
    -ftest-coverage
    --coverage
)

add_library(build_type_selector INTERFACE)

if(Test)
    set(build_type_selector "Test" compile_options_test)
elseif(Debug)
    set(build_type_selector "Debug" compile_options_debug)
else
    set(build_type_selector "Release" compile_options_release)
endif()



# 在 CMakeLists.txt 中添加
function(print_interface_library_config lib_name)
    message(STATUS "=== Configuration for ${lib_name} ===")
    
    # 获取所有属性
    get_target_property(prop_names ${lib_name} INTERFACE_PROPERTIES)
    if(prop_names)
        message(STATUS "Interface properties: ${prop_names}")
    endif()
    
    # 获取编译选项
    get_target_property(compile_opts ${lib_name} INTERFACE_COMPILE_OPTIONS)
    if(compile_opts)
        message(STATUS "Compile options: ${compile_opts}")
    endif()
    
    # 获取编译定义
    get_target_property(compile_defs ${lib_name} INTERFACE_COMPILE_DEFINITIONS)
    if(compile_defs)
        message(STATUS "Compile definitions: ${compile_defs}")
    endif()
    
    # 获取包含目录
    get_target_property(include_dirs ${lib_name} INTERFACE_INCLUDE_DIRECTORIES)
    if(include_dirs)
        message(STATUS "Include directories: ${include_dirs}")
    endif()
    
    # 获取链接选项
    get_target_property(link_opts ${lib_name} INTERFACE_LINK_OPTIONS)
    if(link_opts)
        message(STATUS "Link options: ${link_opts}")
    endif()
    
    # 获取链接库
    get_target_property(link_libs ${lib_name} INTERFACE_LINK_LIBRARIES)
    if(link_libs)
        message(STATUS "Link libraries: ${link_libs}")
    endif()
    
    message(STATUS "")
endfunction()

