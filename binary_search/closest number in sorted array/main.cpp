#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;

int findClosestNumber(const vi &array, int target) {
    int low = 0, high = array.size() - 1;
    int ans, maxDifference = INT_MAX;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == target) return target;
        if (array[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        int difference = abs(array[mid] - target);
        if (difference < maxDifference) {
            ans = array[mid];
            maxDifference = difference;
        }
    }
    return ans;
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n, k;
        cin >> n >> k;
        vi array;
        while(n--) {
            int number;
            cin >> number;
            array.push_back(number);
        }        
        int ans = findClosestNumber(array, k);
        cout << "TEST CASE : " << i << " - " << ans << endl; 
    }
    return 0;
}