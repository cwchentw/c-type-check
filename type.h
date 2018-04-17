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
    char: TYPENAME_CHAR, \
    short: TYPENAME_SHORT, \
    int: TYPENAME_INT, \
    long: TYPENAME_LONG, \
    long long: TYPENAME_LONG_LONG, \
    char *: TYPENAME_POINTER_TO_CHAR, \
    default: TYPENAME_OTHER)

#define type_str(x) _Generic((x), \
    bool: "bool", \
    char: "char", \
    short: "short", \
    int: "int", \
    long: "long", \
    long long: "long long", \
    char *: "pointer to char", \
    default: "other")

#endif // TYPE_H

