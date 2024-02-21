"""
#   Author: Bryce Calhoun
#   Description: Stack ADT implemented with a dynamic array. operations: push(), pop(), top()
"""

from dynamicArray import *
import random

class Stack:
    def __init__(self):
        """
        DESCRIPTION: Stack object initialized with a dynamic array and size set to 0
        """
        self._stack = Dynamic_Array()
        self._size = 0


    def push(self, value):
        """
        DESCRIPTION: Function to push a value into the stack
        """
        self._stack.append(value)
        self._size += 1

        return

    def pop(self) -> object:
        """
        DESCRIPTION: function to pop a value off the stack and return it
        """
        value = self._stack.get_from_end()
        self._stack.remove_from_index(self._size - 1)
        self._size -= 1
        return value

    def top(self) -> object:
        """
        DESCRIPTION: function to get a value from the top of the stack and return it
        """
        value = self._stack.get_from_end()
        return value



