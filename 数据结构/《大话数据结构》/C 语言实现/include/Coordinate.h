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
 * 操作：创建一个空坐标对象
 * 返回：对象的指针
*/
COORD_API PtrCoord DLL_CALL InitCoord(void);

/*
 * 操作：创建一个指定值的坐标对象
 * 参数：坐标的值
 * 返回：对象的指针
*/
COORD_API PtrCoord DLL_CALL CreateCoord(int x, int y);

/*
 * 操作：创建一个拷贝的坐标对象
 * 参数：被拷贝对象
 * 返回：对象的指针
*/
COORD_API PtrCoord DLL_CALL CopyCoord(cPtrCoord coord);

/*
 * 操作：销毁一个坐标对象
 * 参数：被销毁对象指针
*/
COORD_API void DLL_CALL DestroyCoord(PtrCoord coord);

/*
 * 操作：修改指定坐标对象的值
 * 参数：
 * 1. 被指定对象
 * 2. 指定值
*/
COORD_API void DLL_CALL AssignCoordByValue(PtrCoord coord, int x, int y);

/*
 * 操作：拷贝指定坐标对象的值
 * 参数：
 * 1. 被修改对象
 * 2. 被拷贝对象
*/
COORD_API void DLL_CALL AssignCoordByCopy(PtrCoord coord, cPtrCoord copycoord);

/*
 * 操作：将坐标转换为字符串
 * 参数：坐标对象
 * 返回：被转换成的字符串
*/
COORD_API const char * DLL_CALL CoordToString(cPtrCoord coord);

/*
 * 操作：比较两个坐标对象是否相等
 * 参数：两个坐标对象
 * 返回：
 * 1. 若相等返回 true
 * 2. 否则返回 false
*/
COORD_API bool DLL_CALL CompareCoords(cPtrCoord coord1, cPtrCoord coord2);

/*
 * 操作：读入一个坐标对象
 * 参数：需要读入的对象
 * 返回：
 * 1. 若读入成功返回 true
 * 2. 否则返回 false
*/
COORD_API bool DLL_CALL ReadCoord(PtrCoord coord);

/*
 * 操作：打印一个坐标
 * 参数：坐标对象
*/
COORD_API void DLL_CALL PrintCoord(cPtrCoord coord);

// ----------------------兼容配置---------------------- //
#ifdef __cplusplus
}
#endif

#endif