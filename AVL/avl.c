

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

struct AVL* initAVL(){
    struct AVL* myTree = (struct AVL*)malloc(sizeof(struct AVL));
    myTree->size = 0;
    myTree->root = NULL;

    return myTree;

}

struct Node* addAVL(struct Node* current, TYPE val){
    /*
    Description: Recursive function to add a value to an avl tree
    Input(s): tree's root node (struct Node*)
    Output(s): the new node (struct Node*)
    */

    if(current == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->val = val;
        newNode->left = newNode->right = NULL;
        newNode->height = 0;

        return newNode;
    }
    else{
        if(val < current->val){
            current->left = addAVL(current->left, val);
        }
        else{
            current->right = addAVL(current->right, val);
        }
    }
    return balanceNode(current);

}

struct Node* _balanceNode(struct Node* current){
    /*
    Description: 
    Input(s):
    Output(s): 
    */
    int flag = _h(current->right) - _h(current->left);
    if(flag < -1){
        current = _rotateFullRight(current);
    }
    else if(flag > 1){
        current = _rotateFullLeft(current);
    }
    return current;

}

struct Node* _rotateFullRight(struct Node* current){
    /*
    Description: 
    Input(s):
    Output(s): 
    */
    assert(current);
    struct Node* child = current->left;
    assert(child);

    if(_h(child->right) > _h(child->left)){
        child = _rotateLeft(child);
    }
    return _rotateRight(current);

}

struct Node* _rotateFullLeft(struct Node* current){
    /*
    Description: 
    Input(s):
    Output(s): 
    */
    assert(current);
    struct Node* child = current->right;
    assert(child);

    if(_h(child->right) > _h(child->left)){
        child = _rotateRight(child);

    }
    return _rotateLeft(current);
}

struct Node* _rotateRight(struct Node* current){
    /*
    Description: 
    Input(s):
    Output(s): 
    */
    assert(current);
    struct Node* newTop = current->left;
    assert(newTop);

    current->left = newTop->right;
    newTop->right = current;

    _setHeight(current);
    _setHeight(newTop);

    return newTop;
}

struct Node* _rotateLeft(struct Node* current){
    /*
    Description: 
    Input(s):
    Output(s): 
    */
    assert(current);
    struct Node* newTop = current->right;
    assert(newTop);

    current->right = newTop->left;
    newTop->left = current;

    _setHeight(current);
    _setHeight(newTop);

    return newTop;
}

struct Node* _balanceBST(struct Node* current){
    /*
    Description: 
    Input(s):
    Output(s): 
    */
    if(!current){
        return NULL;
    }
    else{
        current->left = _balanceBST(current->left);
        current->right = _balanceBST(current->right);
    }
    return _balanceNode(current);

}

int _h(struct Node* node){
    /*
    Description: Function to return the height of a valid AVL node
                or return -1;
    Input(s): a single node (struct Node*)
    Output(s): height of the node (int)
    */
    if(!node) return -1;
    return node->height;
}

void _setHeight(struct Node* node){
    /*
    Description: Function defined to set the height of a given AVL 
                node based on its children
    Input(s): a single node (struct Node*)
    Output(s): None
    */
    if(_h(node->left) > _h(node->right)){
        node->height = 1 + _h(node->left);
        return;
    }
    node->height = 1 + _h(node->right);
    return;
}

void traversal_PostOrder(struct Node* current){
    if(!current) return;

    traversal_PostOrder(current->left);
    traversal_PostOrder(current->right);
    printf("\n node value: %d", current->val);

    return;

}
int main(){


    struct AVL* myTree = initAVL();

    for(int i = 0; i < 100; i++){
        myTree->root = addAVL(myTree->root, i * 2);
    }

    traversal_PostOrder(myTree->root);



}