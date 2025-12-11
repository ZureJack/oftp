add_executable(opi-client
    main.cpp
)

target_link_libraries(opi-client build_type_selector)
set_target_properties(opi-client PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)