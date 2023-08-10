build: libprint.a

libprint.a: printv.o
	$(AR) -rc $@ *.o

clean:
	rm -rf libprint.a *.o
