/*
    Author: Bryce Calhoun
    Description: 
*/
#include <iostream>

using namespace std;

class node{
    /*

    */

    // access specifier
    private:

        // member variable
        int value;

    public:
    node *left;
    node *right;


    // accessor
    int get_value(){

        return this->value;
    }

    // mutator
    void set_value(int value){

        this->value = value;
    }

};

class binary_search_tree{
    /*
    
    */

    private:
        int height;

    public:
        node *root;
        binary_search_tree(){
            this->height = 0;
            this->root = NULL;
        };
        void insert(int);
        node* node_prep(int);
    

};

int main(){
    binary_search_tree tree;
    tree.insert(5);
    
}

void binary_search_tree::insert(int value){
    /*
    
    */    
    node *ptr = this->node_prep(value);

    if(this->root == NULL){
        this->root = ptr;
        cout << "here" << endl;
    }

}

node* binary_search_tree::node_prep(int value){
    /*
    
    */   
    node *ptr = new node;
    ptr->set_value(value);
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;

}



