#ifndef ASTEROIDS_OPENGL_RENDERER_H
#define ASTEROIDS_OPENGL_RENDERER_H

#include "asteroids/renderer.h"


namespace asteroids
{
    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer (platform::PlatformInfo * info);
        virtual ~OpenGLRenderer (void) final;

        void Render (void);
    };
}

#endif