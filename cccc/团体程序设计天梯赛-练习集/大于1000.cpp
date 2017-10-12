#include<stdio.h>
#include<string.h> 


int main()
{
	int sum = 0;
	int n = 1000;
	int i,j = 1;
	for(i = 0;;i++)
	{
		sum+=j;
		j*=2;
		printf("%d %d\n",i,sum);
		if(sum>1000)break;
	}
	printf("%d",i);
}
