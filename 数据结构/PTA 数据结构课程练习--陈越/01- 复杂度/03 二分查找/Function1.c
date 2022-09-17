#include "Problem.h"

Position BinarySearch(List L, ElementType X)
{
    Position front = 1;
    Position rear = L->Last;
    Position mid;
    while (front <= rear) {
        mid = (front + rear) / 2;
        if (L->Data[mid] == X) {
            return mid;
        } else if (L->Data[mid] > X) {
            rear = mid - 1;
        } else {
            front = mid + 1;
        }
    }
    return NotFound;
}