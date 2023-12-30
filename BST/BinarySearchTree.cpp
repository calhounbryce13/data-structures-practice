/*
    Author: Bryce Calhoun
    Description: Complete binary tree skeleton whith operations: insert, remove, search, and delete tree. Additionally,
                 3 different traversals: Preorder, Inorder, and Postorder. 
                 Memory allocated on the heap and de-allocated recursively.
*/

#include <iostream>

using namespace std;

class node{
    /*
    DESCRIPTION: Class definition for an individual node in the binary search tree.
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
    DESCRIPTION: A class defintion for the binary search tree structure.
    */

    private:
        int numNodes;

    public:
        node *root;

        // default constructor
        binary_search_tree(){
            this->numNodes = 0;
            this->root = NULL;
        };

        node* node_prep(int);
        node* find_parent(int);
        node* inorder_successor(node*);

        // OPERATIONS:
        void insert(int);
        node* tree_search(int);
        void remove(int);
        void delete_tree(node*);
        
        // tree traversals
        void Preorder_trav(node*);
        void Inorder_trav(node*);
        void Postorder_trav(node*);

        // accessors
        int get_numNodes(){
            return this->numNodes;
        }


        // mutators
        void set_numNodes(int value){
            this->numNodes = value;
        }


        void inc_numNodes(){
            this->numNodes++;
        }
    

};

int main(){
    
    

}

void binary_search_tree::insert(int value){
    /*
    DESCRIPTION: Function to insert a new node given a value into the binary
                 search tree.
    */ 

    node *ptr = this->node_prep(value);

    if(this->root == NULL){
        this->root = ptr;
        this->inc_numNodes();
    }
    else{
        node *current = this->root;

        while(true){
            if(current->get_value() > value){
                if(current->left != NULL){
                    current = current->left;
                }
                else{
                    current->left = ptr;
                    this->inc_numNodes();
                    return;
                }
            }
            else{
                if(current->right != NULL){
                    current = current->right;

                }
                else{
                    current->right = ptr;
                    this->inc_numNodes();
                    return;

                }
            }
        }
    }
}


node* binary_search_tree::node_prep(int value){
    /*
    DESCRIPTION: Function to take an integer value and make 
                 a dynamically allocated node for it.
                 Will return a pointer to the node.
    */ 

    node *ptr = new node;  
    ptr->set_value(value);
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;

}

node* binary_search_tree::find_parent(int value){
    /*
    DESCRIPTION: Helper function to return the parent node of
                a specifeid value for removal purposes.
    */

    node *current = this->root;

    if(current->get_value() == value){
        cout << "not parent for root node" << endl;
        return NULL;
    }
    while(current->left->get_value() != value && current->right->get_value() != value){
        if(value < current->get_value()){
            if(current->left != NULL){
                current = current->left;

            }
            else{
                return NULL;

            }
        }
        else{
            if(current->right != NULL){
                current = current->right;
            }
            else{
                return NULL;
                
            }
        }

    }

    return current;

}

node* binary_search_tree::inorder_successor(node* toBeRemoved){
    /*
    DESCRIPTION: Function to locate and return the inorder successor node of
                 a specified node in the tree.
    */

    node *current = toBeRemoved;
    current = current->right;
    while(current->left != NULL){
        current = current->left;
    }
    return current;

}


void binary_search_tree::Preorder_trav(node *root){
    /*
    DESCRIPTION: Function to make a preorder traversal of the binary search tree.
    */

    if(root == NULL){
        return;
    }
    else{
        cout << " " << root->get_value() << endl;
        this->Preorder_trav(root->left);
        this->Preorder_trav(root->right);
    }

}

void binary_search_tree::Inorder_trav(node* root){
    /*
    DESCRIPTION: Function to make an inorder traversal of the binary search tree.
    */

    if(root == NULL){
        return;
    }
    else{ 
        this->Inorder_trav(root->left);
        cout << " " << root->get_value() << endl;
        this->Inorder_trav(root->right);

    }

}

void binary_search_tree::Postorder_trav(node* root){
    /*
    DESCRIPTION: Function to make a postorder traversal of the binary search tree.
    */

   if(root == NULL){
        return;
    }
    else{ 
        this->Postorder_trav(root->left);
        this->Postorder_trav(root->right);
        cout << " " << root->get_value() << endl;

    }
}

node* binary_search_tree::tree_search(int value){
    /*
    DESCRIPTION: Function to search for a value in the binary search tree.
    */

    node *current = this->root;
    if(current->get_value() == value){
        return current;
    }
    while(current != NULL){
        if(current->get_value() == value){
            return current;

        }
        else if(current->get_value() < value){
            current = current->right;

        }
        else if(current->get_value() > value){
            current = current->left;
        }
    }
    cout << "value not found" << endl;
    return NULL;
     
}

void binary_search_tree::remove(int value){
    /*
    DESCRIPTION: Function to remove a single node from the binary
                search tree.
    */

    node *removeNode = this->tree_search(value);

    if(removeNode == NULL){
        cout << "\nvalue not in tree" << endl;
        return;
    }
    else{
        node *parentNode = this->find_parent(value);

        if(removeNode->left == NULL && removeNode->right == NULL){
            if(parentNode){
                if(parentNode->left->get_value() == value){
                    
                    delete removeNode;
                    parentNode->left = NULL;
                    
                    return;
                }
                else if(parentNode->right->get_value() == value){
                    delete removeNode;
                    parentNode->right = NULL;
                    return;

                }
                
            }
            else{
                delete removeNode;
                return;
            }

        }
        else if(removeNode->left == NULL ^ removeNode->right == NULL){
            
            if(removeNode->left){
           
                if(parentNode->left->get_value() == value){
                    parentNode->left = removeNode->left;

                }
                else if(parentNode->right->get_value() == value){
                    parentNode->right = removeNode->left;

                }

            }
            else{
                if(parentNode->left->get_value() == value){
                    parentNode->left = removeNode->right;

                }
                else if(parentNode->right->get_value() == value){
                    parentNode->right = removeNode->right;

                }

            }
            delete removeNode;
            return;

        }
        else{
            
            node *successor = this->inorder_successor(removeNode);
            if(parentNode){

                   // re-assign parent to point to inorder successor
                if(parentNode->left->get_value() == value){
                    parentNode->left = successor;

                }
                else if(parentNode->right->get_value() == value){
                    cout << "here" << endl;
                    parentNode->right = successor;

                }
            }
            else{
                cout << "cannot remove the root" << endl;
                return;
            }

            // successor's left node needs to point to the removeNode's left child
            successor->left = removeNode->left;

            delete removeNode;
            return;

        }

    }

}

void binary_search_tree::delete_tree(node* root){
    /*
    DESCRIPTION: Function to recursively delete a binary tree given the tree root,
                 using a post order traversal.
    */

    if(root == NULL){
        return;
    }
    else{ 
        this->delete_tree(root->left);
        this->delete_tree(root->right);
        delete root;
    

    }
}
