#ifndef TYPE_CHECK_H
#define TYPE_CHECK_H

#include <stdbool.h>
#include <complex.h>

#ifdef __cplusplus
extern "C" {
#endif

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
    TYPENAME_FLOAT,
    TYPENAME_DOUBLE,
    TYPENAME_LONG_DOUBLE,
    TYPENAME_FLOAT_COMPLEX,
    TYPENAME_DOUBLE_COMPLEX,
    TYPENAME_LONG_DOUBLE_COMPLEX,
    TYPENAME_POINTER_TO_CHAR,
    TYPENAME_POINTER_TO_VOID,
    TYPENAME_OTHER
};

#define type(x) _Generic((x), \
    bool: TYPENAME_BOOL, \
    char: TYPENAME_CHAR, \
    short: TYPENAME_SHORT, \
    int: TYPENAME_INT, \
    long: TYPENAME_LONG, \
    long long: TYPENAME_LONG_LONG, \
    unsigned short: TYPENAME_UNSIGNED_SHORT, \
    unsigned int: TYPENAME_UNSIGNED_INT, \
    unsigned long: TYPENAME_UNSIGNED_LONG, \
    unsigned long long: TYPENAME_UNSIGNED_LONG_LONG, \
    float: TYPENAME_FLOAT, \
    double: TYPENAME_DOUBLE, \
    long double: TYPENAME_LONG_DOUBLE, \
    float complex: TYPENAME_FLOAT_COMPLEX, \
    double complex: TYPENAME_DOUBLE_COMPLEX, \
    long double complex: TYPENAME_LONG_DOUBLE_COMPLEX, \
    char *: TYPENAME_POINTER_TO_CHAR, \
    void *: TYPENAME_POINTER_TO_VOID, \
    default: TYPENAME_OTHER)

#define type_str(x) _Generic((x), \
    bool: "bool", \
    char: "char", \
    short: "short", \
    int: "int", \
    long: "long", \
    long long: "long long", \
    unsigned short: "unsigned short", \
    unsigned int: "unsigned int", \
    unsigned long: "unsigned long", \
    unsigned long long: "unsigned long long", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    float complex: "float complex", \
    double complex: "double complex", \
    long double complex: "long double complex", \
    char *: "pointer to char", \
    void *: "pointer to void", \
    default: "other")

#ifdef __cplusplus
}
#endif

#endif // TYPE_CHECK_H

