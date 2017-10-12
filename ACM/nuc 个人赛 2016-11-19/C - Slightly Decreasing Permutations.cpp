#include<stdio.h> 
#include<algorithm>

using namespace std;
int n,k;
int num;
void p()
{
	num++;
	if(num == n)
		printf("\n");
	else
		printf(" ");
}

int main()
{
	//freopen("1.txt","r",stdin);
	
	while(~scanf("%d%d",&n,&k))
	{
		num = 0;
		for(int i = 1;i < n-k;i++)
		{
			printf("%d",i);
			p();
		}
		for(int i = n;i >= n-k;i--)
		{
			printf("%d",i);
			p();
		}
	}

}
