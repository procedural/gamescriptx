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

__declspec(dllimport) std::map<std::string, std::map<std::string, std::map<std::string, GenericElement>>> globalEntryGroupKey;

#define gsxCreateHandle(HANDLE_TYPE, HANDLE_NAME, CREATE_HANDLE_PROCEDURE_CALL) \
  if (globalEntryGroupKey["handle"][HANDLE_TYPE][HANDLE_NAME].value.p == 0) { \
    globalEntryGroupKey["handle"][HANDLE_TYPE][HANDLE_NAME].value.p = (void *)CREATE_HANDLE_PROCEDURE_CALL; \
  }