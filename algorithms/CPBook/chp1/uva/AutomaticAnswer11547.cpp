#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ans = ((n*63+7492)*5)-498;
		ans=(ans%100)/10;
		ans=abs(ans);
		printf("%d\n",ans);
	}
}
