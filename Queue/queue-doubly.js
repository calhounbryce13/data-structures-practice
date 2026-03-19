


// assuming same directory
const Dlist = require('./doubly-linked.js');

class Queue {
    #data;

    constructor() {
        this.#data = new Dlist.DoublyLinkedList();
    }

    enqueue(value) {
        /*
        Time: O(1)
         */
        this.#data.add_back(value);
    }
    dequeue() {
        /*
        Time: O(1)
         */
        const data = this.#data.get_front();
        this.#data.remove_front();
        return data;
    }

    get_size() {
        /*
        Time: O(1)
         */
        return this.#data.get_size();
    }
}
