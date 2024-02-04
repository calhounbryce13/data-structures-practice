"""
DESCRIPTION: Implementation of the bubble sort algorithm.
             TIME O(n^2).

"""


def bubble_sort(array, size):
    """
    :param array: the list to be sorted in ASCENDING order
    :param size: the number of elements in the list
    """

    # looping through the array from last to first
    for x in range(size, 0, -1):

        # making a second pass from first until y = (x-1)
        for y in range(1, x):

            # checking of the current y index is less than its previous adjacent index
            if array[y - 1] > array[y]:

                # making a swap if so
                temp = array[y - 1]
                array[y - 1] = array[y]
                array[y] = temp



