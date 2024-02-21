"""
Author: Bryce Calhoun
Description: Doubly Linked List implementation with operations: insert(at the end), remove, search, display forward,
             display backward.

"""


class Node:
    """
    Description: A class defintion for a single node in the list.
                 Comes with previous and next fields for nodes and
                 a value field for the value of the given node.

    """
    def __init__(self, value=None, previous=None, nxt=None):
        self.value = value
        self.previous = previous
        self.nxt = nxt

    # ACCESSOR
    def get_value(self):
        return self.value

    # MUTATOR
    def set_value(self, value):
        self.value = value


class doublyLL:
    """
    Description: Class defintion for the doubly linked list.
                 A head member to track the front of the list,
                 as well as a size member to track to number 
                 of elements.

    """
    def __init__(self, head=None, size=0):
        self.head = head
        self.size = size

    # ACCESSOR
    def get_size(self):
        return self.size

    def insert(self, value):
        """
        Description: Function to insert a node into the doubly-linked
                     list given the value to insert.
                     TIME: O(n).

        """
        node = Node()
        node.set_value(value)
        if self.head is None:
            node.previous = None
            node.nxt = None
            self.head = node
        else:
            current = self.head
            while current.nxt is not None:
                current = current.nxt
            current.nxt = node
            node.previous = current
        self.size += 1
        return

    def search(self, value):
        """
        Description: Function to search for a node in the list given
                     the value to search for. The function will return the node.
                     TIME: O(n).

        """
        if self.head is None:
            print("empty list")
            return None
        else:
            current = self.head
            while current is not None:
                if current.get_value() == value:
                    return current
                current = current.nxt
            print("\nvalue not found\n")
            return None

    def remove(self, value):
        """
        Description: Function to remove a node from the list, given the value of
                     the node. Uses the search() function as a helper.
                     TIME: O(n).

        """
        node = self.search(value)
        if node is None:
            print("\nremoval error\n")
        else:
            if node.nxt is None:
                node.previous.nxt = None
                node.previous = None
            elif node.nxt is not None and node.previous is not None:
                node.previous.nxt = node.nxt
                node.nxt.previous = node.previous
                node.previous = None
                node.nxt = None
            else:
                self.head = node.nxt
                node.nxt.previous = None
                node.nxt = None
            print("value removed: ", value)

        return

    def display_forward(self):
        """
        Description: Function to display the contents of an instance of the
                     doubly-linked list in a head-first order.
                     TIME: O(n).

        """
        if self.head is None:
            print("\nnothing to see\n")
            return
        else:
            current = self.head
            while current is not None:
                print("\n", current.get_value(), "\n")
                current = current.nxt
            return

    def display_backward(self):
        """
        Description: Function to display the contents of an instance of the
                     doubly-linked list in an end-first order.
                     TIME: O(2n)/O(n).

        """
        if self.head is None:
            print("\nnothing to see\n")
            return
        else:
            current = self.head
            while current.nxt is not None:
                current = current.nxt
            while current is not None:
                print("\n", current.get_value(), "\n")
                current = current.previous
            return

