#include <string>
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string x;
	while(t--)
	{
		cin>>x;
		if(x.size()==5)
			cout<<3<<endl;
		else
		{
			if(x[0]=='o')
			{
				if(x[1]=='n' || x[2]=='e')
					cout<<1<<endl;
				else
					cout<<2<<endl;
			}
			else
			{
				if(x[1]=='w' || x[2]=='o')
					cout<<2<<endl;
				else
					cout<<1<<endl;
			}
		}
	}
}