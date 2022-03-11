# Game Script X

## WinPixEventRuntime (for `pix3.h`)

https://www.nuget.org/api/v2/package/WinPixEventRuntime/

https://devblogs.microsoft.com/pix/winpixeventruntime/

https://devblogs.microsoft.com/pix/programmatic-capture/

## PIX on Windows

* PIX timeline sometimes doesn't show anything after an analysis, right click on the timeline -> Refresh fixes this.

* Debugging shader code: compile HLSL files with [`/Zi /Od` flags](https://docs.microsoft.com/en-us/windows/win32/direct3dtools/dx-graphics-tools-fxc-syntax), open a PIX capture, in the Pipeline tab click on a draw call, in another Pipeline tab below click on a OM RTV, pick a pixel, right click -> Show Pixel History, right click on a Draw row you want -> Debug This Pixel.

![](https://user-images.githubusercontent.com/28234322/157758974-8a83a37e-3b22-40f6-b3e0-5fe2cd4ed303.png)
