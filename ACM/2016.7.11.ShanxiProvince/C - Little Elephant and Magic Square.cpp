#include<string.h>
#include<stdio.h>
int sq [10];


int main()
{
	for(int i = 1;i < 10;i++)
	{
		scanf("%d",&sq[i]);
		
	}
	int sum = sq[8] + sq[2];
	sum = sum/2;
	sum = sum*3;
	sq[1] = sum - sq[2] - sq[3];
	sq[5] = sum - sq[4] - sq[6];
	sq[9] = sum - sq[7] - sq[8];
	for(int i = 1;i < 10;i++)
	{
		if(i%3)
		{
			printf("%d ",sq[i]);
		}
		else
		{
			printf("%d\n",sq[i]);
		}
	}
}

