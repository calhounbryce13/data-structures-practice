/*
** Author: Bryce Calhoun
** Description: Static array object with basic get index and set index operations.
*/

#include <iostream>
using namespace std;


class StaticArray{
    /*
    Description:
    */
    private:
        int capacity;
        void** array;

    public:
        StaticArray(){
            /*
            Default Constructor
            */
            this->capacity = 10;
            this->array = new void*[this->capacity];
            return;
        }
        StaticArray(int cap){
            /*
            Non-default constructor
            */
            this->capacity = cap;
            this->array = new void*[this->capacity];
            return;
        }

        // accessor for capacity
        int get_capacity(){
            return this->capacity;
        }

        void set_at_index(int index, void* value){
            /*
            Description: Function to take an integer value and void pointer 
                        to set the void pointer in an index of the array
            */
            if(index < 0 || index >= this->capacity){
                return;
            }
            this->array[index] = value;
            return;
        }

        void* get_at_index(int index){
            /*
            Description: Function to take an integer index and return a void pointer 
                        from the array
            */
            if(index < 0 || index >= this->capacity){
                void* value = NULL;
                return value;
            }
            void* value = this->array[index];
            return value;      
        }
};




