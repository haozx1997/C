#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n;//¸Älonglong 
int a[100100];
int abs(int a)
{
	if(a<0)
	return 0-a;
	return a;	
}

int al[100100];
int ar[100100];
int abn[100100];
		
void see()
{
	for(int i = 1;i <= n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int TT = 0;TT < T;TT++)
	{
		memset(abn,0,sizeof(abn));
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			ar[a[i]] = al[a[i]] = i;
		}
		for(int i=1;i<=n;++i)
    	{
    		for(int j=i+1;j<=n;j++)
        	{
        		if(a[j] < a[i])
            	{	
					abn[a[i]]++;
				}
			}
		}
		
		for(int i = 1;i <= n;i++)
		{
			if(al[a[i]]>a[i]) 
			{
				al[a[i]] = a[i];
			}
			ar[a[i]] += abn[a[i]];
			
		}		
//		for(int i = 1;i <= n;i++)
//		{
//			printf("%d %d %d %d \n",i,al[i],ar[i],ar[i]-al[i]);
//			
//		}		
//		printf("\n");
	printf("Case #%d:",TT+1);
	for(int i = 1;i <= n;i++)
		{
			printf(" %d",ar[i]-al[i]);
			
		}
	printf("\n");	
	}
}
