#pragma once

#include <map>
#include <string>
#include <vector>

#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_WIN32
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3.h"
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3native.h"
#pragma comment(lib, "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/lib-vc2019/glfw3dll.lib")

#include "x12.h"

typedef union Generic64BitValue {
  int64_t  i;
  uint64_t u;
  double   d;
  void *   p;
} Generic64BitValue;

typedef struct GenericElement {
  Generic64BitValue        value;
  std::vector<double>      numbers;
  std::vector<std::string> strings;
} GenericElement;

__declspec(dllimport) std::map<std::string /*entry*/, std::map<std::string /*group*/, std::map<std::string /*label*/, GenericElement>>> globalCache;
__declspec(dllimport) std::map<std::string /*entry*/, std::map<std::string /*group*/, std::map<std::string /*label*/, GenericElement>>> globalStorage;

// NOTE(Constantine): The expected pattern for caching handles:
// void * handle = globalCache[CACHE_ENTRY][CACHE_GROUP][CACHE_LABEL].value.p;
// if (handle == 0) {
//   // Create and set handle here.
//   globalCache[CACHE_ENTRY][CACHE_GROUP][CACHE_LABEL].value.p = (void *)handle;
// }