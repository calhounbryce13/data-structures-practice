/*
Description: Interface & implementation of a double ended queue using a 
            doubly-linked list as the backbone data structure
Author: Bryce Calhoun (no AI assistance used)
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct DLink{
    void* value;
    struct DLink* previous;
    struct DLink* next;
};

struct Deque{
    int size;
    struct DLink* head_sentinel;
    struct DLink* tail_sentinel;
};


struct  Deque*  Deque_Init();
void Deque_addBeforeDLink(struct Deque*, struct DLink*, void*);
void Deque_addFront(struct Deque*, void*);
void Deque_addBack(struct Deque*, void*);
void Deque_removeDLink(struct Deque*, struct DLink*);
void Deque_removeBack(struct Deque*);
void Deque_removeFront(struct Deque*);
void* Deque_getFront(struct Deque*);
void* Deque_getBack(struct Deque*);


void Deque_addBeforeDLink(struct Deque* d, struct DLink* link, void* val){
    /*
    DESCRIPTION: Function to add a new link in the list before the 
                given link
    Input(s): pointer to a deque, pointer to a dlink, pointer to a void type
    Output(s): None
    Time: O(1)
    */
    assert(d && link);
    struct DLink* newLink = (struct DLink*)malloc(sizeof(struct DLink));
    assert(newLink);

    newLink->value = val;
    newLink->next = link;
    newLink->previous = link->previous;

    link->previous->next = newLink;
    link->previous = newLink;

    d->size++;

    return;
}

void Deque_addFront(struct Deque* d, void* val){
    /*
    DESCRIPTION: Function to add a new value at the front of the deque
    Input(s): pointer to a deque, pointer to a void type
    Output(s): None
    Time: O(1)
    */
    assert(d);
    Deque_addBeforeDLink(d, d->head_sentinel->next, val);
    return;
}

void Deque_addBack(struct Deque* d, void* val){
    /*
    DESCRIPTION: Function to add a new value at the back ofthe deque
    Input(s): pointer to a deque, pointer to a void type
    Output(s): None
    Time: O(1)
    */
    assert(d);
    Deque_addBeforeDLink(d, d->tail_sentinel, val);
    return;
}

void Deque_removeDLink(struct Deque* d, struct DLink* link){
    /*
    DESCRIPTION: Function to remove a given link from the deque and free it's memory
    Input(s): pointer to a deque, pointer to a dlink
    Output(s): None
    Time: O(1) 
    */
    assert(d && link);

    link->previous->next = link->next;
    link->next->previous = link->previous;

    free(link);

    d->size--;

    return;
}

void Deque_removeBack(struct Deque* d){
    /*
    DESCRIPTION: Function to remove a value from the end of the deque
    Input(s): pointer to a deque
    Output(s): None
    Time: O(1) 
    */
    assert(d);

    Deque_removeDLink(d, d->tail_sentinel->previous);

    return;
}

void Deque_removeFront(struct Deque* d){
    /*
    DESCRIPTION: Function to remove a value from the font of the deque
    Input(s): pointer to a deque
    Output(s): None
    Time: O(1) 
    */
    assert(d);

    Deque_removeDLink(d, d->head_sentinel->next);

    return;
}

void* Deque_getFront(struct Deque* d){
    /*
    DESCRIPTION: Function to get a value from the font of the deque
    Input(s): pointer to a deque
    Output(s): pointer to a void type
    Time: O(1) 
    */
    assert(d);
    return d->head_sentinel->next->value;
}

void* Deque_getBack(struct Deque* d){
    /*
    DESCRIPTION: Function to get a value from the end of the deque
    Input(s): pointer to a deque
    Output(s): pointer to a void type
    Time: O(1) 
    */
    assert(d);
    return d->tail_sentinel->previous->value;
}

struct Deque* Deque_Init(){
    /*
    DESCRIPTION: Function to initialize and return a deque structure
    Input(s): None
    Output(s): pointer to a deque structure
    Time: O(1) 
    */
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    assert(deque);

    deque->size = 0;

    deque->head_sentinel = (struct DLink*)malloc(sizeof(struct DLink));
    deque->tail_sentinel = (struct DLink*)malloc(sizeof(struct DLink));
    assert(deque->head_sentinel && deque->tail_sentinel);

    deque->head_sentinel->next = deque->tail_sentinel;
    deque->tail_sentinel->previous = deque->head_sentinel;

    deque->head_sentinel->previous = NULL;
    deque->tail_sentinel->previous = NULL;

    return deque;
}