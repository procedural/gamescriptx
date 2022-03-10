clang++.exe -g -O0 -std=c++14 -Wno-microsoft-cast main.cpp x12dll.lib -lshell32 -lole32 -o gamescriptx.exe
xcopy /y C:\github\glfw\glfw\glfw-3.3.6.bin.WIN64\lib-vc2019\glfw3.dll