#define EXPORT

#include "SymMatrix.h"
#include <stdlib.h>

// 局部函数声明
static int GetN(int order);
static int GetK(int i, int j);

// 接口函数定义
DLL_API PtrMatrix InitMatrix(int order)
{
    if (order <= 0) {
        return NULL;
    }
    PtrMatrix matrix = (PtrMatrix) malloc(sizeof(Matrix));
    if (!matrix) {
        exit(EXIT_FAILURE);
    }
    matrix->n = GetN(order);
    matrix->data = (PtrElem) malloc(matrix->n * sizeof(ElemType));
    if (!matrix->data) {
        exit(EXIT_FAILURE);
    }
    matrix->order = order;
    return matrix;
}
DLL_API bool ReadMatrix(PtrMatrix matrix, FILE *in)
{
    for (int k = 0; k < matrix->n; k++) {
        if (!ReadElem(&(matrix->data[k]), in)) {
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
    int k = GetK(i, j);
    CopyElems(elem, &(matrix->data[k]));
    return SUCCESS;
}
DLL_API Status UpdateElem(PtrMatrix matrix, int i, int j, PtrElem elem)
{
    if (i < 1 || j < 1 || i > matrix->order || j > matrix->order) {
        return WRONGPOS;
    }
    int k = GetK(i, j);
    CopyElems(&(matrix->data[k]), elem);
    return SUCCESS;
}
DLL_API void DestroyMatrix(PtrMatrix matrix)
{
    free(matrix->data);
    free(matrix);
}
DLL_API void PrintMatrix(PtrMatrix matrix, FILE *out)
{
    int k;
    for (int i = 1; i <= matrix->order; i++) {
        for (int j = 1; j <= matrix->order; j++) {
            k = GetK(i, j);
            if (j != 1) {
                fprintf(out, " ");
            }
            PrintElem(&(matrix->data[k]), out);
        }
        fprintf(out, "\n");
    }
}

// 局部函数定义
static int GetN(int order)
{
    return (order * (order + 1)) / 2;
}
static int GetK(int i, int j)
{
    if (i >= j) {
        return (i * (i - 1)) / 2 + j - 1;
    } else {
        return (j * (j - 1)) / 2 + i - 1;
    }
}