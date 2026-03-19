

class DLink {
    #previous;
    #next;
    #value;

    constructor(value, previous, next) {
        this.#value = value;
        this.#previous = previous,
        this.#next = next;
        return;
    }

    // accessors & mutators
    get_previous() {
        return this.#previous;
    }
    get_next() {
        return this.#next;
    }
    get_value() {
        return this.#value;
    }
    set_previous(link) {
        this.#previous = link;
    }
    set_next(link) {
        this.#next = link;
    }
}


class DoublyLinkedList {
    #size;
    #head_sentinel;
    #tail_sentinel;

    constructor() {
        this.#size = 0;
        this.#head_sentinel = new DLink(null, null, null);
        this.#tail_sentinel = new DLink(null, null, null);

        this.#head_sentinel.set_next(this.#tail_sentinel);
        this.#tail_sentinel.set_previous(this.#head_sentinel);
    }

    print_FrontBack() {
        /*
        Time: big theta(n)
         */
        if(this.#size > 0){
            let current = this.#head_sentinel.get_next();
            do{
                console.log(current.get_value());
                current = current.get_next();
            }
            while(current.get_next() != null);
            return;
        }
        console.log("error: empty list on print front to back call");
        return;
    }
    print_BackFront() {
        /*
        Time: big theta(n)
         */
        if(this.#size > 0){
            let current = this.#tail_sentinel.get_previous();
            do{
                console.log(current.get_value());
                current = current.get_previous();
            }
            while(current.get_previous() != null);
            return;
        }
        console.log("error: empty list on print front to back call");
        return;
    }
    add_front(value) {
        /*
        Time: O(1)
         */
        const newLink = new DLink(value, this.#head_sentinel, this.#head_sentinel.get_next());
        this.#head_sentinel.get_next().set_previous(newLink);
        this.#head_sentinel.set_next(newLink);
        this.#size++;
    }
    add_back(value) {
        /*
        Time: O(1)
         */
        const newLink = new DLink(value, this.#tail_sentinel.get_previous(), this.#tail_sentinel);
        this.#tail_sentinel.get_previous().set_next(newLink);
        this.#tail_sentinel.set_previous(newLink);
        this.#size++;
    }
    remove_front() {
        /*
        Time: O(1)
         */
        if(this.#size > 0){
            const linkToRemove = this.#head_sentinel.get_next();
            linkToRemove.get_next().set_previous(this.#head_sentinel);
            this.#head_sentinel.set_next(linkToRemove.get_next());
            this.#size--;
            return;
        }
        console.log("error: empty list");
        return;
    }
    remove_back() {
        /*
        Time: O(1)
         */
        if(this.#size > 0){
            const linkToRemove = this.#tail_sentinel.get_previous();
            linkToRemove.get_previous().set_next(this.#tail_sentinel);
            this.#tail_sentinel.set_previous(linkToRemove.get_previous());
            this.#size--;
            return;
        }
        console.log("error: empty list");
        return;
    }
    get_front() {
        /*
        Time: O(1)
         */
        return this.#head_sentinel.get_next();
    }
    get_back() {
        /*
        Time: O(1)
         */
        return this.#tail_sentinel.get_previous().get_value();
    }
    
    // accessors & mutators
    get_head() {
        return this.#head_sentinel;
    }
    get_tail() {
        return this.#tail_sentinel;
    }
    get_size() {
        return this.#size;
    }
}



module.exports = {
    DoublyLinkedList
};