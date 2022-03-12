#pragma once

#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_WIN32
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3.h"
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3native.h"

#include "x12.h"

#ifndef _countof
#define _countof(x) (sizeof(x) / sizeof((x)[0]))
#endif

#ifdef __cplusplus
extern "C" {
#endif

int64_t         globalCacheGetAsI               (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
uint64_t        globalCacheGetAsU               (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
double          globalCacheGetAsD               (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
void *          globalCacheGetAsP               (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
void            globalCacheSetAsI               (const wchar_t * entry, const wchar_t * group, const wchar_t * label, int64_t value);
void            globalCacheSetAsU               (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t value);
void            globalCacheSetAsD               (const wchar_t * entry, const wchar_t * group, const wchar_t * label, double value);
void            globalCacheSetAsP               (const wchar_t * entry, const wchar_t * group, const wchar_t * label, void * value);

double          globalCacheNumbersGet           (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);
void *          globalCacheNumbersGetAsP        (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);
void            globalCacheNumbersSet           (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, double value);
void            globalCacheNumbersSetAsP        (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, void * value);
size_t          globalCacheNumbersGetSize       (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
void            globalCacheNumbersPushBack      (const wchar_t * entry, const wchar_t * group, const wchar_t * label, double value);
void            globalCacheNumbersPushBackAsP   (const wchar_t * entry, const wchar_t * group, const wchar_t * label, void * value);
void            globalCacheNumbersPopBack       (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
int             globalCacheNumbersErase         (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);

const wchar_t * globalCacheStringsGet           (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);
void            globalCacheStringsSet           (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, const wchar_t * value);
size_t          globalCacheStringsGetSize       (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
void            globalCacheStringsPushBack      (const wchar_t * entry, const wchar_t * group, const wchar_t * label, const wchar_t * value);
void            globalCacheStringsPopBack       (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
int             globalCacheStringsErase         (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);

int64_t         globalStorageGetAsI             (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
uint64_t        globalStorageGetAsU             (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
double          globalStorageGetAsD             (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
void *          globalStorageGetAsP             (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
void            globalStorageSetAsI             (const wchar_t * entry, const wchar_t * group, const wchar_t * label, int64_t value);
void            globalStorageSetAsU             (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t value);
void            globalStorageSetAsD             (const wchar_t * entry, const wchar_t * group, const wchar_t * label, double value);
void            globalStorageSetAsP             (const wchar_t * entry, const wchar_t * group, const wchar_t * label, void * value);

double          globalStorageNumbersGet         (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);
void *          globalStorageNumbersGetAsP      (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);
void            globalStorageNumbersSet         (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, double value);
void            globalStorageNumbersSetAsP      (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, void * value);
size_t          globalStorageNumbersGetSize     (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
void            globalStorageNumbersPushBack    (const wchar_t * entry, const wchar_t * group, const wchar_t * label, double value);
void            globalStorageNumbersPushBackAsP (const wchar_t * entry, const wchar_t * group, const wchar_t * label, void * value);
void            globalStorageNumbersPopBack     (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
int             globalStorageNumbersErase       (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);

const wchar_t * globalStorageStringsGet         (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);
void            globalStorageStringsSet         (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, const wchar_t * value);
size_t          globalStorageStringsGetSize     (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
void            globalStorageStringsPushBack    (const wchar_t * entry, const wchar_t * group, const wchar_t * label, const wchar_t * value);
void            globalStorageStringsPopBack     (const wchar_t * entry, const wchar_t * group, const wchar_t * label);
int             globalStorageStringsErase       (const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index);

const wchar_t * wstrjoin                        (const wchar_t * globalCacheEntry, const wchar_t * a, const wchar_t * b);
void            wstrjoinClearCache              (const wchar_t * globalCacheEntry);

#ifdef __cplusplus
}
#endif

// NOTE(Constantine): The expected pattern for caching handles:
// void * handle = globalCacheGetAsP(CACHE_ENTRY, CACHE_GROUP, CACHE_LABEL);
// if (handle == 0) {
//   // Create and set handle here.
//   globalCacheSetAsP(CACHE_ENTRY, CACHE_GROUP, CACHE_LABEL, (void *)handle);
// }