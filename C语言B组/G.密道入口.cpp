#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>

using namespace std;

int num[10];
int add[10];


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(num,0,sizeof(num));
		int a;
		scanf("%d",&a);
		add[0] = num[a%10] = 1;
		a /= 10;
		add[1] = num[a%10] = 1;
		add[2] = num[a/10] = 1;
		for(int i = 0;i < 10;i++)
		{
			printf("%d\n",num[i]);
		}
		for(int i = 3;i < 10;i++)
		{
			
		}
	}
}


