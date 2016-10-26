#ifndef ASTEROIDS_VECTOR2_H
#define ASTEROIDS_VECTOR2_H

#include "asteriods/types.h"

namespace asteroids
{
    struct Vector2f
    {
        union
        {
            struct { Real32 x, y; };
            Real32 data[2];
        }
    }
}

#endif