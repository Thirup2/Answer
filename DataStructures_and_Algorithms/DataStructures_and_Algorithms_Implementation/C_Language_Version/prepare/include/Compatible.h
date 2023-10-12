#ifndef COMPATIBLE_H_
#define COMPATIBLE_H_

#ifdef _MSC_VER
#ifdef EXPORT
#define DLL_API _declspec(dllexport)
#else
#define DLL_API _declspec(dllimport)
#endif // EXPORT
#else
#define DLL_API
#endif // _MSC_VER

#endif