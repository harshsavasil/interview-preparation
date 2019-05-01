#include <bits/stdc++.h>
using namespace std;

void display(const vector<int> &arr) {
    for(int i =0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
vector<int> plusOne(vector<int> &A) {
    vector<int> ans;
    int carry = 1;
    int n = A.size();
    int i = n - 1;
    while(i >= 0) {
        // cout << "i: " << i << " n: " << n << " carry: " << carry << " v:" << A[i] << endl;
        int currentDigit = (A[i] + carry) % 10;
        carry = (A[i] + carry) / 10;
        ans.push_back(currentDigit);
        i--;
    }
    if (carry) {
        ans.push_back(carry);
    }
    display(ans);
    int j = ans.size() - 1;
    while(j >= 0) {
        if (ans[j] == 0) {
            ans.pop_back();
        } else {
            break;
        }
        j--;
    }
    reverse(ans.begin(), ans.end());
    display(ans);
    return ans;
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
    vector<int> ans = plusOne(arr);
    display(ans);
    return 0;
}