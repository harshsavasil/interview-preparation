#include <iostream>
using namespace std;

bool at_position(int n, int position) {
    bool bit = n & (1<<position);
    return bit;
}

int main() {
    int t, n;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cin>>n;
        int answer = 0;
        for (int j=0; j<8; j++) {
            if(at_position(n, j)) {
                int new_position = (j+4) % 8;
                // cout<<j<<", "<<(1<<new_position)<<endl;
                answer += (1<<new_position);
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}