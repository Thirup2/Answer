#define EXPORT

// --------------------------- 包含头文件 --------------------------- //
#include "Vector.h"
#include <stdlib.h>
#include <stdio.h>

// ---------------------------   接口    --------------------------- //

// 函数接口定义

// 构造数组
PtrVector DLL_CALL InitVector(void)
{
    PtrVector vector = (PtrVector) malloc(sizeof(Vector));
    if (!vector) {
        exit(EXIT_FAILURE);
    }
    vector->data = (PtrElem) malloc(sizeof(ElemType));
    if (!vector->data) {
        exit(EXIT_FAILURE);
    }
    vector->length = 0;
    vector->capacity = 0;
    return vector;
}
PtrVector DLL_CALL CreateVector(size_t size, cPtrElem elem)
{
    PtrVector vector = (PtrVector) malloc(sizeof(Vector));
    if (!vector) {
        exit(EXIT_FAILURE);
    }
    vector->data = (PtrElem) malloc((2 * size + 1) * sizeof(ElemType));
    if (!vector->data) {
        exit(EXIT_FAILURE);
    }
    for (size_t i = 1; i <= size; i++) {
        AssignElem(&(vector->data[i]), elem);
    }
    vector->capacity = 2 * size;
    vector->length = size;
    return vector;
}
PtrVector DLL_CALL CopyVector(cPtrVector copied)
{
    PtrVector vector = (PtrVector) malloc(sizeof(Vector));
    if (!vector) {
        exit(EXIT_FAILURE);
    }
    vector->data = (PtrElem) malloc((copied->capacity + 1) * sizeof(ElemType));
    if (!vector->data) {
        exit(EXIT_FAILURE);
    }
    for (size_t i = 1; i <= copied->length; i++) {
        AssignElem(&(vector->data[i]), &(copied->data[i]));
    }
    vector->length = copied->length;
    vector->capacity = copied->capacity;
    return vector;
}

// 清空数组
void DLL_CALL ClearVector(PtrVector vector)
{
    vector->length = 0;
}

// 销毁数组
void DLL_CALL DestroyVector(PtrVector vector)
{
    free(vector->data);
    free(vector);
}

// 基本信息
bool DLL_CALL VectorEmpty(cPtrVector vector)
{
    return VectorLength(vector) == 0;
}
size_t DLL_CALL VectorLength(cPtrVector vector)
{
    return vector->length;
}

// 改变元素
void DLL_CALL CopyAssign(PtrVector vector, cPtrVector copied)
{
    if (vector->capacity < copied->length) {
        vector->data = (PtrElem) realloc(vector->data, (copied->capacity + 1) * sizeof(ElemType));
        if (!vector->data) {
            exit(EXIT_FAILURE);
        }
        vector->capacity = copied->capacity;
    }
    for (size_t i = 1; i <= copied->length; i++) {
        AssignElem(&(vector->data[i]), &(copied->data[i]));
    }
    vector->length = copied->length;
}
Status DLL_CALL PushBack(PtrVector vector, cPtrElem elem)
{
    if (vector->length == vector->capacity) {
        vector->capacity *= 2;
        vector->data = (PtrElem) realloc(vector->data, (vector->capacity + 1) * sizeof(ElemType));
        if (!vector->data) {
            exit(EXIT_FAILURE);
        }
    }
    AssignElem(&(vector->data[++vector->length]), elem);
    return SUCCESS;
}
Status DLL_CALL PopBack(PtrVector vector, PtrElem elem)
{
    if (VectorEmpty(vector)) {
        return ISEMPTY;
    }
    AssignElem(elem, &(vector->data[vector->length--]));
    if (vector->length < vector->capacity / 4) {
        vector->capacity /= 2;
        vector->data = (PtrElem) realloc(vector->data, (vector->capacity + 1) * sizeof(ElemType));
        if (!vector->data) {
            exit(EXIT_FAILURE);
        }
    }
    return SUCCESS;
}
Status DLL_CALL VectorInsert(PtrVector vector, size_t i, cPtrElem elem)
{
    if (vector->length == vector->capacity) {
        vector->capacity *= 2;
        vector->data = (PtrElem) realloc(vector->data, (vector->capacity + 1) * sizeof(ElemType));
        if (!vector->data) {
            exit(EXIT_FAILURE);
        }
    }
    if (i < 1 || i > vector->length + 1) {
        return WRONGPOS;
    }
    if (i == vector->length + 1) {
        return PushBack(vector, elem);
    }
    for (size_t s = vector->length; s >= i; s--) {
        AssignElem(&(vector->data[s + 1]), &(vector->data[s]));
    }
    AssignElem(&(vector->data[i]), elem);
    vector->length++;
    return SUCCESS;

}
Status DLL_CALL VectorDelete(PtrVector vector, size_t i, PtrElem elem)
{
    if (VectorEmpty(vector)) {
        return ISEMPTY;
    }
    if (i < 1 || i > vector->length) {
        return WRONGPOS;
    }
    if (i == vector->length) {
        return PopBack(vector, elem);
    }
    AssignElem(elem, &(vector->data[i]));
    for (size_t s = i; s < vector->length; s++) {
        AssignElem(&(vector->data[s]), &(vector->data[s + 1]));
    }
    vector->length--;
    if (vector->length < vector->capacity / 4) {
        vector->capacity /= 2;
        vector->data = (PtrElem) realloc(vector->data, (vector->capacity + 1) * sizeof(ElemType));
        if (!vector->data) {
            exit(EXIT_FAILURE);
        }
    }
    return SUCCESS;
}

