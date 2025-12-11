add_library(omem STATIC
    mem.cpp
)

target_link_libraries(omem PUBLIC sys build_type_selector)