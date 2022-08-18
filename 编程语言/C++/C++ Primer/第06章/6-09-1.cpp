/* fact.cc */
#include "6-08.h"
int fact(int i)
{
    while (i > 2) {
        return i * fact(i - 1);
    }
    return i;
}