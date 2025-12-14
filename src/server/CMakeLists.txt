add_executable(oftp-server
    main.cpp
)
target_link_libraries(oftp-server build_type_selector)
set_target_properties(oftp-server PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)