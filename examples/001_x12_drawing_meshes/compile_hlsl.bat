"C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x64/fxc.exe" /Zi /Od /T vs_5_1 /E VSMain depthpass.hlsl /Fh depthpass.hlsl.vs.h
powershell -Command "(gc depthpass.hlsl.vs.h) -replace 'g_VSMain', 'g_DepthPassVSMain' | Out-File -encoding ASCII depthpass.hlsl.vs.h"

"C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x64/fxc.exe" /Zi /Od /T vs_5_1 /E VSMain scenepass.hlsl /Fh scenepass.hlsl.vs.h
powershell -Command "(gc scenepass.hlsl.vs.h) -replace 'g_VSMain', 'g_ScenePassVSMain' | Out-File -encoding ASCII scenepass.hlsl.vs.h"

"C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x64/fxc.exe" /Zi /Od /T ps_5_1 /E PSMain scenepass.hlsl /Fh scenepass.hlsl.ps.h
powershell -Command "(gc scenepass.hlsl.ps.h) -replace 'g_PSMain', 'g_ScenePassPSMain' | Out-File -encoding ASCII scenepass.hlsl.ps.h"
