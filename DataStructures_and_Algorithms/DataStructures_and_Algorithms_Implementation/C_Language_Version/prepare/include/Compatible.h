#ifndef COMPATIBLE_H_
#define COMPATIBLE_H_

// 如果使用 Windows 方式编译程序（一般是使用 Visual Studio 进行构建的方式）
// 则将下方所有注释掉的预处理语句取消注释

//#ifdef _WIN32
//
//#ifdef EXPORT
//#define DLL_API _declspec(dllexport)
//#else
//#define DLL_API _declspec(dllimport)
//#endif
//
//#else

#define DLL_API

//#endif

#endif