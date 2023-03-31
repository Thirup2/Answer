#include "Coordinate.h"
#include <stdio.h>

void ShowCoord(const char *name, cPtrCoord coord);

int main(void)
{
    PtrCoord coord1 = InitCoord();
    ReadCoord(coord1);
    ShowCoord("coord1", coord1);
    int x, y;
    scanf("%d, %d", &x, &y);
    PtrCoord coord2 = CreateCoord(x, y);
    ShowCoord("coord2", coord2);
    PtrCoord coord3 = CopyCoord(coord1);
    ShowCoord("coord3", coord3);
    AssignCoordByCopy(coord3, coord2);
    ShowCoord("coord3", coord3);
    if (CompareCoords(coord1, coord2)) {
        printf("%s == %s\n", "coord1", "coord2");
    }
    if (CompareCoords(coord1, coord3)) {
        printf("%s == %s\n", "coord1", "coord3");
    }
    if (CompareCoords(coord2, coord3)) {
        printf("%s == %s\n", "coord2", "coord3");
    }
    DestroyCoord(coord1);
    DestroyCoord(coord2);
    DestroyCoord(coord3);

    return 0;
}

void ShowCoord(const char *name, cPtrCoord coord)
{
    printf("%s = %s\n", name, CoordToString(coord));
}