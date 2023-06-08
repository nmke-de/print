# Print

Lib**print** is a C library to be used for printing to the screen. It uses Linux syscalls and does no allocation on the heap.

## But why?

I noticed that I regularly do the following in my C projects:

```C
#define print(str) write(1, (str), strlen(str))
```

In order to have this macro and similar functions at one central place, I wrote this library.

### What about `printf`, `puts`, `write` or `writev`?

`printf` and its siblings provide more features than I will usually use. Format strings are also a potential security vulnerability. Furthermore, Libprint is more typesafe than `printf`, since all it functions and macros expect C strings as arguments. Lastly, `printf` can be somewhat bloated. I don't say that we should get rid of `printf` for all time, but my usecase is usually simpler than all the features `printf` provides.

`puts` on the other hand suffers a little from too *little* flexibility. It is possible to archieve all the functionality of `puts` with the above macro. `puts` suffers from one problem: It can only print a single string, not a vector of multiple strings.

`write` has worked well for me so far, since it allows me to control the length of the output a bit better. It suffers from the same problem as `puts`, but it is also inconvenient to pass the string argument twice.

`writev` is capable to print vectors of strings, but setting them up is a bit inconvenient. This library makes use of `writev` in the background.

## Dependencies

- Linux
- a libc
- C Compiler (for building)
- Make (for building)

## Build

Type `make`.

## Usage

See also: [print.h](print.h)

WIP
