#ifndef ASTEROIDS_RENDERER
#define ASTEROIDS_RENDERER

namespace asteroids
{
    class Renderer
    {
    public:
        Renderer(void);
        virtual ~Renderer(void);

        void Render(void);
    };
}

#endif