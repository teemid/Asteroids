#ifndef PLATFORM_OPENGL_H
#define PLATFORM_OPENGL_H

namespace platform
{
    struct PlatformInfo;

namespace opengl
{
    void CreateContext (platform::PlatformInfo * info, int major_version, int minor_version);
    void DeleteContext (platform::PlatformInfo * info);
    void SwapBuffers (platform::PlatformInfo * info);

    void LoadProcs (void);
}
}

#endif
