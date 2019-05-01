#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int c=0;
	char s[100000];
	while(gets(s))
	{
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]=='"' && c==0)
			{
				cout<<"``";
				c=1;
			}
			else if(s[i]=='"' && c==1)
			{
				cout<<"''";
				c=0;
			}
			else
				cout<<s[i];
		}
		printf("\n");
	}
}