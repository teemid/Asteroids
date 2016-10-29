#ifndef ASTEROIDS_LIST_H
#define ASTEROIDS_LIST_H

#include "asteroids/memory.h"
#include "asteroids/types.h"

namespace asteroids
{
    template<typename T>
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
        T * elements;
        Size capacity;
    };

    template<typename T>
    Pool<T>::Pool (void)
    {
        T * elements = ALLOCATE(T, sizeof(T) * (size_t)capacity);
    }

    template<typename T>
    Pool<T>::Pool (Size initial_capacity)
    {
        T * elements = ALLOCATE(T, sizeof(T) * (size_t)initial_capacity);
    }

    template<typename T>
    T * Pool<T>::Get (void)
    {

    }

    template<typename T>
    T * Pool<T>::begin (void)
    {
        return elements;
    }

    template<typename T>
    T * Pool<T>::end (void)
    {
        return elements + capacity;
    }
}

#endif