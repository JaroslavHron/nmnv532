
hello.x: hello.o
	gcc -fopenmp -o $@ $<

priklad.x: priklad.o
	gcc -fopenmp -o $@ $<

%.o : %.c
	gcc -fopenmp -c -o $@ $<

clean:
	rm *.o *.x

