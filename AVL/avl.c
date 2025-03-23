#include <stdlib.h>
#include <stdio.h>
#include "avl.h"
#include <assert.h>

struct Node* rotateRight(struct Node* current){
	assert(current);
	struct Node* newTop = current->left;
	assert(newTop);

	current->left = newTop->right;
	newTop->right = current;

	current->height = setHeight(current);
	newTop->height = setHeight(newTop);

	return newTop;

}

struct Node* rotateLeft(struct Node* current){
	assert(current);
	struct Node* newTop = current->right;
	assert(newTop);


	current->right = newTop->left;
	newTop->left = current;


	current->height = setHeight(current);
	newTop->height = setHeight(newTop);

	return newTop;
}


struct Node* rotateRightLeft(struct Node* current){
	assert(current);
	struct Node* child = current->right;
	if(h(child->left) > h(child->right)){
		child = rotateRight(child);
	}
	return rotateLeft(current);
}

struct Node* rotateLeftRight(struct Node* current){
	assert(current);
	struct Node* child = current->left;
	assert(child);

	if(h(child->right) > h(child->left)){
		child = rotateLeft(child);

	}
	return rotateRight(current);

}



int h(struct Node* node){
	if(node == NULL) return -1
	return node->height;
}

int setHeight(struct Node* node){
	return (1 + max(h(node->left), h(node->right)));
}
int max(int x, int y){
	if(x > y) return x;
	return y;
}

int main(){



}
