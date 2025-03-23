


#include <stdlib.h>
#include <stdio.h>
#include "Deque_doublyLL.h"

#include <assert.h>


struct Deque* Deque_init(){
	struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
	assert(dq);

	dq->size = 0;
	dq->head_sentinel = (struct Link*)malloc(sizeof(struct Link));
	dq->tail_sentinel = (struct Link*)malloc(sizeof(struct Link));

	assert(dq->head_sentinel && dq->tail_sentinel);

	dq->head_sentinel->previous = NULL;
	dq->tail_sentinel->next = NULL;

	dq->head_sentinel->next = dq->tail_sentinel;
	dq->tail_sentinel->previous = dq->head_sentinel;

	return dq;

}

void Deque_addBeforeLink(struct Deque* dq, struct Link* link, void* value){
	assert(dq && link);

	struct Link* newNode = (struct Link*)malloc(sizeof(struct Link));
	assert(newNode);

	newNode->value = value;
	
	newNode->next = link;
	newNode->previous = link->previous;

	newNode->next->previous = newNode;
	newNode->previous->next = newNode;

	dq->size++;


	return;
}


void Deque_addFront(struct Deque* dq, void* value){
	assert(dq);

	Deque_addBeforeLink(dq, dq->head_sentinel->next, value);

	return;

}

void Deque_addFront(struct Deque* dq, void* value){
	assert(dq);
	Deque_addBeforeLink(dq, dq->tail_sentinel, value);

	return;

}

void Deque_removeLink(struct Deque* dq, struct Link* link){
	assert(dq && link);


	link->previous->next = link->next;
	link->next->previous = link->previous;

	free(link);


	dq->size--;

}

void Deque_removeFront(struct Deque* dq){
	assert(dq);

	Deque_removeLink(dq, dq->head_sentinel->next);

	return;

}

void Deque_removeBack(struct Deque* dq){
	assert(dq);

	Deque_removeLink(dq, dq->tail_sentinel->previous);
	
	return;

}


void* Deque_getFront(struct Deque* dq){
	assert(dq->head_sentinel->next);


	return dq->head_sentinel->next->value;
}


void* Deque_getBack(struct Deque* dq){
	assert(dq->tail_sentinel->previous);

	return dq->tail_sentinel->previous->value;

}






int main(){

	struct Deque* myDQ = Deque_init();


	for(int x = 0; x < 20; x++){
		int* ptr = (int*)malloc(sizeof(int));
		ptr = &x
		Deque_addFront(myDQ, ptr); 
	
	}




}
