#include "asteroids/game.h"

namespace asteroids
{
    static GameState state;

    void Initialize (void)
    {
        state.player.position = Vector2f(100.0f, 100.0f);
        state.player.velocity = Vector2f(0.0f, 0.0f);

        state.asteroids = Pool<Asteroid>(20);

        state.score = 0;
    }

    void Update (Real64 delta)
    {
        state.player.position = state.player.position + state.player.velocity * delta;

        for (auto asteroid: state.asteroids)
        {
            asteroid.position = asteroid.position + asteroid.velocity * delta;
        }
    }

    void Draw (void)
    {

    }

    void CleanUp (void)
    {

    }
}