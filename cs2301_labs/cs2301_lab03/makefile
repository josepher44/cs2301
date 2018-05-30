ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

docs:
	doxygen
	chmod go+r html latex
	cp -R -p ~/cs2301/cs2301_labs/cs2301_lab03/html/* ~/public_html/cs2301_lab03/

clean:
	rm -f mystring.o ctest.o ctest
