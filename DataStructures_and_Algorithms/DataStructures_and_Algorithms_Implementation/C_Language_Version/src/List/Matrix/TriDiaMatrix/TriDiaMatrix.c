#define EXPORt

#include "TriDiaMatrix.h"
#include <stdlib.h>

// 局部函数声明
static int N(int order);
static int K(int i, int j);

// 接口函数定义
DLL_API PtrMatrix InitMatrix(int order)
{
    PtrMatrix matrix = (PtrMatrix) malloc(sizeof(Matrix));
    if (!matrix) {
        exit(EXIT_FAILURE);
    }
    matrix->n = N(order);
    matrix->rows = (PtrElem) malloc(matrix->n * sizeof(ElemType));
    if (!matrix->rows) {
        exit(EXIT_FAILURE);
    }
    matrix->order = order;
    return matrix;
}
DLL_API bool ReadMatrix(PtrMatrix matrix, FILE *in)
{
    for (int k = 0; k < matrix->n; k++) {
        if (!ReadElem(&(matrix->rows[k]), in)) {
            return false;
        }
    }
    return true;
}
DLL_API Status GetElem(PtrMatrix matrix, int i, int j, PtrElem elem)
{
    if (i < 1 || j < 1 || i > matrix->order || j > matrix->order) {
        return WRONGPOS;
    }
    PtrElem edge = MakeElem(0, 0);
    int k = K(i, j);
    if (k != -1) {
        CopyElems(elem, &(matrix->rows[k]));
    } else {
        CopyElems(elem, edge);
    }
    DestroyElem(edge);
    return SUCCESS;
}
DLL_API Status UpdateElem(PtrMatrix matrix, int i, int j, PtrElem elem)
{
    if (i < 1 || j < 1 || i > matrix->order || j > matrix->order || abs(i - j) > 1) {
        return WRONGPOS;
    }
    int k = K(i, j);
    CopyElems(&(matrix->rows[k]), elem);
    return SUCCESS;
}
DLL_API void DestroyMatrix(PtrMatrix matrix)
{
    free(matrix->rows);
    free(matrix);
}
DLL_API void PrintMatrix(PtrMatrix matrix, FILE *out)
{
    int k;
    PtrElem elem = MakeElem(0, 0);
    for (int i = 1; i <= matrix->order; i++) {
        for (int j = 1; j <= matrix->order; j++) {
            k = K(i, j);
            if (j != 1) {
                fprintf(out, " ");
            }
            if (k != -1) {
                PrintElem(&(matrix->rows[k]), out);
            } else {
                PrintElem(elem, out);
            }
        }
        fprintf(out, "\n");
    }
    DestroyElem(elem);
}

// 局部函数定义
static int N(int order)
{
    return 3 * order - 2;
}
static int K(int i, int j)
{
    if (abs(i - j) <= 1) {
        return 2 * i + j - 3;
    }
    return -1;
}