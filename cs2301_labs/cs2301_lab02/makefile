all: at at2

at: at.o print_arrays.o
	gcc -g --std=gnu89 at.o print_arrays.o -o at

at.o: at.c print_arrays.h
	gcc -g --std=gnu89 -c at.c

at2: at2.o print_arrays.o
	gcc -g --std=gnu89 at2.o print_arrays.o -o at2

at2.o: at2.c print_arrays.h
	gcc -g --std=gnu89 -c at2.c

print_arrays.o: print_arrays.c print_arrays.h
	gcc -g --std=gnu89 -c print_arrays.c

docs:
	doxygen
	chmod go+r html latex
	cp -R -p ~/cs2301/cs2301_labs/cs2301_lab02/html/* ~/public_html/cs2301_lab02/


clean:
	rm -f *.o
	rm -f at at2
