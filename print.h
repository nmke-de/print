#ifndef PRINT_H
#define PRINT_H

#include <string.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

void fdprintv(int fd, const char**);

#define print(str) write(1, (str), strlen((str)))

#define printv(...) fdprintv(1, (const char *[]){__VA_ARGS__, NULL})
#define println(fd, ...) fdprintv(1, (const char *[]){__VA_ARGS__, "\n", NULL})

#define log(str) write(2, (str), strlen(str))
#define logv(...) fdprintv(2, (const char *[]){__VA_ARGS__, NULL})
#define logln(fd, ...) fdprintv(2, (const char *[]){__VA_ARGS__, "\n", NULL})

#ifdef __cplusplus
}
#endif

#endif
