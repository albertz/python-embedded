Python embedded
===============

Build a single static library with Python and PyCrypto.

This passes `test_crypto()` in [binstruct](https://github.com/albertz/binstruct/).

---

I tried a sample iOS binary where I linked against `libpython.a` and copied the `pylib` directory into Resources (following not-included symlinks).

This is the sample code:

    Py_SetProgramName((char*)[[[[NSBundle mainBundle] bundlePath] stringByAppendingString:@"/"] UTF8String]);
    Py_Initialize();
    PyRun_SimpleString("print 'Hello world!'");

And it works. :)


