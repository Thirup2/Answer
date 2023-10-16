#ifndef ELEMTYPE_H_
#define ELEMTYPE_H_

#ifdef STRING_H_
#include ""
#else
#include "Coords.h"
typedef Coords ElemType;
typedef PtrCoords PtrElem;
#define CreateElem CreateCoords
#define MakeElem MakeCoords
#define DestroyElem DestroyCoords
#define CopyElems CopyCoords
#define EqualElems EqualCoords
#define PrintElem PrintCoords
#define ReadElem ReadCoords
#endif

#endif