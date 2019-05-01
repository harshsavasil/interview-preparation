#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii ,int> iii;
int main()
{
	iii A = make_pair(ii(5,24),-1982);
	iii C = make_pair(ii(11,13),-1983);
	iii B = make_pair(ii(5,24),-1980);
	vector<iii> birthdays;
	birthdays.push_back(A);birthdays.push_back(B);birthdays.push_back(C);
	for(int i=0;i<birthdays.size();i++)
	{
		printf("%d %d %d\n",birthdays[i].first.first,birthdays[i].first.second,birthdays[i].second );
	}
	sort(birthdays.begin(),birthdays.end());
	for(int i=0;i<birthdays.size();i++)
	{
		printf("%d %d %d\n",birthdays[i].first.first,birthdays[i].first.second,birthdays[i].second );
	}
}