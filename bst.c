#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "stack.h"

int max(int a,int b)
{
   return(a>b?a:b);
}

tree_nd *ROOT=NULL;
tree_nd* create_node(int val)
{
        tree_nd *node = NULL;
        node = (tree_nd*)malloc(sizeof(tree_nd));
        node->data = val;
        memset(node->dir,0,2*(sizeof(tree_nd*)));
        return node;
}
boolean tree_node_insert(tree_nd *node,tree_nd *par,int dir)
{
        if (!par) {
            printf("\n First element assing it to ROOT");
            ROOT=node;
            return TRUE;
        }
        dir = (node->data > par->data);
        if (!par->dir[dir]) {
            par->dir[dir] = node;
            return TRUE;
        }
        tree_node_insert(node,par->dir[dir],dir);
        //insert_tree(node, par->dir[(node->data > par->data)], (node->data > par->data));
        return TRUE;
}

 
boolean tree_node_delete(tree_nd *node,int data)
{
    tree_nd *ptr=NULL;
    tree_nd *par=NULL;
    int delete_type = -1;
    int ptr_dir = -1;
    ptr = node;
    while (ptr && ptr->data != data) {
        par = ptr;
        ptr = ptr->dir[(ptr->data < data ? 0 : 1)];
    }
    if (ptr) {
        printf("\n Found the tree node to delete");
        /* now should find out which case of the delete it is
  	 * is it the leaf node without any child
         * or is it the node with a single child 
         * or is it a node with both the children
	 */
         if (ptr->dir[0] && ptr->dir[1] ) {
            delete_type = 3;
         }
         else if (ptr->dir[0] || ptr->dir[1] ) {
            delete_type = 2;
         } else {
            delete_type = 1;
         }
    } else {
         printf("\n Didn't find the element in the tree to delete");
         return FALSE;
    }
    ptr_dir = (par->data > data ? 1 : 0);
   
    switch(delete_type) {
        case 1: /* node without any child case */
           par->dir[ptr_dir]=NULL;
           free(ptr); 
           break;
        case 2:
           if (ptr->dir[0]) {
              par->dir[ptr_dir] = ptr->dir[0];
           } else if (ptr->dir[1]) {
              par->dir[ptr_dir] = ptr->dir[1];
           }
           free(ptr);
           break;
        case 3:
           break;

        default:
	   printf("\n Tree delete default case, shouldn't be here");
           break;
    }
         
    return TRUE;
}
void inorder_recur(tree_nd *node)
{
        if (node == NULL) {
            return;
        }
        inorder_recur(node->dir[0]);
        printf("\t %d",node->data);
        inorder_recur(node->dir[1]);
}

int total_nodes(tree_nd *node)
{
    int val;
    if (node == NULL) {
        return 0;
    }
    val = total_nodes(node->dir[0]) + total_nodes(node->dir[1]) +1;
    return val;
}
    

void inorder(tree_nd *node,int total_elem)
{
     tree_nd *ptr=NULL;
     if (node == NULL) {
        return;
     }

     /* Create the stack to push tree element 
      * max the stack size need to be total elem in the tree
      */
     printf("\n Creating the stack for traversal"); 
     if (!create_stack(total_elem)) {
         printf("\n Failed to create the stack for the tree of size"
                "%d",total_elem);
         return;
     }
     
     ptr = node; 
     while (ptr || !(isStack_empty())) {

         while (ptr) {
            push((void *)ptr);
            ptr=ptr->dir[0];
         }

         ptr = (tree_nd *)pop();
         printf("\n %d",ptr->data);
         ptr = ptr->dir[1];

     }
     delete_stack(); 
     return;          
}

int tree_height(tree_nd *node)
{
    if (node == NULL) {
       return -1;
    }
    return (max(tree_height(node->dir[0]),tree_height(node->dir[1]))+1);
} 
