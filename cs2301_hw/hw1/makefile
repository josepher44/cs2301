all: leap num

leap: leap.o
	gcc --std=gnu89 leap.o -o leap

leap.o: leap.c
	gcc -c --std=gnu89 leap.c

num: num.o grades.o
	gcc --std=gnu89 num.o grades.o -o num

num.o: num.c grades.h
	gcc -c --std=gnu89 num.c

grades.o: grades.c grades.h
	gcc -c --std=gnu89 grades.c

clean:
	rm -f *.o leap num
