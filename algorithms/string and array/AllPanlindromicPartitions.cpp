#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int isPalindrome(string x)
{
	int l=0,r;
	r=x.size()-1;
	while(l<r)
	{
		if(x[l]!=x[r])
			return 0;
		l++;
		r--;
	}
	return 1;
}
void printPalindromicPartitions(string x)
{
	int i,j,n;
	n=x.size();
	if(n<=0)
		return;
	string temp_substring;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			//printPalindromicPartitions(x.substr(0,j-1));
			temp_substring=x.substr(j-1,n-i+1);
			if(isPalindrome(temp_substring)==1)
				cout<<temp_substring<<endl;
			//printPalindromicPartitions(x.substr(n+j-i));
		}
	}

}
int main()
{
	string x;
	cin>>x;
	printPalindromicPartitions(x);
}