add_library(sys STATIC
    sys.cpp
)

target_link_libraries(sys build_type_selector)