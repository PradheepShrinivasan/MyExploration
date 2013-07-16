#make file so that i can be lazy about not typing the entire compilation
#of gcc and arguments again and again

mystring.out:main.c libmystring.so libmystring.a
	gcc -I. -L. -lmystring -o mystring.test main.c

#main.o:main.c
#	gcc -c -g -I. -Wall main.c -lmystring 

libmystring.so:mystring.o
	gcc -shared -Wl,-soname,libmystring.so -o libmystring.so mystring.o

libmystring.a:mystring.o
	ar -r libmystring.a mystring.o

mystring.o:mystring.h mystring.c
	gcc -Wall -g -c -fPIC mystring.c

clean:
	rm *.o 
	rm *.a
	rm *.so
	rm *.test
