#include <iostream>
using namespace std;

int main()
{
    int i,n;
    cin>>n;
    int arr[n],maxLength[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        maxLength[i]=0;
    }
    maxLength[0]=1;
    for(i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1] && maxLength[i-1]+1>maxLength[i])
        maxLength[i] = maxLength[i-1] + 1;
    }
}
