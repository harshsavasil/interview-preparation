#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int t,n,max=0,min=100;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int value;
		max=0,min=100;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&value);
			if(value>max)
				max=value;
			if(value<min)
				min=value;
		}	
		printf("%d\n",2*(max-min));
	}
	return 0;
}
