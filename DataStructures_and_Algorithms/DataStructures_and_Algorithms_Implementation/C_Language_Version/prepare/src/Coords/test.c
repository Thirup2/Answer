#include "Coords.h"
#include <stdio.h>

int main(void)
{
    PtrCoords co1 = GetCoords();
    PtrCoords co2 = GetCoords();
    if (ReadCoords(co1) && ReadCoords(co2)) {
        printf("Co1: "); PrintCoords(co1); printf("\n");
        printf("co2: "); PrintCoords(co2); printf("\n");
        if (EqualCoords(co1, co2)) {
            printf("co1 == co2\n");
        } else {
            printf("co1 != co2\n");
        }
        CopyCoords(co1, co2);
        printf("Now\n");
        printf("Co1: "); PrintCoords(co1); printf("\n");
        printf("co2: "); PrintCoords(co2); printf("\n");
        if (EqualCoords(co1, co2)) {
            printf("co1 == co2\n");
        } else {
            printf("co1 != co2\n");
        }
    } else {
        printf("Faild to read Coords\n");
        return 1;
    }
    DestroyCoords(co1);
    DestroyCoords(co2);

    return 0;
}