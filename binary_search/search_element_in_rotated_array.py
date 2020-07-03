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
    return n - 1 # already sorted

def binary_search(array, number, low, high):
    """
    Performs binary_search on array and returns the index of the number in array if found otherwise -1.
    """
    while low <= high:
        mid = low + (high - low) // 2
        if number == array[mid]:
            return mid
        elif number < array[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return -1

def search(nums, target):
    n = len(nums)
    if n == 0:
        return -1
    smallest_element_index = (find_pivot(nums) + 1 ) % n
    if target >= nums[smallest_element_index] and target <= nums[-1]:
        return binary_search(nums, target, smallest_element_index, n - 1)
    return binary_search(nums, target, 0, smallest_element_index - 1)

def search_without_finding_pivot(nums, target):
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if nums[mid] == target:
            return True
        elif nums[mid] > target:
            if nums[low] <= target <= nums[mid]:
                high -= 1
            else:
                low += 1
        else:
            if nums[mid] <= target <= nums[high]:
                low  += 1
            else:
                high -= 1
                
    return False
elements = [3, 1, 2, 3]
print(search(elements, 3))