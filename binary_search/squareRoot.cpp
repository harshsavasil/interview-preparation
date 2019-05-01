#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    int low = 0, high = x;
    if (x < 2) return x;
    while(low < high) {
        int mid = (high + low) / 2;
        if (x / mid >= mid) low = mid + 1;
        else high = mid;
    }
    return high - 1;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << mySqrt(n) << endl;
    }
    return 0;
}