#ifndef COORDINATE_H_
#define COORDINATE_H_

// ----------------------包含头文件---------------------- //
#include <stdbool.h>

// ----------------------兼容配置---------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define COORD_API _declspec(dllexport)
#else
#define COORD_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define COORD_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

// ----------------------接口---------------------- //

// 数据类型定义
struct coordinate
{
    int x;
    int y;
};
typedef struct coordinate Coordinate;
typedef Coordinate *PtrCoord;
typedef const Coordinate *cPtrCoord;

// 坐标类型函数接口

/*
 * 操作：构造对象
*/
COORD_API PtrCoord DLL_CALL InitCoord(void);
COORD_API PtrCoord DLL_CALL CreateCoord(int x, int y);
COORD_API PtrCoord DLL_CALL CopyCoord(cPtrCoord coord);

/*
 * 操作：销毁对象
*/
COORD_API void DLL_CALL DestroyCoord(PtrCoord coord);

/*
 * 操作：赋值操作
*/
COORD_API void DLL_CALL AssignCoordByValue(PtrCoord coord, int x, int y);
COORD_API void DLL_CALL AssignCoordByCopy(PtrCoord coord, cPtrCoord copycoord);

/*
 * 操作：读写一个坐标对象
*/
COORD_API bool DLL_CALL ReadCoord(PtrCoord coord);
COORD_API void DLL_CALL PrintCoord(cPtrCoord coord);

/*
 * 操作：相等性判断
 * 参数：两个指针
 * 返回：bool 值
*/
COORD_API bool DLL_CALL Equals(cPtrCoord cor1, cPtrCoord cor2);
COORD_API bool DLL_CALL Nequal(cPtrCoord cor1, cPtrCoord cor2);

/*
 * 操作：比较操作
 * 参数：两个指针
 * 返回：bool 值
*/
COORD_API bool DLL_CALL Less(cPtrCoord cor1, cPtrCoord cor2);
COORD_API bool DLL_CALL Lequal(cPtrCoord cor1, cPtrCoord cor2);
COORD_API bool DLL_CALL Greater(cPtrCoord cor1, cPtrCoord cor2);
COORD_API bool DLL_CALL Gequal(cPtrCoord cor1, cPtrCoord cor2);

// ----------------------兼容配置---------------------- //
#ifdef __cplusplus
}
#endif

#endif