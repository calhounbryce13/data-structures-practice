#include <stdlib.h>
#include <stdio.h>
#include "BST.h"
#include <assert.h>

struct BST* BST_init(){
    struct BST* tree = (struct BST*)malloc(sizeof(struct BST));
    assert(tree);
    tree->size = 0;
    tree->root = NULL;
    return tree;
}

void BST_add(struct BST* tree, int value, void* data){
    
    tree->root = add(tree->root, value, data);
    tree->size++;
    return;
}

struct Node* add(struct Node* current, int value, void* data){
    if(current == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->data = data;
        newNode->value = value;
        return newNode;
    }
    else{
        if(value < current->value){
            current->left = add(current->left, value, data);
        }
        else{
            current->right = add(current->right, value, data);
        }
    }
    return current;
}

void BST_removeAll(struct BST* tree, int value){
    if(!tree->root) return;
    while(contains(tree, value) == 1){
        BST_remove(tree, value);
    }
}

void BST_remove(struct BST* tree, int value){
    if(!tree->root) return;
    tree->root = removeNode(tree->root, value);
    tree->size--;
    return;
}

int leftmostValue(struct Node* current){
    if(current->left == NULL){
        return current->value;
    }
    return leftmostValue(current->left);
}

void* leftmostData(struct Node* current){
    if(current->left == NULL){
        return current->data;
    }
    return leftmostData(current->left);
}

struct Node* removeLeftMost(struct Node* current){
    if(current->left == NULL){
        struct Node* temp = current->right;
        free(current);
        return temp;
    }
    else{
        current->left = removeLeftMost(current->left);
        return current;
    }
}

struct Node* removeNode(struct Node* current, int value){
    if(!current) return NULL;
    if(current->value == value){
        if(current->right == NULL){
            struct Node* temp = current->left;
            free(current);
            return temp;
        }
        else{
            current->value = leftmostValue(current->right);
            current->data = leftmostData(current->right);
            current->right = removeLeftMost(current->right);
        }
    }
    else{
        if(value < current->value){
            current->left = removeNode(current->left, value);
        }
        else{
            current->right = removeNode(current->right, value);
        }
    }
    return current;
}

int contains(struct BST* tree, int val){
    if(!tree) return 0;
    return findNode(tree->root, val);
}

int findNode(struct Node* current, int val){
    if(!current) return 0;
    if(current->value == val){
        return 1;
    }
    else{
        if(val < current->value){
            return findNode(current->left, val);
        }
        else{
            return findNode(current->right, val);
        }
    }
}

void preOrder(struct Node* current){
    if(!current) return;
    printf("\n%d", current->value);
    preOrder(current->left);
    preOrder(current->right);
}

void postOrder(struct Node* current){
    if(!current) return;
    preOrder(current->left);
    preOrder(current->right);
    printf("\n%d", current->value);

}

void inOrder(struct Node* current){
    if(!current) return;
    preOrder(current->left);
    printf("\n%d", current->value);
    preOrder(current->right);
}

void delete_tree(struct Node* current){
    if(!current) return;
    delete_tree(current->left);
    delete_tree(current->right);
    free(current);
}

void erase(struct BST* tree){
    delete_tree(tree->root);
    free(tree);
}
