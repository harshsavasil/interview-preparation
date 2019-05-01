#include <bits/stdc++.h>
using namespace std;

int main()
{
	string x,temp;
	getline(cin,x);
	int i,n,numbers=0;
	int arr[100000];
	x=x+' ';
	n=x.size();
	for(i=0;i<n;i++)
	{
		if(x[i]!=' ')
			temp=temp+x[i];
		else
		{
			arr[numbers]=stoi(temp)*stoi(temp);
			temp=' ';
			numbers++;
		}	
	}
	int j,k;
	sort(arr,arr+numbers);
	for(i=numbers-1;i>=2;i--)
	{
		j=0;
		k=i-1;
		while(j<k)
		{
			if(arr[k]+arr[j]<arr[i])
				j++;
			else if(arr[k]+arr[j]==arr[i])
			{
				cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
				break;
			}
			else
			{
				k--;
			}
		}
	}
}