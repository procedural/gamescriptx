#include "frame.h"

extern "C" __declspec(dllexport) int frame(int recompileRequested, void * dataFromMain) {
  int recompile = recompileRequested;
  
  // User code here
  
  if (recompile == 1) {
    for (auto & pair : globalCache[""]["SomeHandleType"]) {
      void * handle = pair.second.value.p;
      // Destroy the handle here
    }
    // More for loops as above for other handle types here
  }
  return recompile;
}
