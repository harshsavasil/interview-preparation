#include <bits/stdc++.h>
// #include <cstdio>
// #include <vector>
// #include <cmath>
// #include <map>
// #include <set>
// #include <algorithm>
#define pb push_back
#define all(c) c.begin(),c.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it!=container.end();it++) 
#define present(container, element) (container.find(element) != container.end()) //for set,map etc.
#define cpresent(container, element) (find(all(container),element) != container.end()) //for vector
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;

double findMedian(vi arr1, vi arr2) {
    if(arr1.size() > arr2.size()) {
        return findMedian(arr2, arr1);
    }
    int x = arr1.size(); // smaller array use binary search on this one
    int y = arr2.size();
    int low = 0, high = x;
    while(low <= high) {
        int partitionX = low + (high - low) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;
        int maxLeftX =  partitionX == 0 ? INT_MIN : arr1[partitionX - 1];
        int minRightX =  partitionX == x ? INT_MAX : arr1[partitionX];
        int maxLeftY =  partitionY == 0 ? INT_MIN : arr2[partitionY - 1];
        int minRightY =  partitionY == y ? INT_MAX : arr2[partitionY];
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Median found 
            if ((x + y) & 1) {
                // odd case
                return max(maxLeftX, maxLeftY);
            } else {
                // even case
                return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            }
        } else if (maxLeftX > minRightY){
            // move left
            high = partitionX - 1;
        } else {
            // move right
            low = partitionX + 1;
        }
    }
    // We will reach here only when arrays are not sorted.
    return -1;
}
int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vi arr1, arr2;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr1.push_back(num);
        }
        for(int i = 0; i < m; i++) {
            int num;
            cin >> num;
            arr2.push_back(num);
        }
        cout << findMedian(arr1, arr2) << endl;
    }
    return 0;
}