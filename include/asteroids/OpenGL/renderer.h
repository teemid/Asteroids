#ifndef ASTEROIDS_OPENGL_RENDERER_H
#define ASTEROIDS_OPENGL_RENDERER_H

#include "asteroids/renderer.h"

namespace asteroids
{
    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer (void);
        ~OpenGLRenderer (void);

        void Render (void);
    };
}

#endif