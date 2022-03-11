del gamescriptx_frame.dll
tcc.exe -g -O0 -shared frame.c -LC:/github/glfw/glfw/glfw-3.3.6.bin.WIN64/lib-vc2019/ -lglfw3 -L. gamescriptx.exe -lx12 -o gamescriptx_frame.dll