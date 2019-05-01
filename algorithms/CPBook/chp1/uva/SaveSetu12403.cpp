#include <string>
#include <iostream>
using namespace std;
int main()
{
	int t;
	string x,val;
	cin>>t;
	int ans=0;
	while(t--)
	{
		cin>>x>>val;
		if(x[0]='d')
		{
			ans=ans+stoi(val);
		}	
		else
			cout<<ans<<endl;
	}
}
