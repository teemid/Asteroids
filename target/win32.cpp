#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#include "asteroids/game.h"
#include "platform/opengl.h"
#include "platform/window.h"
#include "platform/win32/assert.h"
#include "platform/win32/platforminfo.h"

#include "asteroids/OpenGL/opengl.h"


static platform::Window window = {
    "Asteroids",
    CW_USEDEFAULT, CW_USEDEFAULT,
    800, 600,
};

static platform::PlatformInfo info = {
    NULL,
    NULL,
    NULL,
    "AsteroidsClass",
};


LRESULT CALLBACK Win32WindowProc (HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);


int CALLBACK WinMain (HINSTANCE instance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX windowClass = {};
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    windowClass.lpfnWndProc = Win32WindowProc;
    windowClass.hInstance = instance;
    windowClass.lpszClassName = info.className;

    Assert(RegisterClassEx(&windowClass), "Failed to register WindowClass.\n");

    info.windowHandle = CreateWindow(
        info.className,
        window.title,
        WS_OVERLAPPEDWINDOW,
        window.x, window.y,
        window.width, window.height,
        0, 0,
        instance,
        0
    );

    Assert(info.windowHandle, "Failed to create window.\n");

    info.deviceContext = GetDC(info.windowHandle);
    platform::opengl::CreateContext(&info, 3, 2);
    platform::opengl::LoadProcs();

    Assert(info.renderContext, "info.renderContext is NULL.\n");

    ShowWindow(info.windowHandle, nCmdShow);

    bool running = true;

    asteroids::Initialize();

    while (running)
    {
        MSG message;
        while (PeekMessage(&message, info.windowHandle, 0, 0, PM_REMOVE))
        {
            switch (message.message)
            {
                case WM_KEYDOWN:
                {
                    if (message.wParam == VK_ESCAPE)
                    {
                        PostQuitMessage(0);
                        running = false;
                    }
                } break;
                default:
                {
                    TranslateMessage(&message);
                    DispatchMessage(&message);
                } break;
            }
        }

        asteroids::Update(0.0f);

        static float color[] = { 0.0f, 0.0f, 0.0f };
        glClearBufferfv(GL_COLOR_BUFFER_BIT, 0, color);

        asteroids::Draw();

        platform::opengl::SwapBuffers(&info);
    }

    return 0;
}

LRESULT CALLBACK Win32WindowProc (HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);  
        } break;
        default:
        {
            return DefWindowProc(windowHandle, message, wParam, lParam);
        }
    }

    return 0;
}
