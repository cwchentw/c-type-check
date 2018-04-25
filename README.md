# Type Checking in C.

This repo implements type checking in C with `_Generic`.

## System Requirement

* A recent C compiler that supports C11, which is mandatory for `_Generic`.
* (Optional) `make`: for system-wise installation.
* (Dev) Cppcheck: for static code analysis.
* (Dev) Valgrind: for memory leak detection.
* (Dev) Perl: for tailing-line space trimming.

## Usage

Just copy *type_check.h* to your project.

For system-wise installation, run `make install`:

```
$ PREFIX=/usr/local sudo make install
```

This program provides two macros:

* `type(t)` emits a type-presenting enum.
* `type_str(t)` emits a type-presenting C string.

View the test program for more usage.

## Author

Michae Chen, 2018.

## License

MIT
