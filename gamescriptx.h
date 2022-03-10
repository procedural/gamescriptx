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

__declspec(dllimport) std::map<std::string, std::map<std::string, std::map<std::string, GenericElement>>> globalEntryGroupLabel;

#define gsxCacheHandle(CACHE_GROUP, CACHE_LABEL, CACHE_HANDLE_VALUE) \
  if (globalEntryGroupLabel["cache"][CACHE_GROUP][CACHE_LABEL].value.p == 0) { \
    globalEntryGroupLabel["cache"][CACHE_GROUP][CACHE_LABEL].value.p = (void *)(CACHE_HANDLE_VALUE); \
  }