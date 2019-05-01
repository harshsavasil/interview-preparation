#include <cstdio>
using namespace std;
int main()
{
	int k;
	while(scanf("%d",&k),k)
	{
		int division_x,division_y,x,y;
		scanf("%d %d",&division_x,&division_y);
		for(int i=0;i<k;i++)
		{
			scanf("%d %d",&x,&y);
			if(x==division_x || y==division_y)
				printf("divisa\n");
			else if(x>division_x && y>division_y)
				printf("NE\n");
			else if(x<division_x && y>division_y)
				printf("NO\n");
			else if(x>division_x && y<division_y)
				printf("SE\n");
			else if(x<division_x && y<division_y)
				printf("SO\n");
		}
	}
}