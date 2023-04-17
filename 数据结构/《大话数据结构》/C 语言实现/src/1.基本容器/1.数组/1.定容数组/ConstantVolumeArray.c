#define EXPORT

// --------------------------- 包含头文件 --------------------------- //
#include "ConstantVolumeArray.h"
#include <stdlib.h>
#include <stdio.h>

// ---------------------------   接口    --------------------------- //

// 函数接口定义

// 构造函数
PtrConstVA DLL_CALL InitArray(size_t size)
{
    PtrConstVA array = (PtrConstVA) malloc(sizeof(ConstantVolumeArray));
    if (!array) {
        exit(EXIT_FAILURE);
    }
    array->size = size;
    array->length = 0;
    array->data = (PtrElem) malloc((size + 1) * sizeof(ElemType));
    if (!array->data) {
        exit(EXIT_FAILURE);
    }
    return array;
}
PtrConstVA DLL_CALL CreateArray(size_t size, cPtrElem elem)
{
    PtrConstVA array = InitArray(size);
    for (size_t i = 1; i <= array->size; i++) {
        AssignElem(&(array->data[i]), elem);
    }
    return array;
}
PtrConstVA DLL_CALL CopyArray(cPtrConstVA copied)
{
    PtrConstVA array = InitArray(copied->size);
    for (size_t i = 1; i <= array->size; i++) {
        AssignElem(&(array->data[i]), &(copied->data[i]));
    }
    return array;
}

// 清空数组
void DLL_CALL ClearArray(PtrConstVA array)
{
    array->length = 0;
}

// 销毁数组
void DLL_CALL DestroyArray(PtrConstVA array)
{
    free(array->data);
    free(array);
}

// 基本信息
bool DLL_CALL ArrayEmpty(cPtrConstVA array)
{
    return !array->length;
}
bool DLL_CALL ArrayFull(cPtrConstVA array)
{
    return array->length == array->size;
}
size_t DLL_CALL ArrayLength(cPtrConstVA array)
{
    return array->length;
}

// 改变元素
void DLL_CALL CopyAssign(PtrConstVA array, cPtrConstVA copied)
{
    size_t l = (copied->length <= array->size) ? copied->length : array->size;
    array->length = l;
    for (size_t i = 1; i <= l; i++) {
        AssignElem(&(array->data[i]), &(copied->data[i]));
    }
}
Status DLL_CALL PushBack(PtrConstVA array, cPtrElem elem)
{
    if (ArrayFull(array)) {
        return ISFULL;
    }
    AssignElem(&(array->data[++array->length]), elem);
    return SUCCESS;
}
Status DLL_CALL PopBack(PtrConstVA array, PtrElem elem)
{
    if (ArrayEmpty(array)) {
        return ISEMPTY;
    }
    AssignElem(elem, &(array->data[array->length--]));
    return SUCCESS;
}
Status DLL_CALL ArrayInsert(PtrConstVA array, size_t i, cPtrElem elem)
{
    if (ArrayFull(array)) {
        return ISFULL;
    }
    if (i < 1 || i > ArrayLength(array) + 1) {
        return WRONGPOS;
    }
    if (i == ArrayLength(array) + 1) {
        return PushBack(array, elem);
    }
    for (size_t s = ArrayLength(array); s >= i; --s) {
        AssignElem(&(array->data[s + 1]), &(array->data[s]));
    }
    AssignElem(&(array->data[i]), elem);
    array->length++;
    return SUCCESS;
}
Status DLL_CALL ArrayDelete(PtrConstVA array, size_t i, PtrElem elem)
{
    if (ArrayEmpty(array)) {
        return ISEMPTY;
    }
    if (i < 1 || i > ArrayLength(array)) {
        return WRONGPOS;
    }
    if (i == ArrayLength(array)) {
        return PopBack(array, elem);
    }
    for (size_t s = i; s < ArrayLength(array); s++) {
        AssignElem(&(array->data[s]), &(array->data[s + 1]));
    }
    array->length--;
    return SUCCESS;
}

// 访问
Status DLL_CALL GetElem(cPtrConstVA array, size_t i, PtrElem elem)
{
    if (ArrayEmpty(array)) {
        return ISEMPTY;
    }
    if (i < 1 || i > ArrayLength(array)) {
        return WRONGPOS;
    }
    AssignElem(elem, &(array->data[i]));
    return SUCCESS;
}
void DLL_CALL PrintArray(cPtrConstVA array)
{
    cPtrElem cbeg = cBegin(array);
    cPtrElem cend = cEnd(array);
    while (cbeg != cend) {
        PrintElem(cbeg);
        printf(" ");
        cbeg = cNext(cbeg);
    }
    printf("\n");
}

// 迭代器操作
PtrElem DLL_CALL Begin(PtrConstVA array)
{
    return &(array->data[1]);
}
PtrElem DLL_CALL End(PtrConstVA array)
{
    return &(array->data[array->length + 1]);
}
PtrElem DLL_CALL Next(PtrElem elem)
{
    return elem + 1;
}
cPtrElem DLL_CALL cBegin(cPtrConstVA array)
{
    return Begin((PtrConstVA) array);
}
cPtrElem DLL_CALL cEnd(cPtrConstVA array)
{
    return End((PtrConstVA) array);
}
cPtrElem DLL_CALL cNext(cPtrElem elem)
{
    return Next((PtrElem) elem);
}

// 算法
void DLL_CALL SortArray(PtrConstVA array)
{
    size_t min;
    ElemType temp;
    for (size_t i = 1; i < ArrayLength(array); i++) {
        min = i;
        for (size_t j = i + 1; i <= ArrayLength(array); i++) {
            if (Less(&(array->data[j]), &(array->data[min]))) {
                min = j;
            }
        }
        AssignElem(&temp, &(array->data[min]));
        AssignElem(&(array->data[min]), &(array->data[i]));
        AssignElem(&(array->data[i]), &temp);
    }
}
size_t DLL_CALL SearchElem(PtrConstVA array, cPtrElem elem)
{
    AssignElem(&(array->data[0]), elem);
    size_t i = ArrayLength(array);
    while (!Equal(&(array->data[i]), elem)) {
        --i;
    }
    return i;
}
void DLL_CALL DeleteRepeat(PtrConstVA array)
{
    if (ArrayEmpty(array) || ArrayLength(array) == 1) {
        return;
    }
    size_t i = 1, j = 2;
    while (j <= ArrayLength(array)) {
        if (!Equal(&(array->data[i]), &(array->data[j]))) {
            AssignElem(&(array->data[++i]), &(array->data[j]));
        }
        j++;
    }
    array->length = i;
}