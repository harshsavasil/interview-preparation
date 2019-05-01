#include <iostream>
#include <string>

using namespace std;

string removeLeadingZeroes(string x)
{
	int i,n,count=0;
	n=x.size();
	for(i=0;i<n;i++)
	{
		if(x[i]=='0')
			count++;
		else
			break;
	}
	string y = x.substr(count);
	return y;
}
string decimalToBinary(string x)
{
	string ans;
	int n=0;
	while(true)
	{
		int carry=0;
		if(x.size()==1 && stoi(x)==0)
		{
			ans='0'+ans;
			return ans;
		}
		else if(x.size()==1 && stoi(x)==1)
		{	
			ans='1'+ans;
			return ans;
		}
		n=x.size();
		//cout<<x<<" "<<n<<endl;
		if((x[n-1]-'0')%2==0)
		{
			ans='0'+ans;
		}
		else
		{
			ans='1'+ans;
		}
		for(int i=0;i<n;i++)
		{
			//cout<<stoi(to_string(carry)+x[i])<<" "<<carry<<" "<<x<<endl;
			int y=stoi(to_string(carry)+x[i]);
			if(y%2==0)
			{
				carry=0;
			}
			else if(y%2!=0)
			{
				carry=1;
			}
			y/=2;
			x[i]=y+'0';
			//cout<<x<<" "<<y<<" "<<stoi(to_string(carry)+x[i])/2<<" "<<x[i]<<endl;
			//cout<<x[i]<<endl;
		}
		x=removeLeadingZeroes(x);
	}
}
int main()
{
	int a;
	string x;
	cin>>a;
	while(a--)
	{
		cin>>x;
		string ans = decimalToBinary(x);
		cout<<ans<<endl;
	}
}