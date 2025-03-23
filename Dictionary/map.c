


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define KTYPE int


struct Data{
	KTYPE key;
	void* val;
}

struct Link{
	struct Data d;
	struct Link* next;
}

struct Dictionary{
	int size;
	int length;
	struct Link** table;

}



struct Dictionary* Map_init(int length){
	assert(length > 0);
	struct Dictionary* d = (struct Dictionary*)malloc(sizeof(struct Dictionary));
	assert(d);


	d->size = 0;
	d->length = length;

	d->table = (struct Link**)malloc(sizeof(struct Link*) * length);
	for(int i = 0; i < d->length; i++){
		d->table[i] = (struct Link*)malloc(sizeof(struct Link));
		d->table[i]->next = NULL;
	
	}

	return d;

}


void Map_add(struct Dictionary* d, KTYPE key, void* value){
		assert(d);
		int hash_index = k % d->length;
		struct Data d = malloc(sizeof(struct Data));
		d.key = key;
		d.val = value;

		struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
		assert(newLink);
		newLink->next = d->table[hash_index]->next;

		d->table[hash_index]->next = newLink;

		d->size++;

		float lf = d->size / d->length;
		if(lf > 0.75){
			resize(d);
		}

		return;

}





int main(){


	struct Dictionary* d = Map_init(10);






}
