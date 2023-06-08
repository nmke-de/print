#include <alloca.h>
#include <sys/uio.h>
#include "print.h"

void printv(const char **args) {
	int len = 0;
	for (; args[len] != NULL; len++) {}
	struct iovec *vec = alloca(sizeof(struct iovec) * len);
	for (int i = 0; i < len; i++) {
		vec[i] = (struct iovec) {(void *) args[i], strlen(args[i])};
	}
	writev(1, vec, len);
}
