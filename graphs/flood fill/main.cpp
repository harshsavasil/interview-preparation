/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*
* Author : Harsh Gupta
* Handle: harshsavasil
*
*/

/*
Problem Description: Flood Fill
In MS-Paint, when we take the brush to a pixel and click,
the color of the region of that pixel is replaced with a new selected color.

Tags: Graph Traversal

Sample Input -
Given a 2D screen, location of a pixel in the screen and a color,
replace color of the given pixel and all adjacent same colored pixels with the given color.

screen[M][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 1, 0, 1, 1},
    {1, 2, 2, 2, 2, 0, 1, 0},
    {1, 1, 1, 2, 2, 0, 1, 0},
    {1, 1, 1, 2, 2, 2, 2, 0},
    {1, 1, 1, 1, 1, 2, 1, 1},
    {1, 1, 1, 1, 1, 2, 2, 1},
};
x = 4, y = 4, newColor = 3
Sample Output -
screen[M][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 1, 0, 1, 1},
    {1, 3, 3, 3, 3, 0, 1, 0},
    {1, 1, 1, 3, 3, 0, 1, 0},
    {1, 1, 1, 3, 3, 3, 3, 0},
    {1, 1, 1, 1, 1, 3, 1, 1},
    {1, 1, 1, 1, 1, 3, 3, 1},
};

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

vii getNeighbours(int row, int column) {
    return {
        make_pair(row - 1, column - 1),
        make_pair(row - 1, column),
        make_pair(row - 1, column + 1),
        make_pair(row, column - 1),
        make_pair(row, column + 1),
        make_pair(row + 1, column - 1),
        make_pair(row + 1, column),
        make_pair(row + 1, column + 1),
    };
}
void dfs(vvi& visited, vvi& screen_matrix, int row, int column, int oldColor, int newColor) {
    if (row < 0 || row >= screen_matrix.size()) {
        return;
    }
    if (column < 0 || column >= screen_matrix[0].size()) {
        return;
    }
    if (visited[row][column]) return;
    if (screen_matrix[row][column] != oldColor) return;
    screen_matrix[row][column] = newColor;
    visited[row][column] = 1;
    vii neighbours = getNeighbours(row, column);
    for (ii neighbour : neighbours) {
        dfs(visited, screen_matrix, neighbour.first, neighbour.second, oldColor, newColor);
    }
}

void display(const vvi data) {
    int row = data.size();
    int column = data[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void displayResults(vvi screen_matrix, int x_coordinate, int y_coordinate, int newColorCode) {
    cout << "Screen Color Representation before Painting : " << endl;
    display(screen_matrix);
    int m = screen_matrix.size();
    int n = screen_matrix[0].size();
    vvi visited(m, vi(n, 0));
    int oldColor = screen_matrix[x_coordinate][y_coordinate];
    dfs(visited, screen_matrix, x_coordinate, y_coordinate, oldColor, newColorCode);
    cout << "Flood Fill is called on (" << x_coordinate << ", " << y_coordinate << ")" << endl;
    cout << "New Color Code : " << newColorCode << endl;
    cout << "Screen Color Representation after Painting : " << endl;
    display(screen_matrix);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n;
    cin >> m >> n;
    vvi screen_matrix(m, vi(n, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> screen_matrix[i][j];
        }
    }
    int x_coordinate, y_coordinate, newColorCode;
    cin >> x_coordinate >> y_coordinate;
    cin >> newColorCode;
    displayResults(screen_matrix, x_coordinate, y_coordinate, newColorCode);
    return 0;
}