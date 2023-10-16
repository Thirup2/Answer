#ifndef MATRIX_H_
#define MATRIX_H_

#define STDIN false
#define STDOUT false

// 如果要测试不同实现方式的矩阵，则修改下方的 #define
// 并将 CMakeLists.txt 中的依赖库修改为目标链接库
#define TDMATRIX

#ifdef SMATRIX
#include "SymMatrix.h"
#else
#ifdef TMATRIX
#include "TriMatrix.h"
#else
#ifdef TDMATRIX
#include "TriDiaMatrix.h"
#endif // TDMATRIX
#endif // TMATRIX
#endif // SMATRIX

#endif