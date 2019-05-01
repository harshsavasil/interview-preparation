#include <iostream>

using namespace std;

int recursive_binary_search(int arr[], int left, int right, int value) {
    if (right >= left) {
        int middle = left + (right - left)/2;
        if (arr[middle] == value) {
            return middle;
        }
        if (value > arr[middle]) {
            return recursive_binary_search(arr, middle + 1, right, value);
        }
        return recursive_binary_search(arr, left, middle - 1, value); 
    }
    return -1;
}

int iterative_binary_search(int arr[], int left, int right, int value) {
    int ans = -1;
    while (right >= left) {
        int middle = left + (right - left)/2;
        if (arr[middle] == value) {
            ans = middle;
            // left = middle + 1;
            right = middle - 1;
        }
        if (value > arr[middle]) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        } 
    }
    return ans;
}

void printArray(int arr[], int n) { 
   int i; 
   for (i=0; i < n; i++) 
       printf("%d ", arr[i]); 
   printf("\n"); 
} 

int* insertion_sort(int arr[], int n) {
    int key;
    cout << n << endl;
    for(int i=1; i<n; i++) {
        int j = i -1;
        key = arr[i];
        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    printArray(arr, n);
    return arr;
}

int main() {
    int t, length;
    cin>>t;
    while(t--) {
        cin>>length;
        int arr[length];
        for(int i=0; i<length; i++) {
            cin>>arr[i];
        }
        // int length = sizeof(arr)/sizeof(arr[0]);
        // int value;
        // cin>>value;
        // cout<<recursive_binary_search(arr, 0, length, value)<<endl;
        // cout<<iterative_binary_search(arr, 0, length, value)<<endl;
        printArray(arr, length);
        int *new_arr = insertion_sort(arr, length);
        printArray(new_arr, length);
    }
    return 0;
}