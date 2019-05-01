#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int p[20],N=5,i,j;
	for(i=0;i<N;i++) p[i]=i+1;
	for(i=1;i<(1<<N);i++)
	{
		for(j=0;j<N;j++)
			if((i&(1<<j))!=0)
				printf("%d ",p[j]);	
		printf("\n");
	}
}