#define EXPORT

#include "SpaMatrix.h"
#include <stdlib.h>

// 局部函数声明
static PtrNode AllocANode(PtrElem elem, int col);
static PtrNode IsNodeIn(PtrMatrix matrix, int i, int j);

// 接口函数定义
DLL_API PtrMatrix InitMatrix(int order)
{
    PtrMatrix matrix = (PtrMatrix) malloc(sizeof(Matrix));
    if (!matrix) {
        exit(EXIT_FAILURE);
    }
    matrix->rows = (PtrNode *) malloc(order * sizeof(PtrNode));
    if (!matrix->rows) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < order; i++) {
        matrix->rows[i] = NULL;
    }
    matrix->order = order;
    return matrix;
}
DLL_API bool ReadMatrix(PtrMatrix matrix, FILE *in) { return true; }
DLL_API Status GetElem(PtrMatrix matrix, int i, int j, PtrElem elem)
{
    if (i < 1 || j < 1 || i > matrix->order || j > matrix->order) {
        return WRONGPOS;
    }
    PtrNode node = IsNodeIn(matrix, i, j);
    if (node) {
        CopyElems(elem, &(node->data));
    } else {
        PtrElem newnode = MakeElem(0, 0);
        CopyElems(elem, newnode);
        DestroyElem(newnode);
    }
    return SUCCESS;
}
DLL_API Status UpdateElem(PtrMatrix matrix, int i, int j, PtrElem elem)
{
    if (i < 1 || j < 1 || i > matrix->order || j > matrix->order) {
        return WRONGPOS;
    }
    PtrNode node = IsNodeIn(matrix, i, j);
    if (node) {
        CopyElems(&(node->data), elem);
    } else {
        node = AllocANode(elem, j);
        PtrNode *row_st = &matrix->rows[i - 1];
        if (!*row_st) {
            *row_st = node;
        } else {
            PtrNode travel = *row_st;
            if (travel->col < j) {
                while (travel->next && travel->next->col < j) {
                    travel = travel->next;
                }
                node->next = travel->next;
                travel->next = node;
            } else {
                node->next = *row_st;
                *row_st = node;
            }
        }
    }
    return SUCCESS;
}
DLL_API void DestroyMatrix(PtrMatrix matrix)
{
    PtrNode travel;
    PtrNode del;
    for (int i = 0; i < matrix->order; i++) {
        travel = matrix->rows[i];
        while (travel) {
            del = travel;
            travel = travel->next;
            free(del);
        }
    }
    free(matrix->rows);
    free(matrix);
}
DLL_API void PrintMatrix(PtrMatrix matrix, FILE *out)
{
    PtrElem elem = MakeElem(0, 0);
    PtrNode travel;
    for (int i = 0; i < matrix->order; i++) {
        travel = matrix->rows[i];
        for (int j = 1; j <= matrix->order; j++) {
            if (j != 1) {
                fprintf(out, " ");
            }
            if (travel) {
                if (travel->col > j) {
                    PrintElem(elem, out);
                } else {
                    PrintElem(&(travel->data), out);
                    travel = travel->next;
                }
            } else {
                PrintElem(elem, out);
            }
        }
        fprintf(out, "\n");
    }
    DestroyElem(elem);
}

// 局部函数定义
static PtrNode AllocANode(PtrElem elem, int col)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        exit(EXIT_FAILURE);
    }
    if (elem) {
        CopyElems(&(node->data), elem);
    }
    node->next = NULL;
    node->col = col;
    return node;
}
static PtrNode IsNodeIn(PtrMatrix matrix, int i, int j)
{
    PtrNode travel = matrix->rows[i - 1];
    while (travel && travel->col < j) {
        travel = travel->next;
    }
    if (!travel || travel->col > j) {
        return NULL;
    } else {
        return travel;
    }
}