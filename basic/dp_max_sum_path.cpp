#include <iostream>
#define MAX 1000
#define MIN -1000
using namespace std;
int dp[MAX][MAX];
int arr[MAX][MAX];
int n, m;

int max_cost(int x, int y) {
    if ((x>=n) || (y>=m)) {
        return 0;
    }
    if ((x == n-1) && (y == m-1)) {
        return arr[x][y];
    }   
    return arr[x][y] + max(max_cost(x, y+1), max_cost(x+1, y));
}

int max_cost_dp(int x, int y) {
    if ((x>=n) || (y>=m)) {
        return 0;
    }
    if ((x == n-1) && (y == m-1)) {
        dp[x][y] = arr[x][y];
        return arr[x][y];
    }
    if (dp[x][y] != MIN) {
        return dp[x][y];
    }    
    dp[x][y] = arr[x][y] + max(max_cost(x, y+1), max_cost(x+1, y));
    return dp[x][y];
}

int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
            dp[i][j] = MIN;
        }
    }
    cout<<max_cost_dp(0, 0)<<endl;
    return 0;
}