#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N;
	int a,b;
	cin>>N;
	while(N--)
	{
		cin>>a>>b;
		cout<<(a/3)*(b/3);
		cout<<endl;
	}
}