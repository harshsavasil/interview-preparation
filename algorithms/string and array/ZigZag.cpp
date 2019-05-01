#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
	string x,temp;
	getline(cin,x);
	int i,n,numbers=0;
	//cout<<n<<" "<<x<<endl;
	int arr[(n+1)/2];
	x=x+' ';
	n=x.size();
	for(i=0;i<n;i++)
	{
		if(x[i]!=' ')
			temp=temp+x[i];
		else
		{
			arr[numbers]=stoi(temp);
			temp=' ';
			numbers++;
		}	
	}
	for(i=0;i<numbers-1;i++)
	{
		if(i%2==0)
		{
			if(arr[i]>arr[i+1])
				swap(arr[i],arr[i+1]);
		}
		else
		{
			if(arr[i]<arr[i+1])
				swap(arr[i],arr[i+1]);
		}
	}
	for(i=0;i<numbers;i++)
	{
		cout<<arr[i]<<" ";
	}
}