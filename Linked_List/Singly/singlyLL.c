#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/*
DESCRIPTION:
Input(s):
Output(s):
Time: 
*/

struct Node{
    void* value;
    struct Node* next;
};


struct singlyLL{
    int size;
    struct Node* head_sentinel;
};


struct singlyLL* singlyLL_Init(){
    /*
    DESCRIPTION: allocates memory for a singlyLL and returns a pointer to it
    Input(s): None
    Output(s): pointer to a singlyLL structure
    Time: O(1)
    */

    struct singlyLL* list = (struct singlyLL*)malloc(sizeof(struct singlyLL));
    assert(list);

    list->size = 0;
    list->head_sentinel = (struct Node*)malloc(sizeof(struct Node));
    assert(list->head_sentinel);

    list->head_sentinel->next = NULL;

    return list;
}

int singlyLL_isEmpty(struct singlyLL* list){
    if(list->size == 0){
        return 1;
    }
    return 0;
}

void singlyLL_insertFront(struct singlyLL* list, void* value){
    /*
    DESCRIPTION: Inserts a value at the front of the list
    Input(s): pointer to a singlyLL, pointer to a void type
    Output(s): None
    Time: O(1)
    */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    assert(newNode);
    newNode->value = value;
    newNode->next = list->head_sentinel->next;
    list->head_sentinel->next = newNode;
    list->size++;

    return;
}

void singlyLL_removeFront(struct singlyLL* list){
    /*
    DESCRIPTION: Removes the front element from the list
    Input(s): pointer to a singlyLL
    Output(s): None
    Time: O(1)
    */
    assert(list);
    if(list->size > 0){
        struct Node* temp = list->head_sentinel->next;
        list->head_sentinel->next = temp->next;
        free(temp);
        list->size--;
    }
    return;
}

void* singlyLL_getFront(struct singlyLL* list){
    /*
    DESCRIPTION: Accesses the front element from the list
    Input(s): pointer to a singlyLL
    Output(s): None
    Time: O(1)
    */
    assert(list);
    if(list->size > 0){
        return list->head_sentinel->next->value;
    }
    return NULL;
}

void singlyLL_insertBack(struct singlyLL* list, void* value){
    /*
    DESCRIPTION: Inserts a value at the very back of the list
    Input(s): pointer to a singlyLL, pointer to a void type
    Output(s): None
    Time: O(n)
    */
    assert(list);
    if(list->size == 0){
        singlyLL_insertFront(list, value);
        return;
    } 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    assert(newNode);

    newNode->value = value;
    newNode->next = NULL;

    struct Node* current = list->head_sentinel->next;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
    list->size++;

    return;
}

void singlyLL_removeBack(struct singlyLL* list, void* value){
    /*
    DESCRIPTION: Removes the value from the very back of the list
    Input(s): pointer to a singlyLL, pointer to a void type
    Output(s): None
    Time: O(n)
    */
    assert(list);
    if(list->size > 0){
        struct Node* previous = list->head_sentinel;
        struct Node* current = list->head_sentinel->next;
        while(current->next != NULL){
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        free(current);
        list->size--;
    }
    return;


}


int main(){
    struct singlyLL* list = create_list();

}