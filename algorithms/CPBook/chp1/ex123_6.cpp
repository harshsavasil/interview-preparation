#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int L[]={5,4,3,2,0,6,89,85,520,44};
	int v=2;
	sort(L,L+10);
	printf("%d \n",binary_search(L,L+10,v));
}