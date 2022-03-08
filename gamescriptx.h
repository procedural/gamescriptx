#pragma once

#include <map>
#include <string>

#include "x12.h"

typedef union Generic64BitValue {
  int64_t  i;
  uint64_t u;
  double   d;
  void *   p;
} Generic64BitValue;

__declspec(dllimport) std::map<std::string, std::map<std::string, std::map<std::string, Generic64BitValue>>> globalEntryGroupKey;

#define gsxCreateHandle(HANDLE_TYPE, HANDLE_NAME, CREATE_HANDLE_PROCEDURE_CALL) \
  if (globalEntryGroupKey["handle"][HANDLE_TYPE][HANDLE_NAME].p == 0) { \
    globalEntryGroupKey["handle"][HANDLE_TYPE][HANDLE_NAME].p = (void *)CREATE_HANDLE_PROCEDURE_CALL; \
  }