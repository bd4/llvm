//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <utils.h>

// TODO: Enable half precision when the sw routine is implemented.
#if __CLC_FPSIZE > 16

_CLC_OVERLOAD _CLC_DEF __CLC_GENTYPE __spirv_ocl_pow(__CLC_GENTYPE x, __CLC_GENTYPE y) {
  return __clc_pow(x, y);
}

#endif
