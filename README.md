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

==========================================================

Run the client app by executing
> ./bstmain

If you get error like below then make sure the LD_LIBRARY_PATH is programed properly

subchhot@subchhot-VirtualBox:~/cprograms/tree$ ./bstmain
./bstmain: error while loading shared libraries: libbst.so: cannot open shared object file: No such file or directory

To program the LD_LIBRARAY_PATH
export LD_LIBRARY_PATH=/user/folder/mytree_library:$LD_LIBRARY_PATH


