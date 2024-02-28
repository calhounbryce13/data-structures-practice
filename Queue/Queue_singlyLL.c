/*
** Author: Bryce Calhoun
** Description: Queue ADT implemented with a singly liked list.
*/

#include "singlyLL.c"
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    /*
    Description: Queue structure defined with an integer variable to track the size
                and a singlyLL object as the underlying data structure
    */
    int size;
    struct singlyLL* queue;
};


struct Queue* create_queue(){
    /*
    Description: Function to allocate memory for a queue object, initialize its attributes, and 
                return a pointer to it
    */
    struct Queue* q = malloc(sizeof(struct Queue));
    q->queue = create_list();
    q->size = 0;
};

int queue_is_empty(struct Queue* q){
    /*
    Description: Function to return 1(true) if the queue is empty and 0(false) otherwise
    */
    if(q->size == 0){
        return 1;
    }
    return 0;
};

void enqueue(struct Queue* q, void* value){
    /*
    Description: Function to take a void pointer and enqueue to the end of the queue
    */
    insert_back(q->queue, value);
    q->size++;
};

void* dequeue(struct Queue* q){
    /*
    Description: Function to remove a value from the front of the queue and return it
    */
    int empty = queue_is_empty(q);
    if(empty){
        printf("EMPTY QUEUE");
        return NULL;
    }
    void* value = remove_front(q->queue);
    q->size--;
    return value;
};

void* peek(struct Queue* q){
    /*
    Description: Function to read a value from the front of the queue without removing it
    */
    void* value = get_front(q->queue);
    return value;
};
