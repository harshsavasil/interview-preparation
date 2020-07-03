def find_pivot(array):
    """
    Performs binary_search on array and returns the index of the pivot in rotated array if found otherwise -1.
    Note: pivot is the largest element in rotated array for this problem
    """
    n = len(array)
    low = 0
    high = n - 1
    while low <= high:
        mid = low + (high - low) // 2
        if mid < n - 1 and array[mid] > array[mid + 1]:
            return mid
        if mid > 0 and array[mid] < array[mid - 1]:
            return mid - 1
        elif array[mid] >= array[low]: # look on the right unsorted side
            low = mid + 1
        else:
            high = mid - 1
    return -1 # already sorted

if __name__ == "__main__":
    elements = [1, 1, 1, 2, 5, 7, 8, 10, 0, 1]
    num_of_rotations = find_pivot(elements) + 1
    print("Num of rotations: {0}".format(num_of_rotations))