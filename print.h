#ifndef PRINT_H
#define PRINT_H

#include <string.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

void printv(const char**);

#define print(str) write(1, (str), strlen((str)))
#define println(...) printv((const char *[]){__VA_ARGS__, "\n", NULL})


#ifdef __cplusplus
}
#endif

#endif
