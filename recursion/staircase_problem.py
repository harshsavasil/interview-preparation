# Problem Statement
# Given a staircase with N stairs (20) and a set X which denotes the allowed number of steps. {1, 3, 5}
# Find the total no. of ways to climb the stairs
# video link - https://www.youtube.com/watch?v=5o-kdjv7FD0&list=PLBZBJbE_rGRVnpitdvpdY9952IsKMDuev&index=2

def num_ways(N, X):
    """
    @param: N no. of stairs
    @param: X set of allowed steps
    """
    dp = [0] * (N + 1)
    dp[0] = 1
    for num_of_stairs in range(1, N + 1):
        total = 0
        for step in X:
            total += dp[num_of_stairs - step] if num_of_stairs >= step else 0
        dp[num_of_stairs] = total
    return dp[N]


print('No. of Ways to climb the staircase are : {}'.format(num_ways(3, [1, 2])))