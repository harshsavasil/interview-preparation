#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;

// Returns the nth ugly number
// Ugly Numbers are numbers conatining only powers of prime numbers - 2, 3 and 5.    
int ugly_number(int n) {
    // if (ugly_numbers[n] != -1) return ugly_numbers[n];
    int i2=0, i3=0, i5=0;
    vll ugly(n);
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    ugly[0] = 1; 
    for(int i = 1; i < n; i++) {
        unsigned next_value = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_value;
        cout << "i: " << i << ", i2: " << i2 << ", i3: " << i3 << ", i5: " << i5 << ", value: " << next_value << endl;
        if (next_value == next_multiple_of_2) {
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        } else if (next_value == next_multiple_of_3) {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        } else {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ugly[i] << ", ";
    }
    cout << endl;
    return ugly[n-1];
}
int main() {
    int n;
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    while(cin >> n) {
        int ans = ugly_number(n);
        cout << "ans : " << ans << endl;
    }
    return 0;
}