/*
DESCRIPTION: dynamic array implementation in c programming
Author: Bryce Calhoun
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DynArr.h"



struct DynArr* DynArr_init(int cap){
    if(cap <= 0) return NULL;
    struct DynArr* array = (struct DynArr*)malloc(sizeof(struct DynArr));
    array->capacity = cap;
    array->size = 0;
    array->data = (void**)malloc(sizeof(void*) * cap);
    return array;
}

void resize(struct DynArr* list){
    if(!list) return;
    int oldcap = list->capacity;
    int newCap = oldcap * 2;

    void** newData = (void**)malloc(sizeof(void*) * newCap);
    for(int i = 0; i < oldcap; i++){
        newData[i] = list->data[i];
    }
    free(list->data);
    list->data = newData;
    list->capacity = newCap;

    return;
}

void append(struct DynArr* list, void* value){
    if(!list) return;
    if(list->size == list->capacity) resize(list);
    list->data[list->size] = value;
    list->size++;
}

void* get_at_index(struct DynArr* list, int index){
    if(!list || index < 0 || index > list->capacity) return NULL;
    return list->data[index];

}

void set_at_index(struct DynArr* list, int index, void* value){
    if(!list || index < 0 || index > list->size) return;
    if(index == list->size){
        append(list, value);
        return;
    }
    else{
        free(list->data[index]);
    }
    list->data[index] = value;
    return;
}

int get_size(struct DynArr* list){
    return list->size;
}

void delete_list(struct DynArr* list, int var){
    if(!list || (var < 0 || var > 1)) return;
    int end_iter = 0;
    if(var == 0){
        end_iter = list->size;
    }
    else{
        end_iter = list->capacity;
    }
    for(int x = 0; x < end_iter; x++){
        if(list->data[x] != NULL) free(list->data[x]);
    }
    free(list);
}
