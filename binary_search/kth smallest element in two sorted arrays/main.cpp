#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef vector<int> vi;

int kth(const vi &arr1, const vi &arr2, int k) {
    cout << arr1.size() << " : " << arr2.size() << " : " << k << endl;
    if (arr1.size() == 0) return arr2[k];
    if (arr2.size() == 0) return arr1[k];
    if(arr1[k/2] < arr2[k/2]) {
        return kth(vi(arr1.begin() + k/2, arr1.end()), arr2, arr1.size() - 1 - k/2);
    }
    return kth(arr1, vi(arr2.begin() + k/2, arr2.end()), arr2.size() - 1 - k/2);
}

int main() {
    int n, m, k;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    vi arr1, arr2;
    int num;
    while(n--) {
        cin >> num;
        arr1.pb(num);        
    }
    while(m--) {
        cin >> num;
        arr2.pb(num);        
    }
    cout << kth(arr1, arr2, k) << endl;
    return 0;
}