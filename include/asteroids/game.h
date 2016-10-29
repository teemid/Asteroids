#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "asteroids/types.h"
#include "asteroids/vector2.h"
#include "asteroids/pool.h"

namespace asteroids
{
    struct Asteroid
    {
        Vector2f position;
        Vector2f velocity;
        Int32 lives;
    };

    struct Player
    {
        Vector2f position;
        Vector2f velocity;
    };

    struct GameState
    {
        Player player;
        Pool<Asteroid, 20> asteroids;
        Real32 score;
    };

    void Initialize (void);

    void Update (Real64 delta);

    void Draw (void);

    void CleanUp (void);
}

#endif