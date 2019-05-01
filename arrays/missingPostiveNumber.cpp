#include <bits/stdc++.h>
using namespace std;
//Compiler version g++ 6.3.0
typedef vector<int> vi;

int main()
{
    int n;
    cin >> n;
    vi arr(n, 0);
    for(int i =0; i<n; i++) {
        cin >> arr[i];
    }
    int j = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(int i = j; i < n; i++) {
        if (abs(arr[i]) + j - 1 < n) {
            arr[abs(arr[i]) + j - 1] = -arr[abs(arr[i]) + j - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = j; i < n; i++) {
        if (arr[i] > 0) {
            cout << i - j + 1 << endl;
            return 0;
        }
    }
    cout << n - j + 1 << endl;
    return 0;
}
