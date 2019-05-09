// TC - O(n) | SC- O(n)
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vi arr;
    vi rightMax(n);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int low = 0, high = n - 1;
    int total_water = 0;
    int max_left = INT_MIN, max_right = INT_MIN;
    int result = 0;
    while(low <= high) {
        if (arr[low] < arr[high]) {
            if (arr[low] > max_left) {
                max_left = arr[low];
            } else {
                result += (max_left - arr[low]);
            }
            low++;
        } else {
            if (arr[high] > max_right) {
                max_right = arr[high];
            } else {
                result += (max_right - arr[high]);
            }
            high--;
        }
    }
    cout << "Total Water Trapped: " << result << endl; 
    return 0;
}