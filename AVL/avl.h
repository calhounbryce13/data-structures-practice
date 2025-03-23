

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



struct Node{

    int height;
    struct Node* left;
    struct Node* right;
    void* val;
};


struct AVL{
    int size;
    struct Node* root;

};


int max(int, int);

int h(struct Node*);

int setHeight(struct Node*);

struct Node* rotateRight(struct Node*);

struct Node* rotateLeft(struct Node);

struct Node* rotateLeftRight(struct Node*);

struct Node* rotateRightLeft(struct Node*);

struct Node* balanceNode(struct Node*);

struct Node* balanceTree(struct Node*);
