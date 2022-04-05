call compile_hlsl.bat
del gamescriptx_frame.dll
if 0 == 1 (
  :: Debug
  clang++.exe -g -O0 -shared -x c frame.c -LC:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/lib-vc2019/ -lglfw3dll -L. -lgamescriptx -lx12dll -o gamescriptx_frame.dll
) else (
  :: Release
  tcc.exe -O2 -shared frame.c -LC:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/lib-vc2019/ -lglfw3 -L. gamescriptx.exe -lx12 -o gamescriptx_frame.dll
)