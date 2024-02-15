class Static_Array_Exception(Exception):


    pass


class Static_Array:
    def __init__(self, capacity=10):
        """
        Initializing the size of the array and creating a list with the
        specified size
        """
        self.capacity = capacity
        self.data = [None] * capacity

        if capacity < 0:
            raise Static_Array_Exception("\nCapacity Must Be Positive !\n")

