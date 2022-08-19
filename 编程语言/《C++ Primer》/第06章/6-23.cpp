#include "head.h"
void print(const char *cp)
{
    if (cp) {
        while (*cp) {
            cout << *cp++;
        }
    }
}
void print(const int *beg, const int *end)
{
    while (beg != end) {
        cout << *beg++;
    }
}
void print(const int ia[], size_t size)
{
    for (int i = 0; i < size; i++) {
        cout << ia[i];
    }
}