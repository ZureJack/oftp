add_library(protocol STATIC
    ftp.cpp
)

target_link_libraries(protocol build_type_selector)
