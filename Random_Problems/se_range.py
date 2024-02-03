
def se_range(start: int, end: int):
    """
    DESCRIPTION: Function to take an input an integer start value and
                 an integer end value. Function will then create and return
                 a list with all the values in between inclusively.

    """

    # getting the correct size for the return list
    new_array_size = ((2 + (abs(start - end))) - 1)

    # initializing a python list containing all zeros with the correct size
    newArr = [0] * new_array_size

    # setting the initial value to be the start integer
    initial_val = start

    # looping through the new array and assigning values based on the init value
    for x in range(new_array_size):

        # if end is less than start then we count down instead of up
        if end < start:
            newArr[x] = (initial_val - x)
        else:
            newArr[x] = (initial_val + x)

    return newArr

