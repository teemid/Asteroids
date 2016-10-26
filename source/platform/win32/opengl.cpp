#include "platform/opengl.h"

#include <cstring>
#include "gl/wglext.h"

#include "platform/win32/assert.h"
#include "platform/win32/platforminfo.h"

#define GL_FUNC(type, name) type name;
#include "gl.def"

namespace platform
{
namespace opengl
{
    #define WGL_FUNC(type, name) static type name;
    #include "wgl.def"

    typedef void (*glProc) (void);

    static glProc GetGLFunction (HMODULE dll, const char * proc_name)
    {
        glProc result = (glProc)wglGetProcAddress(proc_name);

        if (!result)
        {
            result = (glProc)GetProcAddress(dll, proc_name);
        }

        return result;
    }

    void LoadProcs (void)
    {
        HMODULE dll = LoadLibrary("opengl32.dll");

        #define GL_FUNC(type, name) name = (type)GetGLFunction(dll, #name);
        #include "gl.def"

        FreeLibrary(dll);
    }

    void CreateContext (platform::PlatformInfo * info, int major_version, int minor_version)
    {
        PIXELFORMATDESCRIPTOR pixelFormat = {};
        pixelFormat.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pixelFormat.nVersion = 1;
        pixelFormat.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pixelFormat.iPixelType = PFD_TYPE_RGBA;
        pixelFormat.cColorBits = 24;
        pixelFormat.cAlphaBits = 8;
        pixelFormat.cAccumBits = 0;
        pixelFormat.cDepthBits = 24;
        pixelFormat.cStencilBits = 8;

        auto pixelFormatIndex = ChoosePixelFormat(info->deviceContext, &pixelFormat);

        Assert(pixelFormatIndex, "Failed to choose a pixel format.\n");

        auto result = SetPixelFormat(info->deviceContext, pixelFormatIndex, &pixelFormat);

        Assert(result, "Failed to set the pixel format.\n");

        HGLRC renderContext = wglCreateContext(info->deviceContext);

        Assert(renderContext, "Failed to create a render context.\n");

        wglMakeCurrent(info->deviceContext, renderContext);
    
        wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB");

        Assert(wglGetExtensionsStringARB, "Failed to get the location of %s\n", "wglGetExtensionsStringARB");

        const char * extensions = wglGetExtensionsStringARB(info->deviceContext);

        const char * has_create_context = strstr(extensions, "WGL_ARB_create_context");
        const char * has_context_profile = strstr(extensions, "WGL_ARB_create_context_profile");
        const char * has_robustness = strstr(extensions, "WGL_ARB_create_context_robustness");

        Assert(has_create_context && has_context_profile, "WGL_ARB_create_context and WGL_ARB_create_context_profile not available in extensions string.\n");

        if (!has_robustness)
        {
            printf("WGL_ARB_create_context_robustness not available.\n");
        }

        wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

        Assert(wglCreateContextAttribsARB, "Could not get the location of wglCreateContextAttribsARB.\n");

        info->renderContext = renderContext;
        DeleteContext(info);

        pixelFormatIndex = ChoosePixelFormat(info->deviceContext, &pixelFormat);

        Assert(pixelFormatIndex, "Could not get a pixel format for the new context.\n");

        result = SetPixelFormat(info->deviceContext, pixelFormatIndex, &pixelFormat);

        Assert(result, "Could not set the pixel format.\n");

        int32_t attributes[] = {
            WGL_CONTEXT_MAJOR_VERSION_ARB, major_version,
            WGL_CONTEXT_MINOR_VERSION_ARB, minor_version,
            WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB | WGL_CONTEXT_DEBUG_BIT_ARB,
            NULL, NULL
        };

        renderContext = wglCreateContextAttribsARB(info->deviceContext, 0, attributes);

        Assert(renderContext, "Failed to create a modern OpenGL context.\n");

        Assert(wglMakeCurrent(info->deviceContext, renderContext), "wglMakeCurrent failed.\n");

        info->renderContext = renderContext;
    }

    void DeleteContext (PlatformInfo * info)
    {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(info->renderContext);
        info->renderContext = NULL;
    }

    void SwapBuffers (PlatformInfo * info)
    {
        ::SwapBuffers(info->deviceContext);
    }
}
}