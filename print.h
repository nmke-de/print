#ifndef PRINT_H
#define PRINT_H

#include <string.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

void fdprintv(int fd, const char**);

#define cargs(...) (const char *[]){__VA_ARGS__, NULL}

#define print(str) write(1, (str), strlen((str)))
#define printv(...) fdprintv(1, (const char *[]){__VA_ARGS__, NULL})
#define println(...) fdprintv(1, (const char *[]){__VA_ARGS__, "\n", NULL})

#define log(str) write(2, (str), strlen(str))
#define logv(...) fdprintv(2, (const char *[]){__VA_ARGS__, NULL})
#define logln(...) fdprintv(2, (const char *[]){__VA_ARGS__, "\n", NULL})

#ifdef __cplusplus
}
#endif

#endif
