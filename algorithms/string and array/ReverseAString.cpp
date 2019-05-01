#include <iostream>
#include <string>
using namespace std;

int main()
{
	string x,y,z;
	cin>>x;
	int n,j;
	n=x.size();
	for(int i=0;i<n;i++)
	{
		if((x[i]>='a'&& x[i]<='z')||(x[i]>='A'&& x[i]<='Z'))
		{
			y=x[i]+y;	
		}
	}
	int y_pointer=0;
	for(int i=0;i<n;i++)
	{
		if((x[i]>='a'&& x[i]<='z')||(x[i]>='A'&& x[i]<='Z'))
		{
			z=z+y[y_pointer];
			y_pointer++;	
		}
		else
		{
			z=z+x[i];
		}
	}
	cout<<z<<endl;
}