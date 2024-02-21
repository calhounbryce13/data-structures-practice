"""
#   Author: Bryce Calhoun
#   Description: A singly-linked list implemented with node structures.
"""

import random

class NodeException(Exception):

    pass

class Node:
    """
    DESCRIPTION: Node structure to represent each data point in the
                 linked list. Initialized with no value or next pointer.
    """
    def __init__(self, value=None, next=None):
        self._value = value
        self._next = next

    def get_value(self):
        if self._value is None:
            raise NodeException("NO VALUE IN NODE")
        return self._value

    def set_next(self, node):
        self._next = node

    def get_next(self):
        if self._next is None:
            raise NodeException("NO NEXT NODE")
        return self._next


class singlyLLException(Exception):

    pass


class singlyLL():
    """
    DESCRIPTION: Singly linked list initialized with head and tail sentinel nodes and
                 the size set to 0
    """
    def __init__(self):
        self._headSentinel = Node()
        self._tailSentinel = Node()
        self._size = 0

    def is_empty(self):
        """
        DESCRIPTION: function to return true if the list is empty, and false otherwise
        """
        if self._headSentinel.get_next() is None:
            return True
        return False

    def insert_front(self, value):
        """
        DESCRIPTION: Function to insert a value in the front of the list just
                     after the head sentinel
        """
        if self.is_empty():
            newNode = Node(value, None)
            self._headSentinel.set_next(newNode)
            self._tailSentinel.set_next(newNode)
            self._size += 1
            return

        newNode = Node(value, self._headSentinel.get_next())
        self._headSentinel.set_next(newNode)
        self._size += 1
        return

    def remove_front(self) -> object:
        """
        DESCRIPTION: Function to remove a value from the front of the list just
                     after the head sentinel
        """
        if self.is_empty():
            raise singlyLLException("EMPTY LIST")
        value = self._headSentinel.get_next().get_value()
        current = Node(None, self._headSentinel.get_next())
        current = current.get_next()
        self._headSentinel.set_next(current.get_next())
        self._size -= 1

        return value







