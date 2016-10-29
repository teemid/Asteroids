#ifndef ASTEROIDS_MEMORY_H
#define ASTEROIDS_MEMORY_H

namespace asteroids
{
    #include <cstdlib>

    #define ALLOCATE(type, bytes) (type *)malloc(bytes)
    #define REALLOCATE(type, old_memory, new_size) (type *)malloc(old_memory, new_size)
    #define DEALLOCATE(memory) free(memory)
}

#endif