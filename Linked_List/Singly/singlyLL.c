#include <stdlib.h>
#include <stdio.h>


struct Node{
    void* value;
    struct Node* next;
};


struct singlyLL{
    int size;
    struct Node* head_sentinel;
    struct Node* tail_sentinel;
};


struct singlyLL* create_list(){
    struct singlyLL* list = malloc(sizeof(struct singlyLL));
    list->size = 0;

    list->head_sentinel = malloc(sizeof(struct Node));
    list->tail_sentinel = malloc(sizeof(struct Node));

    list->head_sentinel->next = NULL;
    list->tail_sentinel->next = NULL;

    return list;
}

int is_empty(struct singlyLL* list){
    if(list->size == 0){
        return 1;
    }
    return 0;

}

void insert_front(struct singlyLL* list, void* value){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    int empty = is_empty(list);
    if(empty){
        newNode->next = NULL;
        list->head_sentinel->next = newNode;
        list->tail_sentinel->next = newNode;
    }
    else{
        newNode->next = list->head_sentinel->next;
        list->head_sentinel->next = newNode;
    }
    list->size++;
    return;
}

void* remove_front(struct singlyLL* list){

    int empty = is_empty(list);
    if(empty){
        printf("EMPTY LIST");
        return NULL;
    }
    void* value = list->head_sentinel->next->value;

    struct Node* tempNode = list->head_sentinel->next;
    list->head_sentinel->next = list->head_sentinel->next->next;

    free(tempNode);

    list->size--;
    return value;
}

void insert_back(struct singlyLL* list, void* value){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    int empty = is_empty(list);
    if(empty){
        list->head_sentinel->next = newNode;
        list->tail_sentinel->next = newNode;
    }
    else{
        list->tail_sentinel->next->next = newNode;
        list->tail_sentinel->next = newNode;
    }

    list->size++;
    return;

}


int main(){
    struct singlyLL* list = create_list();


    for(int y = 0; y < 50; y++){
        void* ptr = (y + 1);
        insert_back(list, ptr);
    }
    printf("size: %d \n", list->size);
    printf("empty: %d \n", is_empty(list));


    for(int y = 0; y < 50; y++){
        void* value = remove_front(list);
        printf("value: %d \n", value);
    }
    printf("size: %d \n", list->size);
    printf("empty: %d \n", is_empty(list));
}