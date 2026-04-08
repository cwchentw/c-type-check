#ifndef TYPE_CHECK_H
#define TYPE_CHECK_H

#include <stdbool.h>
#include <complex.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Single source of truth:
 *   C type, enum suffix, display string, category flags
 *
 * Category flags:
 *   I = integer-like
 *   F = floating-point
 *   C = complex
 *   P = pointer
 *
 * Flags are kept as 0/1 so we can reuse the same table for small traits.
 */
#define TYPE_CHECK_TABLE(X) \
    X(bool,                 BOOL,                  "bool",                     1, 0, 0, 0) \
    X(char,                 CHAR,                  "char",                     1, 0, 0, 0) \
    X(signed char,          SIGNED_CHAR,           "signed char",              1, 0, 0, 0) \
    X(unsigned char,        UNSIGNED_CHAR,         "unsigned char",            1, 0, 0, 0) \
    X(short,                SHORT,                 "short",                    1, 0, 0, 0) \
    X(int,                  INT,                   "int",                      1, 0, 0, 0) \
    X(long,                 LONG,                  "long",                     1, 0, 0, 0) \
    X(long long,            LONG_LONG,             "long long",                1, 0, 0, 0) \
    X(unsigned short,       UNSIGNED_SHORT,        "unsigned short",           1, 0, 0, 0) \
    X(unsigned int,         UNSIGNED_INT,          "unsigned int",             1, 0, 0, 0) \
    X(unsigned long,        UNSIGNED_LONG,         "unsigned long",            1, 0, 0, 0) \
    X(unsigned long long,   UNSIGNED_LONG_LONG,    "unsigned long long",       1, 0, 0, 0) \
    X(float,                FLOAT,                 "float",                    0, 1, 0, 0) \
    X(double,               DOUBLE,                "double",                   0, 1, 0, 0) \
    X(long double,          LONG_DOUBLE,           "long double",              0, 1, 0, 0) \
    X(float complex,        FLOAT_COMPLEX,         "float complex",            0, 0, 1, 0) \
    X(double complex,       DOUBLE_COMPLEX,        "double complex",           0, 0, 1, 0) \
    X(long double complex,  LONG_DOUBLE_COMPLEX,   "long double complex",      0, 0, 1, 0) \
    X(char *,               POINTER_TO_CHAR,       "pointer to char",          0, 0, 0, 1) \
    X(const char *,         POINTER_TO_CONST_CHAR, "pointer to const char",    0, 0, 0, 1) \
    X(void *,               POINTER_TO_VOID,       "pointer to void",          0, 0, 0, 1) \
    X(const void *,         POINTER_TO_CONST_VOID, "pointer to const void",    0, 0, 0, 1)

enum typename_t {
#define TYPE_CHECK_ENUM(c_type, enum_name, display_name, is_int, is_float, is_complex, is_ptr) \
    TYPENAME_##enum_name,
    TYPE_CHECK_TABLE(TYPE_CHECK_ENUM)
#undef TYPE_CHECK_ENUM
    TYPENAME_OTHER
};

/*
 * Classify an expression into enum typename_t.
 *
 * Note:
 *   This is intentionally a closed-world classifier over selected built-in
 *   types. It is not a reflection system.
 */
#define type(x) _Generic((x), \
#define TYPE_CHECK_GENERIC_ENUM(c_type, enum_name, display_name, is_int, is_float, is_complex, is_ptr) \
    c_type: TYPENAME_##enum_name,
    TYPE_CHECK_TABLE(TYPE_CHECK_GENERIC_ENUM)
#undef TYPE_CHECK_GENERIC_ENUM
    default: TYPENAME_OTHER)

/*
 * Convert typename_t to a display string.
 */
static inline const char *typename_str(enum typename_t t)
{
    switch (t) {
#define TYPE_CHECK_CASE(c_type, enum_name, display_name, is_int, is_float, is_complex, is_ptr) \
    case TYPENAME_##enum_name: return display_name;
        TYPE_CHECK_TABLE(TYPE_CHECK_CASE)
#undef TYPE_CHECK_CASE
    case TYPENAME_OTHER:
    default:
        return "other";
    }
}

/*
 * Convenience macro: classify and stringify in one step.
 */
#define type_str(x) typename_str(type(x))

/*
 * Small trait-like helpers.
 *
 * These remain intentionally shallow:
 *   - no user-defined types
 *   - no reflection object
 *   - no OO-style dispatch
 */

#define is_integer(x) _Generic((x), \
#define TYPE_CHECK_GENERIC_IS_INTEGER(c_type, enum_name, display_name, is_int, is_float, is_complex, is_ptr) \
    c_type: is_int,
    TYPE_CHECK_TABLE(TYPE_CHECK_GENERIC_IS_INTEGER)
#undef TYPE_CHECK_GENERIC_IS_INTEGER
    default: 0)

#define is_floating(x) _Generic((x), \
#define TYPE_CHECK_GENERIC_IS_FLOATING(c_type, enum_name, display_name, is_int, is_float, is_complex, is_ptr) \
    c_type: is_float,
    TYPE_CHECK_TABLE(TYPE_CHECK_GENERIC_IS_FLOATING)
#undef TYPE_CHECK_GENERIC_IS_FLOATING
    default: 0)

#define is_complex(x) _Generic((x), \
#define TYPE_CHECK_GENERIC_IS_COMPLEX(c_type, enum_name, display_name, is_int, is_float, is_complex, is_ptr) \
    c_type: is_complex,
    TYPE_CHECK_TABLE(TYPE_CHECK_GENERIC_IS_COMPLEX)
#undef TYPE_CHECK_GENERIC_IS_COMPLEX
    default: 0)

#define is_pointer(x) _Generic((x), \
#define TYPE_CHECK_GENERIC_IS_POINTER(c_type, enum_name, display_name, is_int, is_float, is_complex, is_ptr) \
    c_type: is_ptr,
    TYPE_CHECK_TABLE(TYPE_CHECK_GENERIC_IS_POINTER)
#undef TYPE_CHECK_GENERIC_IS_POINTER
    default: 0)

#ifdef __cplusplus
}
#endif

#endif /* TYPE_CHECK_H */
