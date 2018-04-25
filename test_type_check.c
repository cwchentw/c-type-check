#include <assert.h>
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

    // char *, i.e. pointer to char
    {
        assert(type("Hello World") == TYPENAME_POINTER_TO_CHAR);
        assert(strcmp(type_str("Hello World"), "pointer to char") == 0);
    }

    // Pointer to custem struct.
    {
        Int *obj = malloc(sizeof(Int));

        assert(type(obj) == TYPENAME_OTHER);
        assert(strcmp(type_str(obj), "other") == 0);

        free(obj);
    }

    return 0;
}
