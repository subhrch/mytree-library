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
boolean tree_node_insert(tree_nd *node,tree_nd *par,int dir);
void inorder(tree_nd *node,int total_elem);
void inorder_recur(tree_nd *node);
int total_nodes(tree_nd *root);
int tree_height(tree_nd *node);
boolean tree_node_delete(tree_nd *node,int data);
void level_order_spiral(tree_nd *root);
void level_order(tree_nd *root);
#endif
