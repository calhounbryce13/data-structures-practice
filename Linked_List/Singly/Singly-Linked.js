
'use strict';

class Link {
    #value;
    #next;
    constructor(value, next) {
        this.#value = value;
        this.#next = next;
    }

    get_next() {
        return this.#next;
    }
    get_value() {
        return this.#value;
    }
};

class LinkedList {
    #size;
    #head;
    constructor() {
        this.#size = 0;
        this.#head = null;
    }
    add_front(value) {
        const newLink = new Link(value, this.#head);
        this.#head = newLink;
        this.#size++;
    }
    get_front() {
        if(this.#size > 0 && this.#head){
            return this.#head.get_value();
        }
        console.log("error: list is empty on get_front call");
        return;
    }
    remove_front() {
        if(this.#size > 0 && this.#head){
            this.#head = this.#head.get_next();
            this.#size--;
            return;
        }
        console.log("error: list is empty on remove_front call");
        return;
    }
    get_head() {
        return this.#head;
    }
    get_size() {
        return this.#size;
    }
};


const main = function(){}


main();