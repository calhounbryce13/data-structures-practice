/*
** Author: Bryce Calhoun
** Description: Queue ADT implemented with a singly liked list.
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node{
    void* value;
    struct Node* next;
    struct Node* previous;

    
};

struct Queue{
    int size;
    struct Node* head_sentinel;
    struct Node* tail_sentinel;
};

struct Queue* Queue_init();

void Queue_enqueue(struct Queue*, void*);

void Queue_dequeue(struct Queue*);

void* Queue_peek(struct Queue*);

struct Queue* Queue_init(){
    struct Queue* myQ = (struct Queue*)malloc(sizeof(struct Queue));
    assert(myQ);

    myQ->size = 0;

    myQ->head_sentinel = (struct Node*)malloc(sizeof(struct Node));
    myQ->tail_sentinel = (struct Node*)malloc(sizeof(struct Node));

    assert(myQ->head_sentinel && myQ->tail_sentinel);

    myQ->head_sentinel->next = myQ->tail_sentinel;
    myQ->tail_sentinel->previous = myQ->head_sentinel;

    myQ->head_sentinel->previous = NULL;
    myQ->tail_sentinel->next = NULL;

    return myQ;
    
}

void Queue_enqueue(struct Queue* q, void* val){
	assert(q);
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	assert(newNode);

	newNode->value = val;

	newNode->next = q->tail_sentinel;
	newNode->previous = q->tail_sentinel->previous;

	newNode->previous->next = newNode;
	newNode->next->previous = newNode;

	q->size++;

	return;

}
void Queue_dequeue(struct Queue* q){
	assert(q);
	struct Node* link = q->head_sentinel->next;
	assert(link);

	link->previous->next = link->next;
	link->next->previous = link->previous;

	free(link);

	q->size--;

	return;
};

void* Queue_peek(struct Queue* q){
	assert(q->head_sentinel->next);
	if(q->size > 0){
		return q->head_sentinel->next->value;
	}
	return NULL;

};

int main(){
	struct Queue* q = Queue_init();

	for(int i = 0; i < 12; i++){
		int* x = (int*)malloc(sizeof(int));
		Queue_enqueue(q, x); 
	
	}



	printf("first enqued element: %d",*((int*)Queue_peek(q)));


}

