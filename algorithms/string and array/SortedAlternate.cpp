#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
	string x,y,temp;
	getline(cin,x);
	getline(cin,y);
	int i,j,k,a,b,number1=0,number2=0;
	//cout<<n<<" "<<x<<endl;
	int A[10000],B[10000];
	x=x+' ';
	a=x.size();
	b=y.size();
	for(i=0;i<a;i++)
	{
		if(x[i]!=' ')
			temp=temp+x[i];
		else
		{
			A[number1]=stoi(temp);
			temp=' ';
			number1++;
		}	
	}
	temp=' ';
	for(i=0;i<b;i++)
	{
		if(y[i]!=' ')
			temp=temp+y[i];
		else
		{
			B[number2]=stoi(temp);
			temp=' ';
			number2++;
		}	
	}
	for(i=0;i<number1;i++)
	{
		j=A[i+1];
		k=B[0];
		while(j<number1 && k<number2)
		{
			if(B[k]>A[i])
			{
				count++;
				k++;
			}
		}

	}


	for(i=0;i<number1;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<number2;i++)
	{
		cout<<B[i]<<" ";
	}
}