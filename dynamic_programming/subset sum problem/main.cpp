/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*
* Author : Harsh Gupta
* Handle: harshsavasil
*
*/

/*
Problem Description: Subset Sum Problem
Given a set of non-negative integers, and a value sum,
determine if there is a subset of the given set with sum equal to given sum.

Tags: Dynamic Programming

Sample Input -
num of elements : 6 , sum = 9
{3, 34, 4, 12, 5, 2}

Sample Output -
True  //There is a subset (4, 5) with sum 9.

TC -
SC -
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
void display(const vector<vector<bool>> data)
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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, sum;
        cin >> n >> sum;
        vi nums(n);
        REP(i, n)
        {
            cin >> nums[i];
        }
        vector<vector<bool>> subset_sum(n, vector<bool>(sum + 1));
        REP(i, n)
        {
            subset_sum[i][0] = true;
        }
        FOR(i, 1, sum)
        {
            if (i == nums[0])
                subset_sum[0][i] = true;
            else
                subset_sum[0][i] = false;
        }
        // display(subset_sum);
        FOR(i, 1, n - 1)
        {
            FOR(j, 1, sum)
            {
                if (j < nums[i])
                {
                    subset_sum[i][j] = subset_sum[i - 1][j];
                }
                else
                {
                    subset_sum[i][j] = subset_sum[i - 1][j] || subset_sum[i - 1][j - nums[i]];
                }
            }
        }
        // display(subset_sum);
        if (subset_sum[n - 1][sum])
            cout << "Sum can be formed.";
        else
            cout << "No Possible Subset.";
    }
    return 0;
}