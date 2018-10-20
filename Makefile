all : 	stack.o bst.o queue.o libbst.so main
bst.o:		bst.c bst.h
	gcc -ggdb -c -fpic $<
stack.o: 	stack.c stack.h
	gcc -ggdb -c -fpic $<
queue.o:	queue.c queue.h
	gcc -ggdb -c -fpic $<

libbst.so:	bst.o stack.o queue.o
	gcc -shared -ggdb -o libbst.so bst.o stack.o queue.o
main:
	gcc -L/home/subchhot/cprograms/tree/ -Wl,-rpath=/home/subchhot/cprograms/tree -o test_bst -ggdb tree_main.c -lbst

clean:
	rm -f *.so *.o
