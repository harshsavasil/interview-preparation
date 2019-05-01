#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int isAlphabet(char x)
{
	if((x>='a'&& x<='z')||(x>='A'&&x<='Z'))
		return 1;
	return 0;
}
string reverseTheString(string c)
{
	int l,r;
	l=0;
	r=c.size()-1;;
	while(l<r)
	{
		if(!isAlphabet(c[l]))
			l++;
		if(!isAlphabet(c[r]))
			r--;
		else
		{
			swap(c[l],c[r]);
			l++;
			r--;
		}
	}
	return c;
}
int main()
{
	string x;
	cin>>x;
	cout<<reverseTheString(x)<<endl;
}