#include <map>
#include <string>
#include <vector>
#include <stdio.h> // For printf

#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_WIN32
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3.h"
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3native.h"
#pragma comment(lib, "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/lib-vc2019/glfw3dll.lib")

#include "x12.h"

// NOTE(Constantine): See WinPixEventRuntime links in README.md.
#define USE_PIX
#include "include/WinPixEventRuntime/pix3.h"
#pragma comment(lib, "bin/x64/WinPixEventRuntime.lib")

typedef union Generic64BitValue {
  int64_t  i;
  uint64_t u;
  double   d;
  void *   p;
} Generic64BitValue;

typedef struct GenericElement {
  Generic64BitValue              value;
  std::vector<Generic64BitValue> numbers;
  std::vector<std::wstring>      strings;
} GenericElement;

// Globals begin

static int      (*frame)(int recompileRequested, void * dataFromMain) = 0;
static int      gRecompileRequested = 0;
static int      gPixCaptureToggle   = 0;
static uint64_t gPixCaptureCounter  = 0;
static HMODULE  gFrameDll           = 0;

std::map<std::wstring /*entry*/, std::map<std::wstring /*group*/, std::map<std::wstring /*label*/, GenericElement>>> globalCache;
std::map<std::wstring /*entry*/, std::map<std::wstring /*group*/, std::map<std::wstring /*label*/, GenericElement>>> globalStorage;

// Globals end

extern "C" __declspec(dllexport) int64_t globalCacheGetAsI(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].value.i;
}

extern "C" __declspec(dllexport) uint64_t globalCacheGetAsU(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].value.u;
}

extern "C" __declspec(dllexport) double globalCacheGetAsD(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].value.d;
}

extern "C" __declspec(dllexport) void * globalCacheGetAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].value.p;
}

extern "C" __declspec(dllexport) void globalCacheSetAsI(const wchar_t * entry, const wchar_t * group, const wchar_t * label, int64_t value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalCache[_entry][_group][_label].value.i = value;
}

extern "C" __declspec(dllexport) void globalCacheSetAsU(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalCache[_entry][_group][_label].value.u = value;
}

extern "C" __declspec(dllexport) void globalCacheSetAsD(const wchar_t * entry, const wchar_t * group, const wchar_t * label, double value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalCache[_entry][_group][_label].value.d = value;
}

extern "C" __declspec(dllexport) void globalCacheSetAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label, void * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalCache[_entry][_group][_label].value.p = value;
}

extern "C" __declspec(dllexport) double globalCacheNumbersGet(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].numbers[index].d;
}

extern "C" __declspec(dllexport) void * globalCacheNumbersGetAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].numbers[index].p;
}

extern "C" __declspec(dllexport) void globalCacheNumbersSet(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, double value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalCache[_entry][_group][_label].numbers[index].d = value;
}

extern "C" __declspec(dllexport) void globalCacheNumbersSetAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, void * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalCache[_entry][_group][_label].numbers[index].p = value;
}

extern "C" __declspec(dllexport) size_t globalCacheNumbersGetSize(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].numbers.size();
}

extern "C" __declspec(dllexport) void globalCacheNumbersPushBack(const wchar_t * entry, const wchar_t * group, const wchar_t * label, double value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  Generic64BitValue _value;
  _value.d = value;
  globalCache[_entry][_group][_label].numbers.push_back(_value);
}

extern "C" __declspec(dllexport) void globalCacheNumbersPushBackAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label, void * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  Generic64BitValue _value;
  _value.p = value;
  globalCache[_entry][_group][_label].numbers.push_back(_value);
}

extern "C" __declspec(dllexport) void globalCacheNumbersPopBack(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalCache[_entry][_group][_label].numbers.pop_back();
}

extern "C" __declspec(dllexport) int globalCacheNumbersErase(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  int output = globalCache[_entry][_group][_label].numbers.erase(globalCache[_entry][_group][_label].numbers.begin() + index) != globalCache[_entry][_group][_label].numbers.end() ? 1 : 0;
  return output;
}

extern "C" __declspec(dllexport) const wchar_t * globalCacheStringsGet(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].strings[index].c_str();
}

extern "C" __declspec(dllexport) void globalCacheStringsSet(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, const wchar_t * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  std::wstring _value = value;
  globalCache[_entry][_group][_label].strings[index] = _value;
}

extern "C" __declspec(dllexport) size_t globalCacheStringsGetSize(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalCache[_entry][_group][_label].strings.size();
}

