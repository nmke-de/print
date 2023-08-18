#include <sys/uio.h>
#include "print.h"

int fdprintv(int fd, const char **args) {
	int len = 0;
	for (; args[len] != NULL; len++) {}
	struct iovec vec[len];
	for (int i = 0; i < len; i++) {
		vec[i] = (struct iovec) {(void *) args[i], strlen(args[i])};
	}
	return writev(fd, vec, len);
}
