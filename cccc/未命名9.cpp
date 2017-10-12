#include<stdio.h>
#include<string.h>
int main()
{
	char a[1010];
	int mid;
	int ans = 0;
	int max = 0;
	while(~scanf("%s",a))
	{
			
			for(int i = 0;i<strlen(a);i++)
			{
				ans = 0;
				if(a[i]==a[i+1])
				{
					
					int l=i,r=i+1;
					for(;;l--,r++)
					{
						
						if(l<0||r>=strlen(a)||a[l]!=a[r])
						{
							break;
						}
						if(a[l]==a[r])
						{
							ans+=2;
						}
						
					} 
				}
				else
				{
					ans = 1;
					int l=i-1,r=i+1;
					for(;;l--,r++)
					{
						
						if(l<0||r>=strlen(a)||a[l]!=a[r])
						{
							break;
						}
						if(a[l]==a[r])
						{
							ans+=2;
						}
					}
				}
				if(max<ans)
				{
					max = ans;
					mid = i;
				}
				
			}
			printf("%d\n",max);
			if(ans%2)
			{
				
				
				for(int i = (mid - max/2);i<(mid + max/2+1);i++)
				{
					printf("%c",a[i]);
					
				}
				printf("\n");
			}
			else
			{
				for(int i = (mid - max/2);i<(mid + max/2+2);i++)
				{
					printf("%c",a[i]);
					
				}
				printf("\n");
			}
			
	}

}
