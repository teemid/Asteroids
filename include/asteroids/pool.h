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
        T * free_list[N];
        T * current;
        Size capacity;
    };

    template<typename T, UInt32 N>
    Pool<T, N>::Pool (void)
    {
        this->capacity = N;
        
        for (UInt32 i = 0; i < N; i++)
        {
            this->free_list[i] = elements + (N - i);
        }

        this->current = this->free_list[N];
    }

    template<typename T, UInt32 N>
    T * Pool<T, N>::Get (void)
    {
        T * free = this->current;
        this->current = nullptr;
        this->current = this->current - 1;

        return free;
    }

    template<typename T, UInt32 N>
    void Free (T * element)
    {
        this->current = this->current + 1;
        this->current = element;
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