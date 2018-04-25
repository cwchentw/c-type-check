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
    assert(type(({bool flag = true; flag;})) == TYPENAME_BOOL);
    assert(strcmp(type_str(({bool flag = true; flag;})), "bool") == 0);

    // char
    assert(type(({char c = 'c'; c; })) == TYPENAME_CHAR);
    assert(strcmp(type_str(({char c = 'c'; c; })), "char") == 0);

    // short int
    assert(type(({short s = 0; s;})) == TYPENAME_SHORT);
    assert(strcmp(type_str(({short s = 0; s;})), "short") == 0);

    // int
    assert(type(0) == TYPENAME_INT);
    assert(strcmp(type_str(0), "int") == 0);

    // long int
    assert(type(({long l = 0; l;})) == TYPENAME_LONG);
    assert(strcmp(type_str(({long l = 0; l;})), "long") == 0);

    // long long int
    assert(type(({long long ll = 0; ll;})) == TYPENAME_LONG_LONG);
    assert(strcmp(type_str(({long long ll = 0; ll;})), "long long") == 0);

    // char *, i.e. pointer to char
    assert(type("Hello World") == TYPENAME_POINTER_TO_CHAR);
    assert(strcmp(type_str("Hello World"), "pointer to char") == 0);

    // Pointer to custem struct.
    Int *obj = malloc(sizeof(Int));

    assert(type(obj) == TYPENAME_OTHER);
    assert(strcmp(type_str(obj), "other") == 0);

    free(obj);

    return 0;
}
