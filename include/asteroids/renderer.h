#ifndef ASTEROIDS_RENDERER
#define ASTEROIDS_RENDERER

namespace platform
{
    struct PlatformInfo;
}

namespace asteroids
{
    class Renderer
    {
    public:
        virtual ~Renderer (void) = 0;

        virtual void Render(void) = 0;
    };

    inline Renderer::~Renderer (void) { }
}

#endif