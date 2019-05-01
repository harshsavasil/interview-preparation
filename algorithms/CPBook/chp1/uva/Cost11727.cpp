#include <cstdio>
using namespace std;
int main()
{
	int a,b,c,k=1;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a>b&&a>c)
		{
			if(b>c)
				printf("Case %d: %d\n",k,b );
			else
				printf("Case %d: %d\n",k,c );
		}
		else if(b>c)
		{
			if(a>c)
				printf("Case %d: %d\n",k,a );
			else
				printf("Case %d: %d\n",k,c);
		}
		else
		{
			if(a>b)
				printf("Case %d: %d\n",k,a);
			else
				printf("Case %d: %d\n",k,b );
		}
		k++;
	}
}
