#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}

vector<int> SieveOfEratosthenes(int n) { 
    vector<bool> prime(n+1, true);
    for (int p=2; p*p<=n; p++) { 
        if (prime.at(p)) {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    vector<int> primes;
    for(int i=2;i<prime.size();i++) {
        if (prime.at(i)) {
            primes.push_back(i);
        }
    }
    return primes; 
}

int calculatePrimePowerInFactorial(int n, int p) {
    int ans = 0, index = 1;
    // cout<<"n: "<< n << endl;
    while((n/power(p, index)) > 0) {
        ans += (n / power(p, index));
        // cout<<"n: "<< n << " p: "<< power(p, index) <<" power: " << ans << endl;
        index += 1;
    }
    return ans;
}
int main() {
    int t, n;
    vector<int> primes;
    long long ans = 1;
    cin>>t;
    while(t--) {
        ans = 1;
        cin>>n;
        if (n==0) {
            cout << n+1 << endl;
            continue; 
        }
        primes = SieveOfEratosthenes(n);
        for(int i=0;i<primes.size();i++) {
            int divisors = calculatePrimePowerInFactorial(n, primes[i]) + 1 % MOD;
            // cout << primes[i] << ": "<< divisors << endl;
            ans = (ans * divisors) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}