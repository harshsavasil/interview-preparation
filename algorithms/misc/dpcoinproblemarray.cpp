#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int j,i,n,Sum;
	cin>>n;
	cout<<"enter the value of sum"<<endl;
	cin>>Sum;
	int minValue[Sum+1];
	minValue[0]=0;
	for(i=1;i<=Sum;i++)
        minValue[i]=10000;
	int coin_value[n];
	for(i=0;i<n;i++)
		cin>>coin_value[i];

	for(i=1;i<=Sum;i++)
	{
        for(j=0;j<n;j++)
        {
            if(coin_value[j]<=i && minValue[i-coin_value[j]]+1 < minValue[i])
                minValue[i]= minValue[i-coin_value[j]]+1;
        }
        cout<<minValue[i]<<" "<<i<<endl;
	}
}
