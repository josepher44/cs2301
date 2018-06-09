all: structest ctest

ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

structest: structest.o mystruct.o
	gcc structest.o mystruct.o -o structest

structest.o: structest.c mystruct.h
	gcc -c structest.c

mystruct.o: mystruct.c mystruct.h
	gcc -c mystruct.c

docs:
	doxygen
	chmod go+r html latex
	cp -R -p ~/cs2301/cs2301_hw/hw3/html/* ~/public_html/cs2301_hw3/

clean:
	rm -f mystring.o ctest.o ctest mystruct.o structest.o structest
