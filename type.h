#ifndef TYPE_H
#define TYPE_H

#include <stdbool.h>

enum t_typename {
    TYPENAME_BOOL,
    TYPENAME_CHAR,
    TYPENAME_SHORT,
    TYPENAME_INT,
    TYPENAME_LONG,
    TYPENAME_LONG_LONG,
    TYPENAME_UNSIGNED_SHORT,
    TYPENAME_UNSIGNED_INT,
    TYPENAME_UNSIGNED_LONG,
    TYPENAME_UNSIGNED_LONG_LONG,
    TYPENAME_POINTER_TO_CHAR,
    TYPENAME_OTHER
};

#define type(x) _Generic((x), \
    bool: TYPENAME_BOOL, \
    short: TYPENAME_SHORT, \
    int: TYPENAME_INT, \
    long: TYPENAME_LONG, \
    long long: TYPENAME_LONG_LONG, \
    char: TYPENAME_CHAR, \
    char *: TYPENAME_POINTER_TO_CHAR, \
    default: TYPENAME_OTHER)

#define type_str(t) ({ \
        char *out; \
        switch (type(t)) { \
            case TYPENAME_BOOL: \
                out = "bool"; \
                break; \
            case TYPENAME_CHAR: \
                out = "char"; \
                break; \
            case TYPENAME_SHORT: \
                out = "short"; \
                break; \
            case TYPENAME_INT: \
                out = "int"; \
                break; \
            case TYPENAME_LONG: \
                out = "long"; \
                break; \
            case TYPENAME_LONG_LONG: \
                out = "long long"; \
                break; \
            case TYPENAME_POINTER_TO_CHAR: \
                out = "pointer to char"; \
                break; \
            case TYPENAME_OTHER: \
                out = "other"; \
                break; \
        } \
        out; \
    })

#endif // TYPE_H

