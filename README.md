# type_check

A small C11 utility that classifies built-in C types using `_Generic`.

This header provides a lightweight approximation of a `type(obj)` query
for a closed set of built-in C types. It maps expressions to a simple
enum value or a readable string.

This project is intentionally minimal. It does **not** attempt to
implement reflection or a general type system.

------------------------------------------------------------------------

## Requirements

-   A C compiler with **C11** support (required for `_Generic`)
-   Tested with **GCC** and **Clang**

Optional tools used during development:

-   `make`
-   `cppcheck`
-   `valgrind`

------------------------------------------------------------------------

## Installation

The header can simply be copied into your project:

    type_check.h

For system-wide installation:

    PREFIX=/usr/local sudo make install

------------------------------------------------------------------------

## Usage

The library provides two macros:

    type(x)
    type_str(x)

Example:

``` c
#include <stdio.h>
#include "type_check.h"

int main(void)
{
    int x = 10;
    double y = 3.14;

    printf("%s\n", type_str(x));
    printf("%s\n", type_str(y));
}
```

Output:

    int
    double

`type(x)` returns an enum value (`typename_t`), while `type_str(x)`
returns a human-readable string.

------------------------------------------------------------------------

## Scope

This utility intentionally focuses on **built-in C types only**.

It is designed as a small type classifier built on top of `_Generic`,
not as a reflection system or a generic object framework.

Extending it to arbitrary user-defined types would require manually
maintaining a full type metadata system, which is outside the scope of
this project.

------------------------------------------------------------------------

## Author

ByteBard (2018)

------------------------------------------------------------------------

## License

MIT
