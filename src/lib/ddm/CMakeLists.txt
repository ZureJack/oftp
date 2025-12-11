add_library(ddm STATIC
    ddm.cpp
)

target_link_libraries(ddm PUBLIC net sys build_type_selector)
