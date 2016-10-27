#ifndef ASTEROIDS_VECTOR2_H
#define ASTEROIDS_VECTOR2_H

#include "asteriods/types.h"
#include "asteriods/math.h"

namespace asteroids
{
    struct Vector2f
    {
        union
        {
            Real32 data[2];
            struct { Real32 x, y; };
        }

        Vector2f (void);
        Vector2f (Real32 x);
        Vector2f (Real32 x, Real32 y);

        inline Vector2f operator +(const Vector2f & rhs);
        inline Vector2f operator -(const Vector2f & rhs);
        inline Vector2f operator *(const Vector2f & rhs);

        inline Vector2f operator +(const Real32 & scalar);
        inline Vector2f operator -(const Real32 & scalar);
        inline Vector2f operator *(const Real32 & scalar);
        inline Vector2f operator /(const Real32 & scalar);

        inline Bool32 operator ==(const Vector2f & rhs);
    };

    inline Vector2f Normalize (Vector2f & v);
    inline Real32 Length (Vector2f & v);
    inline Real32 LengthSquared (Vector2f & v);
    inline Real32 Dot (Vector2f & v1, Vector2f & v2);
    inline Real32 Angle (Vector2f & v1, Vector2f & v2);
    inline Vector2f Lerp (Vector2f & start, Vector2f & end, Real32 t);

    inline Vector2f Vector2f::operator +(const Vector2f & rhs) { return Vector2f(x + rhs.x, y + rhs.y); }
    inline Vector2f Vector2f::operator -(const Vector2f & rhs) { return Vector2f(x - rhs.x, y - rhs.y); }
    inline Vector2f Vector2f::operator *(const Vector2f & rhs) { return Vector2f(x * rhs.x, y * rhs.y); }

    inline Vector2f Vector2f::operator +(const Real32 & scalar) { return Vector2f(x + scalar, y + scalar); }
    inline Vector2f Vector2f::operator -(const Real32 & scalar) { return Vector2f(x - scalar, y - scalar); }
    inline Vector2f Vector2f::operator *(const Real32 & scalar) { return Vector2f(x * scalar, y * scalar); }
    inline Vector2f Vector2f::operator /(const Real32 & scalar) { return Vector2f(x / scalar, y / scalar); }

    inline Bool32 operator ==(const Vector2f & rhs) { return (x == rhs.x && y == rhs.y); }

    inline Vector2f Normalize (Vector2f & v)
    {
        auto length = Length(v);

        return v / length;
    }

    inline Real32 Length (Vector2f & v)
    {
        return sqrt(v.x * v.x + v.y * v.y);
    }

    inline Real32 LengthSquared (Vector2f & v)
    {
        return v.x * v.x + v.y * v.y;
    }

    inline Real32 Dot (Vector2f & v1, Vector2f & v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }

    inline Real32 Angle (Vector2f & v1, Vector2f & v2)
    {
        return acos(Dot(v1, v2) / (Length(v1) * Length(v2)));
    }

    inline Vector2f Lerp (Vector2f & start, Vector2f & end, Real32 t)
    {
        auto inv = 1.0f - t;

        return Vector2f(start.x * inv + end.x * t , start.y * inv + end.y * t);
    }
}

#endif