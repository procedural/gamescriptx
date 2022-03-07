#include <map>
#include <string>

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

extern "C" int frame(int recompileRequested, void * dataFromMain) {
  int recompile = recompileRequested;
  
  // User code here
  
  if (recompile == 1) {
    for (auto & pair : globalEntryGroupKey["handle"]["SomeHandleType"]) {
      void * handle = pair.second.p;
      // Destroy the handle here
    }
    // More for loops as above for other handle types here
  }
  return recompile;
}
