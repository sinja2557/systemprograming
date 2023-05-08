0314:	0314.o libfunc1.a libfunc2.a
	gcc -o 0314 -L. 0314.o -lfunc1 -lfunc2

libfunc1.a:	func1.o
		ar ruv libfunc1.a func1.o

libfunc2.a:	func2.o
		ar ruv libfunc2.a func2.o

0314.o:	0314.c
	gcc -c 0314.c

func1.o:	func1.c
		gcc -c func1.c

func2.o:	func2.c
		gcc -c func2.c

clean:
	rm -f core *.o 0314
