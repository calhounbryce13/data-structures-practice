/*
Description: Dynamic array interface in c programming, supports elements of any type
Author: Bryce Calhoun
*/

#include <stdlib.h>
#include <stdio.h>

struct DynArr{
    int size;
    int capacity;
    void** data;
};

struct DynArr* DynArr_init(int);
void append(struct DynArr*, void*);
void* get_at_index(struct DynArr*, int);
void set_at_index(struct DynArr*, int, void*);
int get_size(struct DynArr*);