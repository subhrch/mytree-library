#ifndef _BST_H_
#define _BST_H_
typedef struct _tree_nd
{
        int data;
        struct _tree_nd *dir[2];
}tree_nd;

typedef enum _boolean
{
        FALSE=0,
        TRUE=1
}boolean;

extern tree_nd *ROOT;

tree_nd* create_node(int val);
boolean insert_tree(tree_nd *node,tree_nd *par,int dir);
void inorder(tree_nd *node);
void inorder_recur(tree_nd *node);
int total_nodes(tree_nd *root);
int tree_height(tree_nd *node);

#endif
