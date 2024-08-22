add_custom_target(air-headers)
set_target_properties(air-headers PROPERTIES FOLDER "Misc")
add_dependencies(air-headers mlir-headers)

add_subdirectory(air)
