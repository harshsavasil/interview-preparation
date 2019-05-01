#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int T,i,j;
	cin>>T;
	string x,y;
	while(T--)
	{
		set <string>distinctSubstrings;
		cin>>x;
		for(i=0;i<x.size();i++)
		{
			for(j=0;j<x.size()-i;j++)
			{
				y=x.substr(j,i+1);
				distinctSubstrings.insert(y);
			}
		}
		cout<<distinctSubstrings.size()<<endl;
	}
	return 0;
}