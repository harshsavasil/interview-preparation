/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*
* Author : Harsh Gupta
* Handle: harshsavasil
*
*/

/*
Problem Description: Longest Common Subsequence
Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
So a string of length n has 2^n-1 different possible subsequences.

Tags: Dynamic Programming, Recursion

Sample Input - 
1
AGGTAB GXTXAYB

Sample Output -
4
TC - O(n^2)
SC - O(n^2)
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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
    {
        // cout << 'Case ' << tc << endl;
        string a, b;
        cin >> a >> b;
        int a_size = a.size();
        int b_size = b.size();
        vvi lcs(a_size + 1, vi(b_size + 1, 0));
        for (int i = 0; i <= a_size; i++)
        {
            for (int j = 0; j <= b_size; j++)
            {
                if (i == 0 || j == 0)
                {
                    lcs[i][j] = 0;
                }
                else
                {
                    if (a[i - 1] == b[j - 1])
                    {
                        lcs[i][j] = 1 + lcs[i - 1][j - 1];
                    }
                    else
                    {
                        lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                    }
                }
            }
        }
        display(lcs);
        cout << "Length of LCS : " << lcs[a_size][b_size] << endl;
    }
    return 0;
}