#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int p[10],N=4,i;
	for(i=0;i<N;i++)
		p[i]=i;
	do
	{
		for(i=0;i<N;i++) printf("%d",p[i] );
		printf("\n");
	}while(next_permutation(p,p+N));
}