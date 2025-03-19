"""
#  Author: Bryce Calhoun
#  Description: Implementation of the merge sort algorithm on a dynamic array object
"""

from dynamicArray import *

def mergesort(array: Dynamic_Array) -> Dynamic_Array:
    """
    Description: Function will recursively split a given dynamic array in half
    """
    if array.get_size() == 1:
        return array

    size = array.get_size() // 2
    arr1 = Dynamic_Array(size)
    arr2 = Dynamic_Array(size - arr1.get_size())


    for i in range(array.get_size()):
        if i >= arr1.get_capacity():
            arr2.append(array.get_at_index(i))
        else:
            arr1.append(array.get_at_index(i))

    arr1 = mergesort(arr1)
    arr2 = mergesort(arr2)

    return merge(arr1, arr2)

def merge(arr1: Dynamic_Array, arr2: Dynamic_Array) -> Dynamic_Array():
    """
    Description: Function will merge two sorted arrays together and return the result
    """
    newArr = Dynamic_Array()
    while arr1.get_size() > 0 and arr2.get_size() > 0:
        if arr1.get_at_index(0) > arr2.get_at_index(0):
            newArr.append(arr2.get_at_index(0))
            arr2.remove_from_index(0)
        else:
            newArr.append(arr1.get_at_index(0))
            arr1.remove_from_index(0)
    while arr1.get_size() > 0:
        newArr.append(arr1.get_at_index(0))
        arr1.remove_from_index(0)

    while arr2.get_size() > 0:
        newArr.append(arr2.get_at_index(0))
        arr2.remove_from_index(0)

    return newArr

