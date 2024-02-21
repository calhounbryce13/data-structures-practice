"""
#   Author: Bryce Calhoun
#   Description: A basic Static Array class definition to use for a dynamic array implementation.
"""

class Static_Array_Exception(Exception):


    pass


class Static_Array:
    def __init__(self, capacity=10):
        """
        Initializing the size of the array and creating a list with the
        specified size
        """
        self.capacity = capacity
        self._data = [None] * capacity

        if capacity < 0:
            raise Static_Array_Exception("\nCapacity Must Be Positive !\n")


    def get_at_index(self, index) -> object:
        if index < 0 or index >= self.capacity:
            raise Static_Array_Exception("INVALID INDEX")

        value = self._data[index]
        return value

    def set_at_index(self, index, value):
        if index < 0 or index > self.capacity:
            raise Static_Array_Exception("INVALID INDEX")
        self._data[index] = value
        return





