#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(void) {
    int t;
    cin >> t;
    int n, x, y;
    int maxY = -1;
    while(t--) {
        vi arr(100000, 0);
        cin >> n;
        for(int i=0; i < n; i++) {
            cin >> x >> y;
            arr[x+32768] += 1;
            arr[y+32769] -= 1;
            maxY = max(y+32769, maxY);
        }
        int result = 0;
        for(int i=1; i < maxY + 1; i++) {
            arr[i] = arr[i-1] + arr[i];
            cout << i << " " << arr[i] << endl;
            if(arr[i] > 0) {
                result++;
            } 
        }
        cout << result << endl;
    }
    return 0;
}