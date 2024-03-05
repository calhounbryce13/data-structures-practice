"""
#   Author: Bryce Calhoun
#   Description: Implementation of a dynamic array object, utilizing a static array backbone.
"""

from staticArray import *
import random

class Dynamic_Array_Exception(Exception):


    pass

class Dynamic_Array:

    def __init__(self, capacity=10):

        """
        Initializing a size of 0, a starting capacity of 10 and a
        static array with the capacity as its capacity.
        """
        self._size = 0
        self._capacity = capacity
        self._data = Static_Array(self._capacity)

    def get_size(self):
        """
        Accessor for the private size field
        """
        return self._size

    def get_capacity(self):
        """
        Accessor for the private capacity field
        """
        return self._capacity
    
#---------------------------------------------------------------#    

    def is_empty(self):
        """
        Function to return True if the dynamic array is empty or false if not
        """
        if self._size == 0:
            return True
        return False

    def get_at_index(self, index):
        """
        Function to return a value from the array given a valid index number
        """
        if index >= self._capacity or index < 0:
            raise Dynamic_Array_Exception("\nINDEX OUT OF RANGE\n")
        return self._data.get_at_index(index)

    def append(self, value):
        """
        Function to place a value at the end of the dynamic array.
        The function will resize the underlying static array if necessary
        """

        # checking if size and capacity are equal for resizing
        if self._size == self._capacity:

            newCap = self._capacity * 2
            newArr = Static_Array(newCap)

            # looping through the new static array and copying elements from the current array
            for x in range(self._capacity):
                newArr.set_at_index(x, self._data.get_at_index(x) )

            self._data = newArr
            self._capacity = newCap

        # inserting the value at the last index
        #self._data.data[self._size] = value
        self._data.set_at_index(self._size, value)
        self._size += 1

        return

    def get_from_end(self) -> object:
        if self.is_empty():
            raise Dynamic_Array_Exception

        #value = self._data.data[self._size - 1]
        value = self._data.get_at_index(self._size - 1)
        return value

    def remove_from_index(self, index):
        """
        Function to remove a value from the dynamic array at a given index.
        Function will decrease the capacity of the array if the size is less than
        half of the capacity.
        """

        # checking if index is valid
        if index < 0 or index >= self._size:
            raise Dynamic_Array_Exception("\nINDEX OUT OF RANGE\n")

        # iterating over the dynamic array and pushing each element after the removed index forward
        for x in range(index, (self._size - 1)):
            #self._data.data[x] = self._data.data[x + 1]
            self._data.set_at_index(x, self._data.get_at_index(x+1))

        # decrementing size and setting the last index to None
        self._size -= 1
        #self._data.data[self._size] = None
        self._data.set_at_index(self._size, None)

        # checking if the number of elements in array is < half the capacity after removal
        if self._size < self._capacity / 2 and self._capacity >= 20:

            newCap = self._capacity / 2
            newArr = Static_Array(int(newCap))

            for x in range(self._size):
                #newArr.data[x] = self._data.data[x]
                newArr.set_at_index(x, self._data.get_at_index(x))

            self._capacity = newCap

        return



    def get_min(self):
        """
        Function to return the lowest value in the dynamic array
        """

        # checking if the list is empty
        if self.is_empty():
            raise Dynamic_Array_Exception("\nTHE LIST IS EMPTY\n")

        # initializing minVal to first value in the array
        #minVal = self._data.data[0]
        minVal = self._data.get_at_index(0)

        # iterating through the array
        for x in range(self._size):
            if self._data.get_at_index(x) is not None:
                if self._data.get_at_index(x) < minVal:
                    minVal = self._data.get_at_index(x)

        return minVal

    def get_max(self):
        """
        Function to return the greatest value in the dynamic array
        """

        # checking if the list is empty
        if self.is_empty():
            raise Dynamic_Array_Exception("\nTHE LIST IS EMPTY\n")

        # initializing maxVal to first value in the array
        maxVal = self._data.get_at_index(0)

        # iterating through the array
        for x in range(self._size):
            if self._data.get_at_index(x) is not None:
                if self._data.get_at_index(x) > maxVal:
                    maxVal = self._data.get_at_index(x)

        return maxVal
    
    def print_array(self):
        print("\n---------------------------------------\n")

        for x in range(self._size):
            print(self._data.get_at_index(x), " ")

        print("\n---------------------------------------\n")
        return 


