#include <assert.h>
#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type_check.h"

typedef struct _int Int;

struct _int {
    int data;
};

int main()
{
    // bool
    {
        bool flag = true;
        assert(type(flag) == TYPENAME_BOOL);
        assert(strcmp(type_str(flag), "bool") == 0);
    }

    // char
    {
        char c = 'c';
        assert(type(c) == TYPENAME_CHAR);
        assert(strcmp(type_str(c), "char") == 0);
    }

    // signed char
    {
        signed char c = 'c';
        assert(type(c) == TYPENAME_SIGNED_CHAR);
        assert(strcmp(type_str(c), "signed char") == 0);
    }

    // unsigned char
    {
        unsigned char c = 'c';
        assert(type(c) == TYPENAME_UNSIGNED_CHAR);
        assert(strcmp(type_str(c), "unsigned char") == 0);
    }

    // short int
    {
        short s = 0;
        assert(type(s) == TYPENAME_SHORT);
        assert(strcmp(type_str(s), "short") == 0);
    }

    // int
    {
        assert(type(0) == TYPENAME_INT);
        assert(strcmp(type_str(0), "int") == 0);
    }

    // long int
    {
        long l = 0;
        assert(type(l) == TYPENAME_LONG);
        assert(strcmp(type_str(l), "long") == 0);
    }

    // long long int
    {
        long long ll = 0;
        assert(type(ll) == TYPENAME_LONG_LONG);
        assert(strcmp(type_str(ll), "long long") == 0);
    }

    // unsigned short
    {
        unsigned short us = 0;
        assert(type(us) == TYPENAME_UNSIGNED_SHORT);
        assert(strcmp(type_str(us), "unsigned short") == 0);
    }

    // unsigned int
    {
        unsigned int ui = 0;
        assert(type(ui) == TYPENAME_UNSIGNED_INT);
        assert(strcmp(type_str(ui), "unsigned int") == 0);
    }

    // unsigned long
    {
        unsigned long ul = 0;
        assert(type(ul) == TYPENAME_UNSIGNED_LONG);
        assert(strcmp(type_str(ul), "unsigned long") == 0);
    }

    // unsigned long long
    {
        unsigned long long ull = 0;
        assert(type(ull) == TYPENAME_UNSIGNED_LONG_LONG);
        assert(strcmp(type_str(ull), "unsigned long long") == 0);
    }

    // float
    {
        float f = 0.0;
        assert(type(f) == TYPENAME_FLOAT);
        assert(strcmp(type_str(f), "float") == 0);
    }

    // double
    {
        double dl = 0.0;
        assert(type(dl) == TYPENAME_DOUBLE);
        assert(strcmp(type_str(dl), "double") == 0);
    }

    // long double
    {
        long double ldl = 0.0;
        assert(type(ldl) == TYPENAME_LONG_DOUBLE);
        assert(strcmp(type_str(ldl), "long double") == 0);
    }

    // float complex
    {
        float complex fc = 0.0 + 0.0*I;
        assert(type(fc) == TYPENAME_FLOAT_COMPLEX);
        assert(strcmp(type_str(fc), "float complex") == 0);
    }

    // double complex
    {
        double complex dlc = 0.0 + 0.0*I;
        assert(type(dlc) == TYPENAME_DOUBLE_COMPLEX);
        assert(strcmp(type_str(dlc), "double complex") == 0);
    }

    // long double complex
    {
        long double complex ldlc = 0.0 + 0.0*I;
        assert(type(ldlc) == TYPENAME_LONG_DOUBLE_COMPLEX);
        assert(strcmp(type_str(ldlc), "long double complex") == 0);
    }

    // pointer to char
    {
        char *str = "Hello World";
        assert(type(str) == TYPENAME_POINTER_TO_CHAR);
        assert(strcmp(type_str(str), "pointer to char") == 0);
    }

    // pointer to void
    {
        void *ptr = (void *) malloc(sizeof(Int));

        assert(type(ptr) == TYPENAME_POINTER_TO_VOID);
        assert(strcmp(type_str(ptr), "pointer to void") == 0);

        free(ptr);
    }

    // Pointer to some struct
    {
        Int *obj = malloc(sizeof(Int));

        assert(type(obj) == TYPENAME_OTHER);
        assert(strcmp(type_str(obj), "other") == 0);

        free(obj);
    }

    return 0;
}
