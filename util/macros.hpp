//
// Copyright 2015 Raphael Javaux <raphaeljavaux@gmail.com>
// University of Liege.
//
// Various macros.
//

#ifndef __TCP_MPIPE_UTILS_MACROS_HPP__
#define __TCP_MPIPE_UTILS_MACROS_HPP__

#include <tmc/task.h>   // tmc_task_die

//
// Macros
//

#ifdef NDEBUG
    #define TCP_MPIPE_DEBUG(MSG, ...)
#else
    #define TCP_MPIPE_DEBUG(MSG, ...)                                          \
        do {                                                                   \
            fprintf(                                                           \
                stderr, "[" __FILE__ ":%d] [DEBUG] " MSG "\n", __LINE__,       \
                ##__VA_ARGS__                                                  \
            );                                                                 \
        } while (0)
#endif

#define DIE(MSG, ...)                                                          \
    do {                                                                       \
        tmc_task_die("[" __FILE__ ":%d] " MSG, __LINE__, ##__VA_ARGS__);  \
    } while (0)

// Checks for errors in function which returns -1 and sets errno on failure.
#define VERIFY_ERRNO(VAL, WHAT)                                                \
    do {                                                                       \
        long __val = (long) (VAL);                                             \
        if (__val == -1)                                                       \
            DIE("%s (errno: %d)", (WHAT), errno);                              \
    } while (0)

// Branch prediction hints.
#define LIKELY(x)       __builtin_expect(!!(x), 1)
#define UNLIKELY(x)     __builtin_expect((x), 0)

#endif /* __TCP_MPIPE_UTILS_MACROS_HPP__ */