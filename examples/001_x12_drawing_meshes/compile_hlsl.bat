"C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x64/fxc.exe" /Zi /Od /T vs_5_1 /E VSMain depthpass.hlsl /Fh depthpass.hlsl.vs.h

"C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x64/fxc.exe" /Zi /Od /T vs_5_1 /E VSMain scenepass.hlsl /Fh scenepass.hlsl.vs.h
"C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x64/fxc.exe" /Zi /Od /T ps_5_1 /E PSMain scenepass.hlsl /Fh scenepass.hlsl.ps.h
