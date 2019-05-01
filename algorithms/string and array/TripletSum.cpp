#include <iostream>
using namespace std;

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
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			value=0;
			for(k=j+1;k<=n;k++)
			{
				value=arr[i-1]+arr[j-1]+arr[k-1];
				if(value<=sum)
					count++;
			}
		}
	}
	cout<<count<<endl;
}