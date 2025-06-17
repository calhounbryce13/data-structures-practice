#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"



void Map_init(struct Map* map, int length){
	if((!map) || (length < 0)) return;
	map->table = (struct Link**)malloc(sizeof(struct Link*) * length);
	map->size = 0;
	map->length = length;

	for(int x = 0; x < map->length; x++){
		map->table[x] = (struct Link*)malloc(sizeof(struct Link));
		map->table[x]->next = NULL;
	
	}
	return;
}


long _hash(char* key){
	long hash = 5381;
	int c;
	while((c = *key++)){
		hash = ((hash << 5) + hash) + c;
	
	}
	return hash;

}


void Map_remove(struct Map* map, KTYPE key){
	if(!map) return;

	int index = abs(_hash((char*)key)) % map->length;
	struct Link* current = map->table[index]->next;
	struct Link* previous = map->table[index];

	while(current != NULL){
		if(current->d.key == key){
			previous->next = current->next;
			free(current);
			map->size--;
			return;
		}
		previous = current;
		current = current->next;
		
	}

	return;

}


void _resize(struct Map* map){
	int oldlength = map->length;
	struct Link** oldTable = map->table;


	Map_init(map, map->length * 2);

	struct Link* previous;
	struct Link* current;

	for(int x = 0; x < oldlength; x++){
		current = oldTable[x]->next;
		while(current != NULL){
			Map_add(map, current->d.key, current->d.value);
			previous = current;
			current = current->next;
			free(previous);
		}
	
	}
	free(oldTable);

	return;

}

int contains(struct Map* map, KTYPE key){
	int index = abs(_hash((char*)key)) % map->length;

	struct Link* current = map->table[index]->next;
	while(current != NULL){
		if(current->d.key == key){
			return 1;
		
		}
	
	}
	return 0;

}

void Map_add(struct Map* map, KTYPE key, void* value){
	Map_remove(map, key);
	int index = abs(_hash((char*)key)) % map->length;

	struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
	newLink->d.key = key;
	newLink->d.value = value;

	newLink->next = map->table[index]->next;

	map->table[index]->next = newLink;

	map->size++;

	if((map->size / map->length) > LOAD_FACTOR) _resize(map);

	return;

}


void* Map_contains(struct Map* map, KTYPE key){
	int index = abs(_hash((char*)key)) % map->length;

	struct Link* current = map->table[index]->next;

	while(current != NULL){
		if(current->d.key == key){
			return current->d.value;
		}
		current = current->next;
	}

	void* ptr = NULL;
	return ptr;


}







int main(){
	struct Map* map = (struct Map*)malloc(sizeof(struct Map));
	Map_init(map, 10);
	printf("table length: %d", map->length);
	/////////////////////////////////////////////////////////
	char* value = "some given value";
	Map_add(map, "some given key", (void*)value);
	

	printf("\n table length after insert(s): %d", map->length);
	
	printf("\n map contains inserted key: %d",contains(map, "some given key"));

	printf("\n value of key: %s", (char*)Map_contains(map, "some given key"));

}
