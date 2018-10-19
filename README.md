# mytree-library

git add bst.c
git commit -m "comments"
git remote add origin https://github.com/subhrch/mytree-library.git
git push -u origin master

==========================================================

Use the makefile to build the tree library and build a sample application which will use 
the library apis and create a tree and test all the apis.

1. Clean the object files
> make clean

2. Build the tree library
>make 

3. Build the application and the bin file name is "bstmain"
> make main

OTHER OPTIONs for more control

// For compiling the bst tree library and test app
gcc -c -fpic bst.c
gcc -c -fpic stack.c
gcc -shared -o libbst.so stack.o bst.o
gcc -L/home/subchhot/cprograms/tree/ -Wl,-rpath=/home/subchhot/cprograms/tree -ggdb -o newbstmain tree_main.c -lbst

//for building only the queue library and the test app replace the path properly
//
gcc -c  -fpic queue.c
gcc -shared -o libqueue.so queue.o
gcc -L/home/subchhot/cprograms/tree/ -Wl,-rpath=/home/subchhot/cprograms/tree -ggdb -o test_queue queue_test.c -lqueue

==========================================================

Run the client app by executing
> ./bstmain

If you get error like below then make sure the LD_LIBRARY_PATH is programed properly

subchhot@subchhot-VirtualBox:~/cprograms/tree$ ./bstmain
./bstmain: error while loading shared libraries: libbst.so: cannot open shared object file: No such file or directory

To program the LD_LIBRARAY_PATH
export LD_LIBRARY_PATH=/user/folder/mytree_library:$LD_LIBRARY_PATH


