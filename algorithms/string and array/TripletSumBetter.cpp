#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countTriplets(int arr[],int n,int value)
{
	sort(arr,arr+n);
	int i,j,k,ans=0;
	for(i=0;i<n-2;i++)
	{
		j=i+1;
		k=n-1;
		while(j<k)
		{
			if(arr[i]+arr[j]+arr[k]>=value)
				k--;
			else
			{
				ans+=(k-j);
				j++;
			}
		}	
	}
	return ans;
}
int main()
{
	int n,sum,value,count=0;
	cin>>n>>sum;
	int i,j,k;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int ans = countTriplets(arr,n,sum);
	cout<<ans;
}