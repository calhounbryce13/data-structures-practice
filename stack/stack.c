/*
    Author: Bryce Calhoun
    Description: Program implements a stack abstract data type using a
                 singly linked list allocated on the heap. Operations: create,
                 push, and pop.
*/
#include <stdio.h>
#include <stdlib.h>



struct Node{
    /*
    Description: Node struct to contain a void pointer
                 to the value stored and a pointer
                 to the next node in the stack.
    */
    int value;
    struct Node *next;

};

struct Stack{
    /*
    Description: Stack struct to hold a pointer to the top
                of the stack.
    */
    struct Node *top;
};

struct Stack* stack_create(){
    /*
        Description: Function will allocate dynamic memory for the stack structure
                     and return a pointer to it.
    */
    struct Stack *s = malloc(sizeof(struct Stack));
    s->top = NULL;

    return s;

}

void push(struct Stack *ptr, int value){
    /*
    Description: PUSH operation for a stack implemented 
                 with a singly linked list.
                 TIME: O(1).
    */
    struct Node *new = malloc(sizeof(struct Node));    
    new->value = value;

    if(ptr->top == NULL){
        new->next = NULL;
        ptr->top = new;
    }
    else{
        new->next = ptr->top;
        ptr->top = new;
    }
    
    return;

}
int pop(struct Stack *ptr){
    /*
    Description: POP operation for a stack implemented 
                 with a singly linked list.
                 TIME: O(1).
    */

    if(ptr->top == NULL){
        printf("\nNOTHING TO POP\n");
        return 0;
    }

    int res  = ptr->top->value;
    struct Node *current = ptr->top;
    ptr->top = ptr->top->next;
    
    free(current);

    return res;
}

int greetUser(){
    /*
        Description: This function will prompt the user to make 
                     a selection in the menu.
    */
    int choice = 0;
    do{
        printf("\nWhat would you like to do?\n");
        printf("\n(1) PUSH\n");
        printf("\n(2) POP\n");
        printf("\n(3) Quit\n");
        scanf("%d", &choice);
        if(choice == 3){
            printf("\nGoodbye\n");
            break;
        }
    }while(choice < 1 && choice > 3);
    

    return choice;
}

void program(int selection, struct Stack *s){
    /*
        DESCRIPTION: function defined to implement the functionality of 
                     the program-user interaction.
    */
    do{
        selection = greetUser();
        if(selection == 1){
            int val = 0;
            printf("\nEnter value to push to stack: \n");
            scanf("%d", &val);
            push(s, val);
            system("cls");
        }
        else{
            int value = pop(s);
            if(value > 0){
                printf("\nPOPPED: %d\n", value);
            }  
        }
    }while(selection < 3 && selection > 0);

}




int main(){
    struct Stack *s = stack_create();
    int selection = 0;
    program(selection,s);

}
