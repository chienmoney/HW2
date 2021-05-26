all: main.c bst.c bst.h arr.c arr.h bs.c bs.h ll.c ll.h#bst.o bs.o ll.o arr.o #hash.o
	g++ main.c bst.c bst.h arr.c arr.h bs.c bs.h ll.c ll.h -o main

#bst.o: bst.c bst.h
#	gcc -c bst.c -o bst.o

#bs.o: bs.c bs.h
#	gcc -c bs.c -o bs.o

#arr.o: arr.c arr.h
#	gcc -c arr.c -o arr.o

#ll.o: ll.c ll.h
#	gcc -c ll.c -o ll.o

#hash.o: hash.c hash.h
#	gcc -c hash.c -o hash.o

clean:
		rm -f main
