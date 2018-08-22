libbst.so:	bst.o 
	gcc -shared -o libbst.so bst.o

bst.o:		bst.c bst.h
	gcc -c -fpic $<

main:
	gcc -L/home/subchhot/cprograms/tree -o bstmain tree_main.c -lbst

clean:
	rm -f *.so *.o
