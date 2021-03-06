#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define pb push_back
#define all(c) c.begin(),c.end()
#define MAX 10000
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it!=container.end();it++) 
#define present(container, element) (container.find(element) != container.end()) //for set,map etc.
#define cpresent(container, element) (find(all(container),element) != container.end()) //for vector
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;

int find_peak(int arr[], int left, int right, int n) {
    int middle = (left + right) / 2;
    if ((middle == 0 || arr[middle-1] <= arr[middle]) && 
            (middle == n-1 || arr[middle+1] <= arr[middle])) 
        return arr[middle];
    else if (middle > 0 && arr[middle] < arr[middle - 1]) {
        return find_peak(arr, left, middle-1, n);
    }
    return find_peak(arr, middle+1, right, n);
}
int find_peak_divide_and_conquer(int* arr, int n) {
    return find_peak(arr, 0, n-1, n);
}

int find_peak_brute_force(int* arr, int n) {
    if (arr[0] >= arr[1]) {
        return arr[0];
    }
    if (arr[n-1] >= arr[n-2]) {
        return arr[n-1];
    }
    for( int i=1; i<n-1; i++ ) {
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]) {
            return arr[i];
        }
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    } 
    printf("peak Element is %d.\n", find_peak_brute_force(arr, n)); 
    printf("peak Element is %d.\n", find_peak_divide_and_conquer(arr, n)); 
    return 0;
}