// 访问
Status DLL_CALL GetElem(cPtrVector vector, size_t i, PtrElem elem)
{
    if (VectorEmpty(vector)) {
        return ISEMPTY;
    }
    if (i < 1 || i > vector->length) {
        return WRONGPOS;
    }
    AssignElem(elem, &(vector->data[i]));
    return SUCCESS;
}
void DLL_CALL PrintVector(cPtrVector vector)
{
    cPtrElem cbeg = cBegin(vector);
    cPtrElem cend = cEnd(vector);
    while (cbeg != cend) {
        PrintElem(cbeg);
        printf(" ");
        cbeg = cNext(cbeg);
    }
    printf("\n");
}

// 迭代器操作
PtrElem DLL_CALL Begin(PtrVector vector)
{
    return &(vector->data[1]);
}
PtrElem DLL_CALL End(PtrVector vector)
{
    return &(vector->data[vector->length + 1]);
}
PtrElem DLL_CALL Next(PtrElem now)
{
    return now++;
}
cPtrElem DLL_CALL cBegin(cPtrVector vector)
{
    return Begin((PtrVector) vector);
}
cPtrElem DLL_CALL cEnd(cPtrVector vector)
{
    return End((PtrVector) vector);
}
cPtrElem DLL_CALL cNext(cPtrElem now)
{
    return Next((PtrElem) now);
}

// 算法
void DLL_CALL SortVector(PtrVector vector)
{
    size_t min;
    ElemType elem;
    for (size_t i = 1; i < vector->length; i++) {
        min = i;
        for (size_t j = i + 1; j <= vector->length; j++) {
            if (Less(&(vector->data[j]), &(vector->data[min]))) {
                min = j;
            }
        }
        AssignElem(&elem, &(vector->data[min]));
        AssignElem(&(vector->data[min]), &(vector->data[i]));
        AssignElem(&(vector->data[i]), &elem);
    }
}
size_t DLL_CALL SearchElem(PtrVector vector, cPtrElem elem)
{
    AssignElem(&(vector->data[0]), elem);
    size_t i = vector->length;
    while (!Equal(&(vector->data[i]), elem)) {
        --i;
    }
    return i;
}
void DLL_CALL DeleteRepeat(PtrVector vector)
{
    if (VectorEmpty(vector) || VectorLength(vector) == 1) {
        return;
    }
    size_t i = 1, j = 2;
    while (j <= VectorLength(vector)) {
        if (!Equal(&(vector->data[i]), &(vector->data[j]))) {
            AssignElem(&(vector->data[++i]), &(vector->data[j]));
        }
        j++;
    }
    vector->length = i;
    if (vector->length < vector->capacity / 4) {
        vector->capacity /= 2;
        vector->data = (PtrElem) realloc(vector->data, (vector->capacity + 1) * sizeof(ElemType));
        if (!vector->data) {
            exit(EXIT_FAILURE);
        }
    }
}