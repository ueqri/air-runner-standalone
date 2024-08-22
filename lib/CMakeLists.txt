# Copyright (C) 2022, Xilinx Inc. All rights reserved.
# Copyright (C) 2022, Advanced Micro Devices, Inc. All rights reserved.
# SPDX-License-Identifier: MIT

add_subdirectory(Dialect)
add_subdirectory(Util)

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)

add_mlir_library(
  AIRInitAll
  InitAll.cpp

  DEPENDS
  AIRDialect

  LINK_LIBS
  AIRDialect
  AIRUtil
  MLIRSupport
  ${dialect_libs})
