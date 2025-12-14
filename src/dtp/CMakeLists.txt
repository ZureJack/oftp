add_executable(oftp-dtp
    main.cpp
)

target_link_libraries(oftp-dtp build_type_selector)
set_target_properties(oftp-dtp PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)