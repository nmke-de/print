build: libprint.a

libprint.a: printv.o
	$(AR) -rc $@ *.o
