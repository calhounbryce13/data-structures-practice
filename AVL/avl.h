

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TYPE int



struct Node{

    int height;
    struct Node* left;
    struct Node* right;
    TYPE val;
};


struct AVL{
    int size;
    struct Node* root;

};