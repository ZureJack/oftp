add_executable(oftp-client
    main.cpp
)

target_link_libraries(oftp-client build_type_selector)
set_target_properties(oftp-client PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)