#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<map>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		int a[100100];
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n ;i++)
		{
			scanf("%d",&a[i]);
			
		}
		int sum = a[0];
		int head = 0;
		int tail = 0;
		int f = 0;
		while(1)
		{
		//	printf("%d %d\n",head,tail); 
			if(sum>=m)
			{
				if((m%sum)==0)
				{
					f= 1;
					break;
				}
				else if(tail<(n-1))
				{
					tail++;
					sum += a[tail];
					if((m%sum)!=0&&tail == (n-1))
					 {
					 	head++;
						if(head>=n)
						{
							break;
						}
						tail = head;
						sum = a[head]; 
						 }
				}
				else
				{
					head++;
					if(head>=n)
					{
						break;
					}
					tail = head;
					sum = a[head]; 
				}
			}
			else
			{
				tail++;
				sum += a[tail];
				if(sum<m&&tail == (n-1))
				 {
				 	break;
				 }
			}
		}
		if(f)
		 printf("YES\n");
		else
		 printf("NO\n"); 
		 
		
		
		
	}
}
