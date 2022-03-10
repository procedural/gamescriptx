#pragma once

#include <map>
#include <string>
#include <vector>

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
// if (globalCache[CACHE_ENTRY][CACHE_GROUP][CACHE_LABEL].value.p == 0) {
//   void * handle = createHandle(...);
//   globalCache[CACHE_ENTRY][CACHE_GROUP][CACHE_LABEL].value.p = (void *)handle;
// }
// void * handle = globalCache[CACHE_ENTRY][CACHE_GROUP][CACHE_LABEL].value.p;