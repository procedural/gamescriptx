#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_WIN32
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3.h"
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3native.h"
#pragma comment(lib, "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/lib-vc2019/glfw3dll.lib")

#include <map>
#include <string>
#include <vector>
#include <stdio.h>

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

// Globals begin

static int     (*frame)(int recompileRequested, void * dataFromMain) = 0;
static int     gRecompileRequested = 0;
static HMODULE gFrameDll           = 0;

__declspec(dllexport) std::map<std::string /*entry*/, std::map<std::string /*group*/, std::map<std::string /*label*/, GenericElement>>> globalCache;
__declspec(dllexport) std::map<std::string /*entry*/, std::map<std::string /*group*/, std::map<std::string /*label*/, GenericElement>>> globalStorage;

// Globals end

static std::string systemCommandExecute(std::string command) {
  FILE * cfd = _popen(command.c_str(), "r");
  std::string out;
  {
    int c = fgetc(cfd);
    while (c != EOF) {
      out += c;
      c = fgetc(cfd);
    }
    _pclose(cfd);
  }
  return out;
}

static void recompileDll(void * x12DebugContext) {
  {
    // TODO(Constantine): Serialize the global storage to disk and allow to load it by dragging-and-dropping it onto a Game Script X window.
  }
  {
    // NOTE(Constantine): Destroy all X12 handles here by iterating over all cache entries and cache handle type groups, assuming the user has finished all the threads in the frame procedure on receiving a recompile request.
    for (auto & entryPair : globalCache) {
      std::map<std::string, GenericElement> factories                  = entryPair.second["X12Factory4"];
      std::map<std::string, GenericElement> adapters                   = entryPair.second["X12Adapter3"];
      std::map<std::string, GenericElement> devices                    = entryPair.second["X12Device3"];
      std::map<std::string, GenericElement> heaps                      = entryPair.second["X12Heap"];
      std::map<std::string, GenericElement> resources                  = entryPair.second["X12Resource"];
      std::map<std::string, GenericElement> descriptorHeaps            = entryPair.second["X12DescriptorHeap"];
      std::map<std::string, GenericElement> blobs                      = entryPair.second["X12Blob"];
      std::map<std::string, GenericElement> rootSignatures             = entryPair.second["X12RootSignature"];
      std::map<std::string, GenericElement> rootSignatureDeserializers = entryPair.second["X12RootSignatureDeserializer"];
      std::map<std::string, GenericElement> pipelineStates             = entryPair.second["X12PipelineState"];
      std::map<std::string, GenericElement> fences                     = entryPair.second["X12Fence"];
      std::map<std::string, GenericElement> commandQueues              = entryPair.second["X12CommandQueue"];
      std::map<std::string, GenericElement> commandAllocators          = entryPair.second["X12CommandAllocator"];
      std::map<std::string, GenericElement> commandLists               = entryPair.second["X12CommandList"];
      std::map<std::string, GenericElement> swapChains                 = entryPair.second["X12SwapChain3"];
      std::map<std::string, GenericElement> outputs                    = entryPair.second["X12Output4"];
      for (auto & pair : fences) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : commandLists) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : commandAllocators) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : pipelineStates) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : rootSignatureDeserializers) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : rootSignatures) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : blobs) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : descriptorHeaps) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : resources) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : heaps) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : outputs) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : swapChains) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : commandQueues) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : devices) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : adapters) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
      for (auto & pair : factories) {
        void * handle = pair.second.value.p;
        x12Release(handle, __FILE__, __LINE__);
      }
    }
  }
  if (x12DebugContext != 0) {
    x12DebugReport(x12DebugContext, __FILE__, __LINE__);
  }
  globalCache = {};
  frame = 0;
  if (gFrameDll != 0) {
    FreeLibrary(gFrameDll);
    gFrameDll = 0;
  }
  std::string executeOutput = systemCommandExecute("compile_dll.bat");
  printf("%s\n", executeOutput.c_str());
  gFrameDll = LoadLibraryA("gamescriptx_frame.dll");
  if (gFrameDll != 0) {
    frame = (int (*)(int, void *))GetProcAddress(gFrameDll, "frame");
  }
}

static void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_F5 && action == GLFW_PRESS) {
    gRecompileRequested = 1;
  }
}

int main() {
  // NOTE(Constantine): WIP.
  
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  GLFWwindow * window = glfwCreateWindow(1800, 900, "Game Script X", NULL, NULL);
  glfwSetKeyCallback(window, keyCallback);
  
  // NOTE(Constantine): To see X12 debug output, run DebugView program.
  void * x12DebugContext = x12DebugEnable(__FILE__, __LINE__);
  
  while (glfwWindowShouldClose(window) == 0) {
    glfwPollEvents();
    int recompile = frame == 0 ? gRecompileRequested : 0;
    if (frame != 0) {
      recompile = frame(gRecompileRequested, (void *)window);
    }
    gRecompileRequested = 0;
    if (recompile == 1) {
      recompileDll(x12DebugContext);
    }
  }
}

#undef min
#include "backward.cpp"
