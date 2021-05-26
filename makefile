all: main.c bst.c bst.h arr.c arr.h bs.c bs.h ll.c ll.h
	g++ main.c bst.c bst.h arr.c arr.h bs.c bs.h ll.c ll.h -o main
clean:
		rm -f main
