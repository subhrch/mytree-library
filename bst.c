#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

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
boolean insert_tree(tree_nd *node,tree_nd *par,int dir)
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
        insert_tree(node,par->dir[dir],dir);
        //insert_tree(node, par->dir[(node->data > par->data)], (node->data > par->data));
        return TRUE;
}
void inorder_recur(tree_nd *node)
{
        if (node == NULL) {
            return;
        }
        inorder(node->dir[0]);
        printf("\t %d",node->data);
        inorder(node->dir[1]);
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
    

void inorder(tree_nd *node)
{
     if (node == NULL) {
        return;
     }
}

int tree_height(tree_nd *node)
{
    if (node == NULL) {
       return -1;
    }
    return (max(tree_height(node->dir[0]),tree_height(node->dir[1]))+1);
} 
