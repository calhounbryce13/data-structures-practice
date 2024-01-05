/*
Author: Bryce Calhoun
Description: Singly-Linked list implementation using malloc() to allocate memory on 
             the heap and free() to de-allocate memory. Operations: Insert, Remove, Search
             Display(forward), Delete list.
             
*/

#include <stdlib.h>
#include <stdio.h>

struct Node{
    /*
    DESCRIPTION: A struct definition for a single node in the linked list.
                an integer value member and node pointer member, to reference the 
                next node in the list.
    */

    int value;
    struct Node *next;

};

struct singlyLL{
    /*
    DESCRIPTION: A struct definition for the singly-linked list. A size member to track
                 the number of elements, and a node pointer to reference the head of the list.
    */
    int size;
    struct Node *head;

};


struct singlyLL* create_list(){
    /*
    DESCRIPTION: Function to allocate heap memory for a linked list struct pointer,
                 as well as initialize member variables. The function will return the pointer.
    */
    struct singlyLL *ptr = malloc(sizeof(struct singlyLL));
    ptr->head = NULL;
    ptr->size = 0;

    return ptr;

}

void insert(struct singlyLL *list, int value){
    /*
    DESCRIPTION: Function to insert an integer value into the list given the value.
                 TIME: O(n).
    */
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->value = value;
    ptr->next = NULL;
    if(list->head == NULL){
        list->head = ptr;
    }
    else{
        struct Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = ptr;
    }
    list->size++;
    return;

}

int remove_node(struct singlyLL *list, int value){
    /*
    DESCRIPTION: Function to remove a node from the list and free the memory. The
                 value of the node will be returned.
                 TIME:O(n).
    */
    if(list->head == NULL){
        printf("\nempty list\n");
        return 0;
    }
    else{
        int x = 0;
        struct Node *current = list->head;
        struct Node *previous = list->head;
        while(current != NULL){
            if(current->value == value){
                int res = current->value;
                if(x){
                    if(current->next == NULL){
                        previous->next = NULL;
                    }
                    else{
                        previous->next = current->next;

                    }
                }
                free(current);
                list->size--;
                return res;

            }
            current = current->next;
            if(x){
                previous = previous->next;
            }
            x = 1;
        }
        printf("\nvalue not found\n");
    }
    list->size--;
    return 0;

}

struct Node* search(struct singlyLL *list, int value){
    /*
    DESCRIPTION: Function to search for a node in the list by value.
                 The node will be returned.
                 TIME: O(n).
    */
    if(list->head == NULL){
        printf("\nempty list\n");
        return NULL;
    }
    else{
        struct Node *current = list->head;
        while(current != NULL){
            if(current->value == value){
                return current;
            }
            current = current->next;
        }
        printf("\nvalue not found\n");
        return NULL;
    }

}

void display(struct singlyLL *list){
    /*
    DESCRIPTION: Function to display the list in head-first order.
                 TIME: O(n).
    */
    if(list->head == NULL){
        printf("\nempty list\n");
        return;
    }
    struct Node *current = list->head;
    while(current != NULL){
        printf("\n %d \n", current->value);
        current = current->next;
    }
    return;

}

void delete_list(struct singlyLL *list){
    /*
    DESCRIPTION: Function to delete the whole list and set the head to null.
                 The memory is freed.
                 TIME: O(n).
    */
    if(list->head == NULL){
        printf("\nempty list\n");
        return;
    }
    else{
        struct Node *current = list->head;
        struct Node *next;
        while(current != NULL){
            next = current->next;
            free(current);
            current = next;
        }
        list->head = NULL;
        return;
    }

}
