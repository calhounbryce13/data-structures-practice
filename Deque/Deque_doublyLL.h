#include <stdlib.h>
#include <stdio.h>

#define TYPE int


struct Link{
	void* value;
	struct Link* previous;
	struct Link* next;
};


struct Deque{
	int size;
	struct Link* head_sentinel;
	struct Link* tail_sentinel;
};



struct Deque* Deque_init();

void Deque_addBeforeLink(struct Deque*, struct Link*, void*);

void Deque_addFront(struct Deque*, void*);

void Deque_addBack(struct Deque*, void*);

void Deque_removeLink(struct Deque*, struct Link*);

void Deque_removeFront(struct Deque*);

void Deque_removeBack(struct Deque*);

void* Deque_getFront(struct Deque*);

void* Deque_getBack(struct Deque*);



