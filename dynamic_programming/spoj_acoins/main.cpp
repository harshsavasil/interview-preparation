#include <bits/stdc++.h>
using namespace std;

typedef vector<long long int> vl;
typedef vector<int> vi;

int main() {
    string n;
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    while(cin>>n) {
        if (n[0]=="0") break;
        int len = n.size();
        vl dp(len+1, 0);
        dp[0] = 1;
        for(int i=1; i < len; i++) {
            int num = (n[i-1] - '0') * 10 + (n[i] - '0');
            if(n[i] - '0') {
                dp[i] = dp[i-1];
            }
            if (num > 9 && num <= 26) {
                dp[i] += dp[i-2>0?i-2:0];
            }
        }
        cout<<dp[len-1]<<endl;
    }
    return 0;
}