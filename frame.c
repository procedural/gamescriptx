#include "frame.h"

#ifdef __cplusplus
extern "C"
#endif
__declspec(dllexport) int frame(int recompileRequested, void * dataFromMain) {
  int recompile = recompileRequested;
  
  // User code here
  
  return recompile;
}
