#define EXPORT

#include "TriMatrix.h"
#include <stdlib.h>
#include <ctype.h>

// 局部函数声明
static int GetN(int order);
static int GetK(int i, int j, int n, bool down);

// 接口函数定义
DLL_API PtrMatrix InitMatrix(int order)
{
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
    matrix->down = true;
    return matrix;
}
DLL_API bool ReadMatrix(PtrMatrix matrix, FILE *in)
{
    char ch = toupper(getc(in));
    if (ch == 'U') {
        matrix->down = false;
    } else if (ch == 'D') {
        matrix->down = true;
    }
    while (getc(in) != '\n');
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
    int k = GetK(i, j, matrix->order, matrix->down);
    CopyElems(elem, &(matrix->data[k]));
    return SUCCESS;
}
DLL_API Status UpdateElem(PtrMatrix matrix, int i, int j, PtrElem elem)
{
    if (i < 1 || j < 1 || i > matrix->order || j > matrix->order) {
        return WRONGPOS;
    }
    int k = GetK(i, j, matrix->order, matrix->down);
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
            k = GetK(i, j, matrix->order, matrix->down);
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
    return (order * (order + 1)) / 2 + 1;
}
static int GetK(int i, int j, int n, bool down)
{
    if (down) {
        if (i >= j) {
            return (i * (i - 1)) / 2 + j - 1;
        }
    } else {
        if (i <= j) {
            return ((i - 1) * (2 * n - i + 2)) / 2 + (j - i);
        }
    }
    return (n * (n + 1)) / 2;
}