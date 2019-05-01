#include <vector>
#include <algorithm>
#include <cstdio>
#define ALL(x) x.begin(),x.end()
#define UNIQUE(c) (c).erase(unique(ALL(c)),(c).end())
using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {1,2,2,2,3,3,2,3,1};
	vector<int> v(a,a+9);
	sort(ALL(v));
	UNIQUE(v);
	for (int i = 0; i < (int)v.size(); ++i)
	{
		printf("%d\n",v[i] );
	}
	return 0;
}