
"""
Author: Bryce Calhoun
Description: Implementation of a stack ADT. operations: push, pop, peek, isempty.
"""
# I know that the accessors and mutators are not necessary for python, but I like to
# use them consistently in OOP languages.


class Node:
    """
    DESCRIPTION: Node object to contain the value to be stored
                 as well as a next attribute for another node.
    """
    def __init__(self, value, next_node):
        self.value = value
        self.next_node = next_node

    # MUTATOR
    def set_value(self, value):
        self.value = value
        return

    # ACCESSOR
    def get_value(self):
        return self.value


class Stack:
    """
    DESCRIPTION: Stack object to contain a node to represent to top of the stack
                as well as a value to track stack size.
    """
    def __init__(self, top, size):
        self.top = None
        self.size = 0

    # ACCESSOR
    def get_size(self):
        return self.size

    def push(self, value):
        """
        DESCRIPTION: Function to push a node onto a stack instance
                     given the value to be pushed.
        """
        if self.top is None:
            n = Node(value, None)

        else:
            n = Node(value, self.top)

        self.size += 1
        self.top = n
        return

    def pop(self):
        """
        DESCRIPTION: Function to pop a value from an instance of a stack
                     and return the value
        """
        if self.top is None:
            print("\nnothing to pop\n")
            return
        else:
            value = self.top.get_value()
            self.top = self.top.next_node
            return value

    def peek(self):
        """
        DESCRIPTION: Function to peek at a value from an instance of a stack
                     and return the value without removing the node.
        """
        if self.top is None:
            print("\nnothing to see\n")
            return
        else:
            var = self.top.get_value()
            return var

    def isempty(self):
        """
        DESCRIPTION: Function to determine whether an instance of a stack is empty
                     or not, will return false if not empty and true if empty.
        """
        if self.top is None:
            return True
        else:
            return False



