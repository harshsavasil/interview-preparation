#include <bits/stdc++.h>
#define MAX_SIZE 1000000010

using namespace std;

// typedef vector<long> vi;

unordered_map<long, long> dp;

long returnCoins(long n) {
    // cout << "n: " << n << " dp[n]: " << dp[n] << endl; 
    if (dp.find(n) != dp.end()) return dp[n];
    if(n == 0) return 0;
    return dp[n] = max(n, returnCoins(n/2) + returnCoins(n/3) + returnCoins(n/4)); 
}

// void precompute() {
//     dp[0] = 0;
//     dp[1] = 1;
//     for(long i = 2; i <= MAX_SIZE; i++) {
//         dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
//     }
// }
int main() {
    long n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // precompute();
    while(scanf("%ld" , &n) != EOF) {
    	printf("%ld\n", returnCoins(n));
    	// printf("%ld\n", dp[n]);
    }
}