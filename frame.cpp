#include "frame.h"

extern "C" __declspec(dllexport) int frame(int recompileRequested, void * dataFromMain) {
  int recompile = recompileRequested;
  
  // User code here
  
  return recompile;
}
