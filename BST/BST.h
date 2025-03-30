#include <stdlib.h>
#include <stdio.h>

struct Node{
    int value;
    void* data;
    struct Node* left;
    struct Node* right;
};

struct BST{
    struct Node* root;
    int size;
};

struct BST* BST_init();

void BST_add(struct BST*, int, void*);
struct Node* add(struct Node*, int, void*);

void BST_removeAll(struct BST*, int);
void BST_remove(struct BST*, int);
struct Node* removeNode(struct Node*, int);
int leftmostValue(struct Node*);
void* leftmostData(struct Node*);
struct Node* removeLeftMost(struct Node*);

int contains(struct BST*, int);
int findNode(struct Node*, int);

void erase(struct BST*);
void delete_tree(struct Node*);

void preOrder(struct Node*);
void postOrder(struct Node*);
void inOrder(struct Node*);

