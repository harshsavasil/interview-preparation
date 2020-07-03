def first_occurence(array, number):
    """
    Performs binary_search on array and returns the first occurence of the number in array if found otherwise -1.
    """
    low = 0
    high = len(array) - 1
    first_occurence = -1
    while low <= high:
        mid = low + (high - low) // 2
        if number == array[mid]:
            first_occurence = mid
            high = mid - 1
        elif number < array[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return first_occurence

def last_occurence(array, number):
    """
    Performs binary_search on array and returns the last occurence of the number in array if found otherwise -1.
    """
    low = 0
    high = len(array) - 1
    last_occurence = -1
    while low <= high:
        mid = low + (high - low) // 2
        if number == array[mid]:
            last_occurence = mid
            low = mid + 1
        elif number < array[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return last_occurence

def frequency(array, number):
    left_index = first_occurence(array, number)
    right_index = last_occurence(array, number)
    if left_index == -1: # number nor found
        return 0
    return right_index - left_index + 1

if __name__ == "__main__":
    elements = [1, 1, 2, 2, 2, 5, 7, 8, 10]
    print("First occurence of 1 is {0}".format(first_occurence(elements, 1)))
    print("First occurence of -1 is {0}".format(first_occurence(elements, -1)))
    print("Last Occurence of 2 is {0}".format(last_occurence(elements, 2)))
    print("Frequency of number 2 is {0}.".format(frequency(elements, 2)))