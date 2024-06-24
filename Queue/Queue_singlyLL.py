"""
AUTHOR: Bryce Calhoun
DESCRIPTION: Queue ADT implemented with a singly linked list of node objects
"""

class Node:
    """
    DESCRIPTION: Object definition for a single node in the Linked List
    """
    def __init__(self, value, nextNode):
        self._value = value
        self._nextNode = nextNode

    def get_value(self):
        return self._value

    def get_next(self):
        return self._nextNode

    def set_next(self, node):
        self._nextNode = node
        return


class LinkedList:
    """
    DESCRIPTION: Object definition for the linked list holding the nodes
    """

    def __init__(self):
        self._front = None
        self._rear = None
        self._size = 0


    def get_size(self):
        return self._size

    def get_front(self):
        return self._front

    def set_front(self, node):
        self._front = node
        return

    def set_rear(self, node):
        self._rear = node
        return

    def get_rear(self):
        return self._rear

    def is_empty(self):
        if self.get_size() == 0:
            return True
        return False

    def insert_rear(self, value):

        if self.is_empty():
            newNode = Node(value, None)
            self.set_front(newNode)
        else:
            newNode = Node(value, None)
            self.get_rear().set_next(newNode)

        self.set_rear(newNode)
        self._size += 1
        return

    def remove_front(self):
        if self.is_empty():
            return

        returnNode = self.get_front()

        self.set_front(returnNode.get_next())

        self._size -= 1

        if self.get_size() == 0:
            self.set_front(None)
            self.set_rear(None)

        return returnNode


class Queue_singlyLL:
    """
    DESCRIPTION: Object definition for the queue ADT, implemented with a singly linked list
    """

    def __init__(self):
        self._size = 0
        self._list = LinkedList()

    def get_size(self):
        return self._size

    def is_empty(self):
        if self.get_size() == 0:
            return True
        return False


    def enqueue(self, value):

        self._list.insert_rear(value)
        self._size += 1
        return

    def dequeue(self):

        if self.is_empty():
            return

        returnNode = self._list.remove_front()
        self._size -= 1

        return returnNode

    def peek(self):
        return self._list.get_front()


