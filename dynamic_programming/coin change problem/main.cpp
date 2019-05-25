/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*
* Author : Harsh Gupta
* Handle: harshsavasil
*
*/

/*
Problem Description: Coin Change Problem
Given a value N, if we want to make change for N cents, and we have infinite
supply of each of S = { S1, S2, .. , Sm} valued coins, fint the possible change with minimum number of coins?
The order of coins doesn’t matter.

Tags: Dynamic Programming

Sample Input -
3 4
1 2 3
3 is the number of types of coins.
4 is the change required.

Sample Output -
2
*/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
inline bool EQ(double a, double b)
{
    return fabs(a - b) < 1e-9;
}
const int INF = 1 << 29;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int &n, int b) { n |= two(b); }
inline void unset_bit(int &n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n)
{
    int res = 0;
    while (n && ++res)
        n -= n & (-n);
    return res;
}
template <class T>
void chmax(T &a, const T &b) { a = max(a, b); }
template <class T>
void chmin(T &a, const T &b) { a = min(a, b); }

/////////////////////////////////////////////////////////////////////
void display(const vvi data)
{
    int row = data.size();
    int column = data[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// TC - O(n^2)
// SC - O(n^2)
int getMinCoinChange(vi coins, int change)
{
    int n = coins.size();
    vvi coinChanges(n, vi(change + 1, 0));
    for (int i = 0; i < n; i++)
    {
        coinChanges[i][0] = 0;
    }
    for (int i = 1; i <= change; i++)
    {
        if (i % coins[0] == 0)
        {
            coinChanges[0][i] = i / coins[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= change; j++)
        {
            if (j < coins[i])
            {
                coinChanges[i][j] = coinChanges[i - 1][j];
            }
            else
            {
                coinChanges[i][j] = min(1 + coinChanges[i][j - coins[i]], coinChanges[i - 1][j]);
            }
        }
    }
    return coinChanges[n - 1][change];
}

// TC - O(n^2) SC - O(n)
int coinChangeSpaceOptimized(vi coins, int change)
{
    int n = coins.size();
    vi coinChanges(change + 1, INT_MAX);
    coinChanges[0] = 0;
    for (int i = 1; i <= change; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                coinChanges[i] = min(1 + coinChanges[i - coins[j]], coinChanges[i]);
            }
        }
    }
    // for (int i = 0; i <= change; i++)
    //     cout << coinChanges[i] << " ";
    // cout << endl;
    return coinChanges[change];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, change;
        cin >> n >> change;
        vi coins(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        cout << "Solution using O(n^2) Solution : " << getMinCoinChange(coins, change) << endl;
        cout << "Solution using O(n) Solution : " << coinChangeSpaceOptimized(coins, change) << endl;
    }
    return 0;
}