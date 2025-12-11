add_library(olog STATIC
    log.cpp
)

target_link_libraries(olog PUBLIC sys omem build_type_selector)