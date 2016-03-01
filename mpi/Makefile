
hello.x: hello.o
	mpicc -o $@ $<

priklad.x: priklad.o
	mpicc -o $@ $<

%.o : %.c
	mpicc -c -o $@ $<

clean:
	rm *.o *.x