extern "C" __declspec(dllexport) void globalCacheStringsPushBack(const wchar_t * entry, const wchar_t * group, const wchar_t * label, const wchar_t * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  std::wstring _value = value;
  globalCache[_entry][_group][_label].strings.push_back(_value);
}

extern "C" __declspec(dllexport) void globalCacheStringsPopBack(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalCache[_entry][_group][_label].strings.pop_back();
}

extern "C" __declspec(dllexport) int globalCacheStringsErase(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  int output = globalCache[_entry][_group][_label].strings.erase(globalCache[_entry][_group][_label].strings.begin() + index) != globalCache[_entry][_group][_label].strings.end() ? 1 : 0;
  return output;
}

extern "C" __declspec(dllexport) int64_t globalStorageGetAsI(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].value.i;
}

extern "C" __declspec(dllexport) uint64_t globalStorageGetAsU(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].value.u;
}

extern "C" __declspec(dllexport) double globalStorageGetAsD(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].value.d;
}

extern "C" __declspec(dllexport) void * globalStorageGetAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].value.p;
}

extern "C" __declspec(dllexport) void globalStorageSetAsI(const wchar_t * entry, const wchar_t * group, const wchar_t * label, int64_t value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalStorage[_entry][_group][_label].value.i = value;
}

extern "C" __declspec(dllexport) void globalStorageSetAsU(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalStorage[_entry][_group][_label].value.u = value;
}

extern "C" __declspec(dllexport) void globalStorageSetAsD(const wchar_t * entry, const wchar_t * group, const wchar_t * label, double value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalStorage[_entry][_group][_label].value.d = value;
}

extern "C" __declspec(dllexport) void globalStorageSetAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label, void * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalStorage[_entry][_group][_label].value.p = value;
}

extern "C" __declspec(dllexport) double globalStorageNumbersGet(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].numbers[index].d;
}

extern "C" __declspec(dllexport) void * globalStorageNumbersGetAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].numbers[index].p;
}

extern "C" __declspec(dllexport) void globalStorageNumbersSet(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, double value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalStorage[_entry][_group][_label].numbers[index].d = value;
}

extern "C" __declspec(dllexport) void globalStorageNumbersSetAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, void * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalStorage[_entry][_group][_label].numbers[index].p = value;
}

extern "C" __declspec(dllexport) size_t globalStorageNumbersGetSize(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].numbers.size();
}

extern "C" __declspec(dllexport) void globalStorageNumbersPushBack(const wchar_t * entry, const wchar_t * group, const wchar_t * label, double value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  Generic64BitValue _value;
  _value.d = value;
  globalStorage[_entry][_group][_label].numbers.push_back(_value);
}

extern "C" __declspec(dllexport) void globalStorageNumbersPushBackAsP(const wchar_t * entry, const wchar_t * group, const wchar_t * label, void * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  Generic64BitValue _value;
  _value.p = value;
  globalStorage[_entry][_group][_label].numbers.push_back(_value);
}

extern "C" __declspec(dllexport) void globalStorageNumbersPopBack(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalStorage[_entry][_group][_label].numbers.pop_back();
}

extern "C" __declspec(dllexport) int globalStorageNumbersErase(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  int output = globalStorage[_entry][_group][_label].numbers.erase(globalStorage[_entry][_group][_label].numbers.begin() + index) != globalStorage[_entry][_group][_label].numbers.end() ? 1 : 0;
  return output;
}

extern "C" __declspec(dllexport) const wchar_t * globalStorageStringsGet(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].strings[index].c_str();
}

extern "C" __declspec(dllexport) void globalStorageStringsSet(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index, const wchar_t * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  std::wstring _value = value;
  globalStorage[_entry][_group][_label].strings[index] = _value;
}

extern "C" __declspec(dllexport) size_t globalStorageStringsGetSize(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  return globalStorage[_entry][_group][_label].strings.size();
}

extern "C" __declspec(dllexport) void globalStorageStringsPushBack(const wchar_t * entry, const wchar_t * group, const wchar_t * label, const wchar_t * value) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  std::wstring _value = value;
  globalStorage[_entry][_group][_label].strings.push_back(_value);
}

extern "C" __declspec(dllexport) void globalStorageStringsPopBack(const wchar_t * entry, const wchar_t * group, const wchar_t * label) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  globalStorage[_entry][_group][_label].strings.pop_back();
}

extern "C" __declspec(dllexport) int globalStorageStringsErase(const wchar_t * entry, const wchar_t * group, const wchar_t * label, uint64_t index) {
  std::wstring _entry = entry;
  std::wstring _group = group;
  std::wstring _label = label;
  int output = globalStorage[_entry][_group][_label].strings.erase(globalStorage[_entry][_group][_label].strings.begin() + index) != globalStorage[_entry][_group][_label].strings.end() ? 1 : 0;
  return output;
}

