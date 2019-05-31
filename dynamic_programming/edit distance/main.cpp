/*
 * Note: This template uses some c++11 functions , so you have to compile it
 * with c++11 flag. Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Harsh Gupta
 * Handle: harshsavasil
 *
 */

/*
Problem Description: Minimum Edit Distance
Given two strings str1 and str2 and below operations that can performed on str1.
Find minimum number of edits (operations) required to convert ‘str1’ into
‘str2’. Operations - Insert Remove Replace All of the above operations are of
equal cost.


Tags: Strings, Dynamic Programming, Distance Measure

Sample Input -
str1 = "geek", str2 = "gesek"

Sample Output -
1

Explanation - We can convert str1 into str2 by inserting a 's'.
*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
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
inline int ones(int n) {
    int res = 0;
    while (n && ++res) n -= n & (-n);
    return res;
}
template <class T>
void chmax(T &a, const T &b) {
    a = max(a, b);
}
template <class T>
void chmin(T &a, const T &b) {
    a = min(a, b);
}

/////////////////////////////////////////////////////////////////////
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) {
        string a, b;
        cin >> a >> b;
        int a_size = a.size();
        int b_size = b.size();
        vvi distance(a_size + 1, vi(b_size + 1, -1));
        distance[0][0] = 0;
        for (int i = 0; i <= a_size; i++) {
            for (int j = 0; j <= b_size; j++) {
                if (i == 0 && j == 0) {
                    distance[i][j] = 0;
                } else if (i == 0) {
                    distance[i][j] = j;
                } else if (j == 0) {
                    distance[i][j] = i;
                } else {
                    if (a[i - 1] == b[j - 1]) {
                        distance[i][j] = distance[i - 1][j - 1];
                    } else {
                        distance[i][j] = min(distance[i - 1][j - 1], min(distance[i - 1][j], distance[i][j - 1])) + 1;
                    }
                }
            }
        }
        cout << "Edit Distance between " << a << " and " << b << " is " << distance[a_size][b_size] << endl;
    }
    return 0;
}