
"""
Author: Bryce Calhoun
Description: Stack ADT implemented with a singly-linked list. operations: push, pop, peek, isempty.
"""
import random

from singlyLL import *


class StackException(Exception):

    pass


class Stack:
    """
    DESCRIPTION: Stack object to contain a node to represent to top of the stack
                as well as a value to track stack size.
    """
    def __init__(self):
        self._stack = singlyLL()
        self._size = 0

    def get_size(self):
        return self._size

    def is_empty(self):
        if self._stack.is_empty():
            return True
        return False

    def push(self, value):
        """
        DESCRIPTION: Function to push a node onto a stack instance
                     given the value to be pushed.
        """
        self._stack.insert_front(value)
        self._size += 1
        return

    def pop(self):
        """
        DESCRIPTION: Function to pop a value from an instance of a stack
                     and return the value
        """
        if self.is_empty():
            raise StackException("EMPTY STACK")

        value = self._stack.remove_front()
        self._size -= 1

        return value


    def top(self):
        """
        DESCRIPTION: Function to peek at a value from an instance of a stack
                     and return the value without removing the node.
        """
        value = self._size.get_front()
        return value


if __name__ == '__main__':


    stack = Stack()
    num = random.randint(5, 200)
    for x in range(num):
        print("x:", x)
        stack.push(x)


    for x in range(num):
        print("popped: ", stack.pop())


