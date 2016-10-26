#ifndef PLATFORM_WIN32_ASSERT_H
#define PLATFORM_WIN32_ASSERT_H

#include <cstdio>
#include <cstdlib>

#define Assert(expression, message, ...) \
    if (!expression) \
    { \
        printf("Expression: %s failed at %s: %i.\n", #expression, __FILE__, __LINE__); \
        printf(message, __VA_ARGS__); \
        \
        exit(1); \
    } \
    else \
    { \
    \
    }

#endif