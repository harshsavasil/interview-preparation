#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int sum=0,ans=1;
	sort(arr,arr+n);
	for(i=1;i<=n;i++)
	{
		sum=sum+arr[i-1];
		if(sum<=(i*(i+1))/2)
			ans+=1;
	}
	cout<<ans;
}