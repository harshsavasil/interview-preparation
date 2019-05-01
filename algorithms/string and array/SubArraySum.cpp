#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int currentSum=arr[0],start=0;
	for(i=1;i<=n;i++)
	{
		while(currentSum>m && start<i-1)
		{
			currentSum=currentSum-arr[start];
			start++;
		}
		if(currentSum==m)
		{
			cout<<start<<" "<<(i-1)<<endl;
		}
		currentSum+=arr[i-1];
	}
}