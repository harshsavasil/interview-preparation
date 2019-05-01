// Kadane's Algorithm
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

#define pb push_back
using namespace std;

typedef vector<int> vi; 

int main() {
    int n, number;
    cin >> n;
    vi numbers;
    while(n--) {
        cin >> number;
        numbers.push_back(number);
    }
    int maxSum = 0, localstartIndex = -1, globalstartIndex = -1,  localSum = 0;
    for(int i=0; i<numbers.size(); i++) {
        // cout << localSum << ", " << numbers.at(i) << ", " << maxSum << endl;
        localSum += numbers.at(i);
        if (localSum > maxSum) {
            maxSum = localSum;
            globalstartIndex = localstartIndex;
        }
        if (localSum <= 0) {
            localSum = 0;
            localstartIndex = i+1;
        }
    }
    cout << maxSum << ": " << globalstartIndex << endl;
    return 0;
}