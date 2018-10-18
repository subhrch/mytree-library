all : 	stack.o bst.o libbst.so main
bst.o:		bst.c bst.h
	gcc -c -fpic $<
stack.o: 	stack.c stack.h
	gcc -c -fpic $<
libbst.so:	bst.o stack.o
	gcc -shared -o libbst.so bst.o stack.o
main:
	gcc -L/home/subchhot/cprograms/tree/ -Wl,-rpath=/home/subchhot/cprograms/tree -o test_bst tree_main.c -lbst

clean:
	rm -f *.so *.o
