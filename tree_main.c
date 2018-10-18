#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main(void)
{
        char *input=(char *)malloc(10);
        int tree_data=0,total_nd=0;
        tree_nd *nd=NULL;
        boolean rc = 0;

        do {
            printf("\nEnter data to insert into tree(press E to exit)");
            scanf("%s",input);
            if (strcmp(input,"E")) {
                tree_data = atoi(input);
                nd = create_node(tree_data);
                if (nd) {
                    printf("\n Tree node created successfully");
                } else {
                    printf("\n Tree node creation failed");
                    return 0;
                }
                rc = tree_node_insert(nd,ROOT,0);
                if (rc) {
                    printf("\n Insertion into TREE is successful");
                }
            }
        }while (strcmp(input,"E"));

        total_nd = total_nodes(ROOT);
        printf("\n Printing the TREE \n");
        printf("\n Total elements in tree %d",total_nd);
        printf("\n Total height of the tree is %d",tree_height(ROOT));
        /*inorder_recur(ROOT);*/
        inorder(ROOT,total_nd);
        return 0;
}
