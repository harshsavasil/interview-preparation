#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ugly[n+1],next_ugly_num,temp;
    int i2=0,i3=0,i5=0,i;
    ugly[0]=1;
    int next_multiple_of_2 = ugly[i2] * 2;
    int next_multiple_of_3 = ugly[i3] * 3;
    int next_multiple_of_5 = ugly[i5] * 5;
    for(i=1;i<=n;i++)
    {
        temp = min(next_multiple_of_2,next_multiple_of_3);
        next_ugly_num = min(next_multiple_of_5,temp);
        ugly[i]=next_ugly_num;
        if(next_ugly_num == next_multiple_of_2)
        {
            i2=i2+1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if(next_ugly_num == next_multiple_of_3)
        {
            i3=i3+1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if(next_ugly_num == next_multiple_of_5)
        {
            i5=i5+1;
            next_multiple_of_5 = ugly[i5] * 5;
        }
       // cout<<temp<<" "<<i<<" "<<i2<<" "<<i3<<" "<<i5<<endl;
    }
    for(i=0;i<n;i++)
        cout<<ugly[i]<<endl;
}
