set(LLVM_LINK_COMPONENTS Core Support)

add_mlir_tool(air-runner air-runner.cpp)
llvm_update_compile_flags(air-runner)

set(LIBS
    AIRDialect
    AIRUtil
    AIRInitAll
    MLIRSupport)

target_link_libraries(air-runner PRIVATE ${LIBS})

export_executable_symbols(mlir-cpu-runner)
