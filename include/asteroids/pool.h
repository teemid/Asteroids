#ifndef ASTEROIDS_LIST_H
#define ASTEROIDS_LIST_H

#include "asteroids/memory.h"
#include "asteroids/types.h"

namespace asteroids
{
    template<typename T, UInt32 N>
    class Pool
    {
    public:
        Pool (void);
        Pool (Size initial_capacity);

        T * Get (void);
        void Free (Size index);

        T * begin (void);
        T * end (void);
    private:
        T elements[N];
        Size capacity;
    };

    template<typename T, UInt32 N>
    Pool<T, N>::Pool (void) : capacity(N) { }

    template<typename T, UInt32 N>
    T * Pool<T, N>::Get (void)
    {

    }

    template<typename T, UInt32 N>
    T * Pool<T, N>::begin (void)
    {
        return elements;
    }

    template<typename T, UInt32 N>
    T * Pool<T, N>::end (void)
    {
        return elements + N;
    }
}

#endif