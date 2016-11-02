#include "asteroids/OpenGL/renderer.h"
#include "platform/opengl.h"


namespace asteroids
{
    OpenGLRenderer::OpenGLRenderer (platform::PlatformInfo * info)
    {
        platform::opengl::CreateContext(info, 3, 3);
    }

    OpenGLRenderer::~OpenGLRenderer (void)
    {
        
    }

    void OpenGLRenderer::Render (void)
    {

    }
}
