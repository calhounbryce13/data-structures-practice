/*
** Author: Bryce Calhoun
** Description: Deque implementation utilizing a doubly linked list data structure
*/

public class Deque{
/*
Description: Class definition for a deque object which uses a doubly linked list
*/
    private int size;
    private DoublyLL deque;

    Deque(){
    /*
    Description: Default constructor for the deque
    */
        this.size = 0;
        this.deque = new DoublyLL();
    }
    public int is_empty(){
        if(this.size == 0){
            return 1;
        }
        return 0;
    }
    // accessor for the size member variable
    public int get_size(){
        return this.size;
    }
    public void enqueue_front(int value){
    /*
    Description: Function to enqueue an integer value at the front of the deque
    Input(s): integer value
    Output(s): None
    */
        this.deque.insert_front(value);
        this.size++;

    }
    public void enqueue_back(int value){
    /*
    Description: Function to enqueue an integer value at the back of the deque
    Input(s): Integer value
    Output(s): None
    */
        this.deque.insert_back(value);
        this.size++;
    }
    public int dequeue_front(){
    /*
    Description: Function to dequeue a value from the front of the deque
    Input(s): None
    Output(s): Integer value
    */
        int value = this.deque.remove_front();
        this.size--;

        return value;
    }
    public int dequeue_back(){
    /*
    Description: Function to dequeue a value from the back of the deque
    Input(s): None
    Output(s): integer value
    */
        int value = this.deque.remove_back();
        this.size--;

        return value;
    }
}