#include <stdlib.h>
#include <stdio.h>

#define KTYPE char*
#define LOAD_FACTOR 0.75


struct Data{
	KTYPE key;
	void* value;
};

struct Link{
	struct Data d;
	struct Link* next;
};

struct Map{
	struct Link** table;
	int size;
	int length;

};

long _hash(char*);

void Map_init(struct Map*, int);

void Map_add(struct Map*, KTYPE, void*);

void _resize(struct Map*);

int contains(struct Map*, KTYPE);

void Map_remove(struct Map*, KTYPE);

void* Map_contains(struct Map*, KTYPE);
