#include "head.h"
int retlow(int a, int *p)
{
    return a > *p ? a : *p;
}