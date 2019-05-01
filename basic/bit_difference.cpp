#include <iostream>
using namespace std;

int count_set_bits(int n) {
    int count = 0;
    while(n) {
        n &= (n-1);
        count += 1;
    }
    return count;
}
int xor_numbers(int x, int y) {
    return (x | y) & (~x | ~y); 
}
int main() {
    int t, a, b;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        int difference;
        difference = xor_numbers(a, b);
        cout<<count_set_bits(difference)<<endl; 
    }
    return 0;
}