/*
** Author: Bryce Calhoun
** Description: Singly Linked List implemented with both a head and tail sentinel node.
*/

#include <stdlib.h>
#include <stdio.h>


struct Node{
    /*
    Description: Node structre defined with a void pointer and a 
                Node pointer to point to the next node in the list
    */
    void* value;
    struct Node* next;
};


struct singlyLL{
    /*
    Description: Singly linked list structre defined with an integer variable to track size 
                as well as a head sentinel and a tail sentinel
    */
    int size;
    struct Node* head_sentinel;
    struct Node* tail_sentinel;
};


struct singlyLL* create_list(){
    /*
    Description: Function to allocate memory for a singlyLL struct and 
                initialize its attributes. Function woll return a pointer 
                to the struct
    */
    struct singlyLL* list = malloc(sizeof(struct singlyLL));
    list->size = 0;

    list->head_sentinel = malloc(sizeof(struct Node));
    list->tail_sentinel = malloc(sizeof(struct Node));

    list->head_sentinel->next = NULL;
    list->tail_sentinel->next = NULL;

    return list;
}

int is_empty(struct singlyLL* list){
    /*
    Description: Function to return 1 (true) if a list is empty and 0 (false) otherwise
    */
    if(list->size == 0){
        return 1;
    }
    return 0;

}

void insert_front(struct singlyLL* list, void* value){
    /*
    Description: Function to take a void pointer and insert it in the front of a singlyLL 
                object
    */
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    int empty = is_empty(list);
    if(empty){
        newNode->next = NULL;
        list->head_sentinel->next = newNode;
        list->tail_sentinel->next = newNode;
    }
    else{
        newNode->next = list->head_sentinel->next;
        list->head_sentinel->next = newNode;
    }
    list->size++;
    return;
}

void* remove_front(struct singlyLL* list){
    /*
    Description: Function to remove a node from the front of a singlyLL
                and return the void pointer value
    */
    int empty = is_empty(list);
    if(empty){
        printf("EMPTY LIST");
        return NULL;
    }
    void* value = list->head_sentinel->next->value;

    struct Node* tempNode = list->head_sentinel->next;
    list->head_sentinel->next = list->head_sentinel->next->next;

    free(tempNode);

    list->size--;
    return value;
}

void insert_back(struct singlyLL* list, void* value){
    /*
    Description: Function to take a void pointer and insert it in the back of a singlyLL 
                object
    */
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    int empty = is_empty(list);
    if(empty){
        list->head_sentinel->next = newNode;
        list->tail_sentinel->next = newNode;
    }
    else{
        list->tail_sentinel->next->next = newNode;
        list->tail_sentinel->next = newNode;
    }

    list->size++;
    return;

}

void* get_front(struct singlyLL* list){
    int empty = is_empty(list);
    if(empty){
        printf("EMPTY LIST");
        return NULL;
    }
    
    void* value = list->head_sentinel->next->value;
    return value;

}

