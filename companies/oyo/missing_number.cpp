#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(void) {
    int n, number;
    cin>>n;
    vi arr;
    int sum = 0;
    for(int i=0; i<n-1; i++) {
        cin>>number;
        arr.push_back(number);
        sum += number;
    }
    int x1, x2;
    x1 = arr.at(0);
    x2 = 1;
    for(int i=1; i<n-1; i++) {
        x1 ^= arr.at(i); 
    }
    for(int i=2; i <= n; i++) {
        x2 ^= i; 
    }
    cout<<(n*(n+1))/2 - sum<<endl;
    cout << (x1^x2) << endl;
    return 0;
}