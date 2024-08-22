//===- InitAll.cpp ----------------------------------------------*- C++ -*-===//
//
// Copyright (C) 2021-2022, Xilinx Inc. All rights reserved.
// Copyright (C) 2022, Advanced Micro Devices, Inc. All rights reserved.
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//

#include "air/InitAll.h"

#include "air/Dialect/AIR/AIRDialect.h"
#include "mlir/IR/Dialect.h"
#include "mlir/InitAllPasses.h"

void xilinx::air::registerAllDialects(mlir::DialectRegistry &registry) {
  registry.insert<xilinx::air::airDialect>();
}
