#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	int a[100];
	char c[] = "pqruvwxyz";
	//ap + bq + cr + du + ev + fw + gx + hy + iz + j
	while(T--)
	{
		int an =0;
		int F = 1;
		for(int i =0; i  <10;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]!=0)
			{
				F = 0;
			}
		}
		if(F)
		{
			printf("0\n");
			continue;
		}
		int f = 0;
		for(int i = 0;i<9;i++)
		{
			if(a[i] == 0)
			{
				continue;
			}
			if(f == 0)
			{
				if(a[i] == 1)
				{
					printf("%c",c[i]);
				}
				else if(a[i] == -1)
				{
					printf("-%c",c[i]);
				}
				else
				{
					printf("%d%c",a[i],c[i]);
				}
				
				f = 1;
			}
			else
			{
				if(a[i] == 1)
				{
					printf("+%c",c[i]);
				}
				else if(a[i] == -1)
				{
					printf("-%c",c[i]);
				}
				else
				{
					printf("%+d%c",a[i],c[i]);
				}
				
				
			}
		}
		if(a[9])
		{
			if(f == 0)
			{
				printf("%d",a[9]);
				f = 1;
			}
			else
			{
				printf("%+d",a[9]);
			}
			
		}
		printf("\n");
		
	}


/*

10
0 0 0 0 0 0 0 0 0 0 
0 46 3 4 -5 -22 -8 -32 24 27
2 31 -5 0 0 12 0 0 -49 12

46q+3r+4u-5v-22w-8x-32y+24z+27
46q+3r+4u-5v-22w-8x-32y+24z+27
2p+31q-5r+12w-49z+12
2p+31q-5r+12w-49z+12
*/

 return 0;
}


