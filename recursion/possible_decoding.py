# Problem Statement
# Given Mapping for all characters such that {a: 1, b: 2, .... z: 26}
# Given a numeric string find all possible messages that could be formed from characters.
# e.g. 12 - {ab, l}
# e.g. 123 - {abc, lc, aw}
# video link - https://www.youtube.com/watch?v=qli-JCrSwuk&list=PLBZBJbE_rGRVnpitdvpdY9952IsKMDuev

def helper(data, k):
    if k == 0: # empty string
        return 1
    start = len(data) - k
    if data[start] == '0':
        return 0
    result = helper(data, k - 1)
    if k>=2 and int(data[start : start + 2]) <= 26:
        result += helper(data, k - 2)
    return result

def helper_dp(data, k, dp):
    if k == 0: # empty string
        return 1
    start = len(data) - k
    if data[start] == '0':
        return 0
    if dp[k] is not None:
        return dp[k]
    result = helper_dp(data, k - 1, dp)
    if k>=2 and int(data[start : start + 2]) <= 26:
        result += helper_dp(data, k - 2, dp)
    dp[k] = result
    return result

def num_ways(input_string):
    """
        Recursive Approach TC - O(2^n) T(n) = T(n - 1) + T(n - 2)
    """
    return helper(input_string, len(input_string))

def num_ways_dp(input_string):
    """
        Dynamic Programming Approach TC - O(n)
    """
    dp = [None] * (len(input_string) + 1)
    return helper_dp(input_string, len(input_string), dp)

if __name__ == "__main__":
    test_case = '123454456'
    print(num_ways(test_case))
    print(num_ways_dp(test_case))
