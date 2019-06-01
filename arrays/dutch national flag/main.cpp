/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*
* Author : Harsh Gupta
* Handle: harshsavasil
*
*/

/*
Problem Description: Dutch National Flag
Given an array with n objects colored red, white or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Tags: Sorting, count sort

Sample Input -
[2,0,2,1,1,0]

Sample Output -
[0,0,1,1,2,2]

TC - O(n)
SC - O(1)
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
typedef vector<vector<int> > vvi;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
    int res = 0;
    while (n && ++res) n -= n & (-n);
    return res;
}
template <class T>
void chmax(T& a, const T& b) { a = max(a, b); }
template <class T>
void chmin(T& a, const T& b) { a = min(a, b); }

void display(const vi data) {
    int n = data.size();
    for (int i = 0; i < n; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}
void sortColors(vi& colors) {
    int n = colors.size();
    int left = 0, current = 0;
    int right = n - 1;
    while (current < right) {
        if (colors[current] == 0) {
            swap(colors[left++], colors[current++]);
        } else if (colors[current] == 1) {
            current++;
        } else {
            swap(colors[right--], colors[current]);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vi colors(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> colors[i];
        }
        cout << "original array : " << endl;
        display(colors);
        sortColors(colors);
        cout << "sorted array : " << endl;
        display(colors);
    }
    return 0;
}