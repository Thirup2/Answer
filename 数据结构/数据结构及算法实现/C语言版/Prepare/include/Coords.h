#ifndef COORDS_H_
#define COORDS_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define COORDS_API _declspec(dllexport)
#else
#define COORDS_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define COORDS_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

// --------------------------- 包含头文件 --------------------------- //
#include <stdbool.h>

// ---------------------------    接口    --------------------------- //
// 类型定义
struct coords
{
    int x;
    int y;
};
typedef struct coords Coords;
typedef Coords *PtrCoords;
typedef const Coords *cPtrCoords;

// 函数接口
COORDS_API void DLL_CALL CopyCoords(PtrCoords elem, cPtrCoords copied);
COORDS_API bool DLL_CALL EqualCoords(cPtrCoords elem1, cPtrCoords elem2);
COORDS_API void DLL_CALL PrintCoords(cPtrCoords elem);
COORDS_API bool DLL_CALL ReadCoords(PtrCoords elem);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif