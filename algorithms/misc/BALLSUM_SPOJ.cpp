#include <cstdio>
#include <cmath>
using namespace std;

long long int gcd(long long int a,long long int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
int main()
{
	long p,q;
	long long int numerator,denominator,common;
	while(scanf("%ld %ld",&p,&q),(p!=-1 && q!=-1))
	{
		if(q<3)
		{
			printf("0\n");
			continue;
		}
		if(q&1)
			numerator=(q-1)*(q-1)/4;
		else
			numerator = (q/2)*(q-2)/2;
		denominator = p*(p-1)/2;
		if(numerator>=denominator)
			printf("1\n");
		else
		{
			common = gcd(numerator,denominator);
			numerator = numerator/common;
			denominator = denominator/common;
			printf("%lld/%lld\n",numerator,denominator);
		}
	}

	return 0;
}
