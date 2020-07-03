# Problem - Search Element in nearly sorted array
# A nearly sorted array is an array in which every element at index i can be at ith, (i-1)th or (i+1)th position.
# Search the target in such an array.

def binary_search(nums, target):
    """
    Performs binary_search on array and returns the index of the number in array if found otherwise -1.
    """
    n = len(nums)
    low = 0
    high = n - 1
    while low <= high:
        mid = low + (high - low) // 2
        if target == nums[mid]:
            return mid
        elif mid < n - 1 and target == nums[mid + 1]:
            return mid + 1
        elif mid > 0 and target == nums[mid - 1]:
            return mid - 1
        elif target > nums[mid]:
            low = mid + 2
        else:
            high = mid - 2
    return -1

def search(nums, target):
    n = len(nums)
    if n == 0:
        return -1
    return binary_search(nums, target)

elements = [5, 10, 30, 20, 40]
print(search(elements, 5))