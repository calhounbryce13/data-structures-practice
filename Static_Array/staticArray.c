#include <stdlib.h>
#include <stdio.h>


struct StaticArray{
    /*
    Description: Static array structre defined with a double void pointer and an integer
                to track the capacity
    */
    int capacity;
    void** array;

};

struct StaticArray* create_array(int cap){
    /*
    Description: Function to allocate memory for a static array structre and return a pointer to it
    */
    if(cap <= 0){
        printf("NO NEGATIVE CAPACITY");
        return NULL;
    }
    struct StaticArray* array = malloc(sizeof(struct StaticArray));
    array->capacity = cap;
    array->array = malloc(sizeof(void*) * (array->capacity));

};

void set_at_index(struct StaticArray* array, int index, void* value){
    /*
    Description: Function to take a void pointer and insert it at a given index
    */
    if(index < 0 || index >= array->capacity){
        printf("INDEX OUT OF RANGE");
        return NULL;
    }
    array->array[index] = value;
    return;
};

void* get_at_index(struct StaticArray* array, int index){
    /*
    Description: Function to return a void pointer value from a given index and return it
    */
    if(index < 0 || index >= array->capacity){
        printf("INDEX OUT OF RANGE");
        return NULL;
    }
    return array->array[index];
};

