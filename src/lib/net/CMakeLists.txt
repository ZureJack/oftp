add_library(net STATIC
    net.cpp
)

target_link_libraries(net PUBLIC sys build_type_selector)
