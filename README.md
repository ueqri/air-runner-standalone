# AIR Runner Standalone

AIR Runner is a performance simulator that models the concurrent execution of MLIR-AIR programs.

This repository decouples the implementation of AIR Runner from [Xilinx/mlir-air](https://github.com/Xilinx/mlir-air) for easy building and extended development.

## Build

Instead of building and installing a giant set of dependencies and playing with the black-magic scripts provided by [mlir-air](https://github.com/Xilinx/mlir-air/tree/main/utils), we can build the AIR router based on just two dependencies:

1. LLVM
2. MLIR

We use a `clang` compiler and a faster `lld` linker for build as per MLIR common/best practice.

```bash
mkdir build
cd build
cmake .. \
    -GNinja \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DLLVM_DIR=/path/to/llvm/build/lib/cmake/llvm \
    -DMLIR_DIR=/path/to/llvm/build/lib/cmake/mlir \
    -DLLVM_USE_LINKER=lld
ninja air-runner
```

## Usage

It mainly takes the following inputs and outputs the estimated latency of the program and the simulated time traces.

1. An AIE architecture description (precisely, an AIE device's resource model). [Example](https://github.com/Xilinx/mlir-air/blob/main/mlir/test/Util/Runner/custom_op/arch.json).
2. An MLIR-AIR program. [Example](https://github.com/Xilinx/mlir-air/blob/main/mlir/test/Util/Runner/custom_op/tiny_nn.mlir).

More unit tests are located [here](https://github.com/Xilinx/mlir-air/tree/main/mlir/test/Util/Runner). They will be integrated into this repo soon after dealing with the required [llvm-lit](https://llvm.org/docs/TestingGuide.html) testing framework.

## Note

The repo is based on commit [0426adb](https://github.com/Xilinx/mlir-air/commit/0426adb2c98facbcc4a36d0af7cd63aff6759fda) of [Xilinx/mlir-air](https://github.com/Xilinx/mlir-air).
