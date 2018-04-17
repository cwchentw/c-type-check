#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "type.h"

int main()
{
    // bool
    assert(type_str(({bool flag = true; flag;})) == "bool");
    // short int
    assert(type_str(({short s = 0; s;})) == "short");
    // int
    assert(type_str(0) == "int");
    // long int
    assert(type_str(({long l = 0; l;})) == "long");
    // long long int
    assert(type_str(({long long ll = 0; ll;})) == "long long");
    // char
    assert(type_str(({char c = 'c'; c; })) == "char");
    // char *, i.e. pointer to char
    assert(type_str("Hello World") == "pointer to char");

    return 0;
}
