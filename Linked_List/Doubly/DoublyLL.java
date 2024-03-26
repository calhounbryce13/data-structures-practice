/*
** Author: Bryce Calhoun
** description: Implementation of a doubly linked list of node structures.
*/

public class DoublyLL{
/*
Description: Class definition for the doubly linked list which uses both head a tail sentinels
*/

    private int size;
    private Node head_sentinel;
    private Node tail_sentinel;
    
    public DoublyLL(){
    /*
    Description:  default constructor for the doubly linked list object
    */
        this.head_sentinel = new Node(null, null, 0);
        this.tail_sentinel = new Node(null, null, 0);
        this.size = 0;
    }
    public class doublyLLException extends Exception{
        public doublyLLException(String error){
            super(error);
        }
    }
    // Accessor for the size member variable
    public int get_size(){
        return this.size;
    }
    public int is_empty(){
        if(this.size == 0){
            return 1;
        }
        return 0;
    }
    public void insert_front(int value){
    /*
    Description: Function to insert a node into the front of the doubly linked list
    Input(s): Integer value
    Output(s): None
    */
        if(this.is_empty() == 1){
            Node newNode = new Node(this.head_sentinel, this.tail_sentinel, value);
            this.head_sentinel.next = newNode;
            this.tail_sentinel.previous = newNode;
        }
        else{
            Node newNode = new Node(this.head_sentinel, this.head_sentinel.next, value);
            this.head_sentinel.next = newNode;
            newNode.next.previous = newNode;
        }
        this.size++;
    }
    public int remove_front(){
    /*
    Description: Function to remove a node from the front of the doubly linked list and return its value
    Input(s): None
    Output(s): Integer value
    */
        if(this.is_empty() == 1){
            System.out.println("\nEMPTY LIST\n");
            return 0;
        }
        else{
            int value = this.head_sentinel.next.get_value();
            this.head_sentinel.next = this.head_sentinel.next.next;
            this.head_sentinel.next.previous = this.head_sentinel;

            this.size--;
            return value;
        }
        
    }
    public void insert_back(int value){
    /*
    Description: Function to insert a node into the back of the doubly linked list.
    Input(s): Integer value
    Output(s): None
    */
        if(this.is_empty() == 1){
            Node newNode = new Node(this.head_sentinel, this.tail_sentinel, value);
            this.head_sentinel.next = newNode;
            this.tail_sentinel.previous = newNode;
        }
        else{
            Node newNode = new Node(this.tail_sentinel.previous, this.tail_sentinel, value);
            this.tail_sentinel.previous.next = newNode;
            this.tail_sentinel.previous = newNode;
        }
        this.size++;
    }
    public int remove_back(){
    /*
    Description: Function to remove a node from the back of the doubly linked list and return its value
    Input(s): None
    Output(s): Integer value
    */
        if(this.is_empty() == 1){
            System.out.println("\nEMPTY LIST\n");
            return 0;
        }
        else{
            int value = this.tail_sentinel.previous.value;
            this.tail_sentinel.previous = this.tail_sentinel.previous.previous;
            this.tail_sentinel.previous.next = this.tail_sentinel;

            this.size--;
            return value;
        }
    }
    public int get_front(){
    /*
    Description: Function to get and return the value from the front node in the doubly linked list
    Input(s): None
    Output(s): Integer value
    */
        return this.head_sentinel.next.get_value();
    }
    public int get_back(){
    /*
    Description: Function to get and return the value from the back node in the doubly linked list
    Input(s): None
    Output(s): Integer value
    */
        return this.tail_sentinel.previous.get_value();
    }
    public class Node{
    /*
    Description: Class definition for a single node structure within the linked list.
    */
        private int value;
        public Node previous;
        public Node next;

        public Node(Node previous, Node next, int value){
        /*
        Description: Default constructor for the node structure within the linked list
        */
            this.previous = previous;
            this.next = next;
            this.value = value;
        }
        public int get_value(){
            return this.value;
        }
    }

}

