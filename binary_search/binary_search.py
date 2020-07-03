def binary_search(array, number):
    """
    Performs binary_search on array and returns the index of the number in array if found otherwise -1.
    """
    low = 0
    high = len(array) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if number == array[mid]:
            return mid
        elif number < array[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return -1

if __name__ == "__main__":
    elements = [1, 2, 5, 7, 8, 10]
    print(binary_search(elements, 1))
    print(binary_search(elements, -1))
    print(binary_search(elements, 10))