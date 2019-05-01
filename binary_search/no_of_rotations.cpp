#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int index_of_pivot(const vi &arr, int n) {
    int low = 0, high = n - 1;
    if (arr[low] <= arr[high]) { return low;}
    int mid = (low + high ) / 2;
    int next = (mid + 1) % n;
    int prev = (mid + n - 1) % n;
}
int main(void) {
    int n;
    cin >> n;
    vi arr(n, 0);
    while(n--) {
        cin >> arr[i];
    }
    cout << no_of_rotations(arr, arr.size()) << endl;
    return 0;
}