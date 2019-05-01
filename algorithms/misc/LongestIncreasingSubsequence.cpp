#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int lis(int arr[],int n)
{
	int res;
	int maxLength=1;
	if (n==1)
		return 1;
	for(int i=1;i<n;i++)
	{
		res = lis(arr,i);
		if(res+1<maxLength && arr[i-1]<arr[n-1])
			maxLength=res+1;
	}
	return maxLength;
}
int main()
{
	int arr[]={1,7,3,8,2,4,5,6};
	int ans=lis(arr,8);
	cout<<ans<<endl;
}