extern "C" __declspec(dllexport) const wchar_t * wstrjoin(const wchar_t * globalCacheEntry, const wchar_t * a, const wchar_t * b) {
  std::wstring _entry = globalCacheEntry;
  std::wstring _a = a;
  std::wstring _b = b;
  std::wstring * _c = new(std::nothrow) std::wstring();
  if (_c == 0) {
    return 0;
  }
  _c[0] = _a + _b;
  Generic64BitValue _value;
  _value.p = (void *)_c;
  globalCache[_entry][L"wstrjoin"][L""].numbers.push_back(_value);
  const wchar_t * _cstr = _c->c_str();
  return _cstr;
}

extern "C" __declspec(dllexport) void wstrjoinClearCache(const wchar_t * globalCacheEntry) {
  std::wstring _entry = globalCacheEntry;
  std::vector<Generic64BitValue> numbers = globalCache[_entry][L"wstrjoin"][L""].numbers;
  for (auto & number : numbers) {
    std::wstring * pointer = (std::wstring *)number.p;
    delete pointer;
  }
  globalCache[_entry][L"wstrjoin"][L""].numbers = {};
}

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
    // NOTE(Constantine): Destroy all X12 handles here by iterating over all cache entries and cache handle type groups.
    for (auto & entryPair : globalCache) {
      std::map<std::wstring, GenericElement> factories                  = entryPair.second[L"X12Factory4"];
      std::map<std::wstring, GenericElement> adapters                   = entryPair.second[L"X12Adapter3"];
      std::map<std::wstring, GenericElement> devices                    = entryPair.second[L"X12Device3"];
      std::map<std::wstring, GenericElement> heaps                      = entryPair.second[L"X12Heap"];
      std::map<std::wstring, GenericElement> resources                  = entryPair.second[L"X12Resource"];
      std::map<std::wstring, GenericElement> descriptorHeaps            = entryPair.second[L"X12DescriptorHeap"];
      std::map<std::wstring, GenericElement> blobs                      = entryPair.second[L"X12Blob"];
      std::map<std::wstring, GenericElement> rootSignatures             = entryPair.second[L"X12RootSignature"];
      std::map<std::wstring, GenericElement> rootSignatureDeserializers = entryPair.second[L"X12RootSignatureDeserializer"];
      std::map<std::wstring, GenericElement> pipelineStates             = entryPair.second[L"X12PipelineState"];
      std::map<std::wstring, GenericElement> fences                     = entryPair.second[L"X12Fence"];
      std::map<std::wstring, GenericElement> commandQueues              = entryPair.second[L"X12CommandQueue"];
      std::map<std::wstring, GenericElement> commandAllocators          = entryPair.second[L"X12CommandAllocator"];
      std::map<std::wstring, GenericElement> commandLists               = entryPair.second[L"X12CommandList"];
      std::map<std::wstring, GenericElement> swapChains                 = entryPair.second[L"X12SwapChain3"];
      std::map<std::wstring, GenericElement> outputs                    = entryPair.second[L"X12Output4"];
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
  {
    // NOTE(Constantine): Delete all wstrjoin leftovers.
    for (auto & entryPair : globalCache) {
      std::vector<Generic64BitValue> numbers = entryPair.second[L"wstrjoin"][L""].numbers;
      for (auto & number : numbers) {
        std::wstring * pointer = (std::wstring *)number.p;
        delete pointer;
      }
    }
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
  } else if (key == GLFW_KEY_F6 && action == GLFW_PRESS) {
    if (gPixCaptureToggle == 0) {
      std::wstring filename = L"pixcapture_" + std::to_wstring(gPixCaptureCounter) + L".wpix";
      PIXCaptureParameters pixCaptureParameters = {};
      pixCaptureParameters.GpuCaptureParameters.FileName = filename.c_str();
      PIXBeginCapture(PIX_CAPTURE_GPU, &pixCaptureParameters);
      gPixCaptureCounter += 1;
      gPixCaptureToggle = 1;
    } else {
      PIXEndCapture(true);
      gPixCaptureToggle = 0;
    }
  }
}

int main() {
  // NOTE(Constantine): WIP.
  
  PIXLoadLatestWinPixGpuCapturerLibrary();
  
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
      // NOTE(Constantine): Assuming the user has finished all the threads in the frame procedure on receiving a recompile request.
      recompileDll(x12DebugContext);
    }
  }
}

#undef min
#include "backward.cpp"
