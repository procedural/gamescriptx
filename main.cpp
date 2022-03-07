#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_WIN32
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3.h"
#include "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/include/GLFW/glfw3native.h"
#pragma comment(lib, "C:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/lib-vc2019/glfw3.lib")

#include <map>
#include <string>

typedef union Generic64BitValue {
  int64_t  i;
  uint64_t u;
  double   d;
  void *   p;
} Generic64BitValue;

// Globals begin

static int gRecompileRequested = 0;

__declspec(dllexport) std::map<std::string, std::map<std::string, std::map<std::string, Generic64BitValue>>> globalEntryGroupKey;

// Globals end

static void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_F5 && action == GLFW_PRESS) {
    gRecompileRequested = 1;
  }
}

// TODO(Constantine): Just a test, remove later.
extern "C" int frame(int recompileRequested, void * dataFromMain);

int main() {
  // NOTE(Constantine): WIP.
  
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  GLFWwindow * window = glfwCreateWindow(1800, 900, "Game Script X", NULL, NULL);
  glfwSetKeyCallback(window, keyCallback);
  
  while (glfwWindowShouldClose(window) == 0) {
    glfwPollEvents();
    int recompile = frame(gRecompileRequested, (void *)window);
    gRecompileRequested = 0;
    if (recompile == 1) {
      // TBD
    }
  }
}