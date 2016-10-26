#ifndef PLATFORM_WIN32_PLATFORMINFO_H
#define PLATFORM_WIN32_PLATFORMINFO_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <WinGDI.h>


namespace platform
{
    struct PlatformInfo
    {
        HWND windowHandle;
        HDC deviceContext;
        HGLRC renderContext;
        LPCSTR className;
    };
}

#endif