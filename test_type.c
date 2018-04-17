#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "type.h"

int main()
{
    // bool
    assert(type(({bool flag = true; flag;})) == TYPENAME_BOOL);
    assert(type_str(({bool flag = true; flag;})) == "bool");
    // char
    assert(type(({char c = 'c'; c; })) == TYPENAME_CHAR);
    assert(type_str(({char c = 'c'; c; })) == "char");
    // short int
    assert(type(({short s = 0; s;})) == TYPENAME_SHORT);
    assert(type_str(({short s = 0; s;})) == "short");
    // int
    assert(type(0) == TYPENAME_INT);
    assert(type_str(0) == "int");
    // long int
    assert(type(({long l = 0; l;})) == TYPENAME_LONG);
    assert(type_str(({long l = 0; l;})) == "long");
    // long long int
    assert(type(({long long ll = 0; ll;})) == TYPENAME_LONG_LONG);
    assert(type_str(({long long ll = 0; ll;})) == "long long");
    // char *, i.e. pointer to char
    assert(type("Hello World") == TYPENAME_POINTER_TO_CHAR);
    assert(type_str("Hello World") == "pointer to char");

    return 0;
}
