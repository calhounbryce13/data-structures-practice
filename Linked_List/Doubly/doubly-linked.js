



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
    }

}