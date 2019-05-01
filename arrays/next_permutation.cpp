#include <bits/stdc++.h>
using namespace std;

void display(const vector<int> &arr) {
    for(int i =0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void nextPermutation(vector<int> &A) {
    int leftIndex = -1, n;
    n = A.size();
    for(int i = 0; i < n - 1; i++) {
        // cout << i << " " << A.at(i) << endl;
        if (A[i] < A[i+1]) {
            leftIndex = i; 
        }
    }
    if (leftIndex != -1) {
        int rightIndex = -1;
        for(int i = n - 1; i >= leftIndex + 1; i--) {
            if (A[i] > A[leftIndex]) {
                rightIndex = i;
                break;
            }
        }
        swap(A[leftIndex], A[rightIndex]);
    }
    sort(A.begin() + leftIndex + 1, A.end());
    display(A); 
}

int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int i = 0;
    while(i < n) {
        cin >> arr[i];
        i++;
    }
    nextPermutation(arr);
    // display(ans);
    return 0;
}
