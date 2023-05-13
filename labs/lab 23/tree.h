#ifndef _Tree_H_
#define _Tree_H_

struct tnode {
    float value;
    struct tnode *son;
    struct tnode *brother;
    struct tnode *parent;
};
typedef struct tnode node;
typedef struct {
    node *root;
} Tree;


node *create_node(float f, node *par);
Tree *create_tree(float f);
node *search_tree(node *t, float f);
void add_node_in_tree(Tree *tree, float par_f, float f);
void delete_node(Tree *tree, float f);
void Delete(node *t);
void Pre_Order(node *t, int x);
void Post_Order(node *t);
void In_Order(node *t);
#endif