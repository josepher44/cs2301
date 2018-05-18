all: leap

leap: leap.o
	gcc --std=gnu89 leap.o -o leap

leap.o: leap.c
	gcc -c --std=gnu89 leap.c

clean:
	rm -f leap.o leap
