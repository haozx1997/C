#include<bits/stdc++.h>

using namespace std;

int a[700][700];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		
		int h,w;
		if(n == 1)
		{
			printf("1 1\n1 1 \n");
			continue;
		}
		
//		if(n == 2)
//		{
//			printf("1 3\n");
//			printf("1 1 \n");
//			printf("1 2 1 3 \n");
//			
//			
//			continue;
//		}
//		
		
		h = (n+1)/2;
		int sum = (1+n)*n/2;
		w = sum / h;
		printf("%d %d\n",h,w);
		int ou = 0;
		ou = (w/2)+1;
		
		if((n%4) == 1)
		{
			for(int i = 1;i<=n;i++)
			{
				if(i%2)//奇数
				{
					int x,y;
					x = 1;y = (i+1)/2;
					printf("%d %d ",x,y);
					
					a[x][y] = i;
					
					int tu = 0;
					for(int ii = 1;ii<i;ii++)
					{
						if(ii>(i/2))
						{
							y--;
						}
						else
						{
							x++;
						}
						printf("%d %d ",x,y);
						a[x][y] = i;
					}
					printf("\n");
				 } 
				else
				{
					int d = i/2;
					if(d%2)//2 6 10
					{
						printf("%d %d %d %d ",1,d+ou-1+1,1,d+2+ou-1);
						a[1][d+ou-1+1] = i;
						a[1][d+1+ou-1+1] = i;
						
						for(int ii = 1;ii < d;ii++)
						{
							printf("%d %d %d %d ",ii+1,d+ou-1+1,ii+1,d+2+ou-1);
							a[ii+1][d+ou-1+1] = i;
							a[ii+1][d+ou-1+2] = i;
						
						}
						printf("\n");
					}
					else
					{
						printf("%d %d %d %d ",d,1+ou-1+1,d+1,1+ou-1+1);
						a[d][1+ou-1+1] = i;
						a[d+1][1+ou-1+1] = i;
						for(int ii = 1;ii < d;ii++)
						{
							printf("%d %d %d %d ",d,ii+1+ou-1+1,d+1,ii+1+ou+1-1);
							a[d][ii+1+ou-1+1] = i;
							a[d+1][ii+1+ou-1+1] = i;
						
						}
						printf("\n");	
					}
					
					
				 } 
				
				
				
			}
		
		
		}
		else if((n%4) == 2)
		{
			for(int i = 1;i<=n;i++)
			{
				if(i%2)//奇数
				{
					int x,y;
					x = 1;y = (i+1)/2;
					printf("%d %d ",x,y);
					
					a[x][y] = i;
					
					int tu = 0;
					for(int ii = 1;ii<i;ii++)
					{
						if(ii>(i/2))
						{
							y--;
						}
						else
						{
							x++;
						}
						printf("%d %d ",x,y);
						a[x][y] = i;
					}
					printf("\n");
				 } 
				else
				{
					int d = i/2;
					if(d%2)//2 6 10
					{
						printf("%d %d %d %d ",1,d+ou-1-1+1,1,d-1+2+ou-1);
						a[1][d+ou-1+1-1] = i;
						a[1][d+1+ou-1+1-1] = i;
						
						for(int ii = 1;ii < d;ii++)
						{
							printf("%d %d %d %d ",ii+1,d+ou-1+1-1,ii+1,d+2+ou-1-1);
							a[ii+1][d+ou-1+1-1] = i;
							a[ii+1][d+ou-1+2-1] = i;
						
						}
						printf("\n");
					}
					else
					{
						printf("%d %d %d %d ",d,1+ou-1+1-1,d+1,1+ou-1+1-1);
						a[d][1+ou-1+1-1] = i;
						a[d+1][1+ou-1+1-1] = i;
						for(int ii = 1;ii < d;ii++)
						{
							printf("%d %d %d %d ",d,ii+1+ou-1+1-1,d+1,ii+1+ou+1-1-1);
							a[d][ii+1+ou-1+1-1] = i;
							a[d+1][ii+1+ou-1+1-1] = i;
						
						}
						printf("\n");	
					}
					
					
				 } 
				
				
				
			}
		}
		else if((n%4) == 3)
		{
			for(int i = 1;i<=n;i++)
			{
				if(i%2)//奇数
				{
					int x,y;
					x = 1;y = (i+1)/2;
					printf("%d %d ",x,y);
					
					a[x][y] = i;
					
					int tu = 0;
					for(int ii = 1;ii<i;ii++)
					{
						if(ii>(i/2))
						{
							y--;
						}
						else
						{
							x++;
						}
						printf("%d %d ",x,y);
						a[x][y] = i;
					}
					printf("\n");
				 } 
				else
				{
					int st = (n+1)/2;
					int d = i/2;
					if(d%2)
					{
						printf("%d %d %d %d ",d,st+1,d+1,st+1);
						a[d][st+1] = i;
						a[d+1][st+1] = i;
						
						for(int ii = 1;ii<d;ii++)
						{
							printf("%d %d %d %d ",d,st+1+ii,d+1,st+1+ii);
							a[d][st+1+ii] = i;
							a[d+1][st+1+ii] = i;
						
						}
					}
					else
					{
						int hou = d;
						printf("%d %d %d %d ",1,st+d,1,st+d+1);
						a[1][st+d] = i;
						a[1][st+d+1] = i;
						for(int ii = 1;ii<d;ii++)
						{
							printf("%d %d %d %d ",1+ii,st+d,1+ii,st+d+1);
							a[1+ii][st+d] = i;
							a[1+ii][st+d+1] = i;
						}
						
					
						
					}
						printf("\n");
				 } 
				
				
				
			}
				
		}
		
		else if((n%4) == 0)
		{
			for(int i = 1;i<=n;i++)
			{
				if(i%2)//奇数
				{
					int x,y;
					x = 1;y = (i+1)/2;
					printf("%d %d ",x,y);
					
					a[x][y] = i;
					
					int tu = 0;
					for(int ii = 1;ii<i;ii++)
					{
						if(ii>(i/2))
						{
							y--;
						}
						else
						{
							x++;
						}
						printf("%d %d ",x,y);
						a[x][y] = i;
					}
					printf("\n");
				 } 
				else
				{
					int st = (n+1)/2;
					int d = i/2;
					if(d%2)
					{
						printf("%d %d %d %d ",d,st+1,d+1,st+1);
						a[d][st+1] = i;
						a[d+1][st+1] = i;
						
						for(int ii = 1;ii<d;ii++)
						{
							printf("%d %d %d %d ",d,st+1+ii,d+1,st+1+ii);
							a[d][st+1+ii] = i;
							a[d+1][st+1+ii] = i;
						
						}
					}
					else
					{
						int hou = d;
						printf("%d %d %d %d ",1,st+d,1,st+d+1);
						a[1][st+d] = i;
						a[1][st+d+1] = i;
						for(int ii = 1;ii<d;ii++)
						{
							printf("%d %d %d %d ",1+ii,st+d,1+ii,st+d+1);
							a[1+ii][st+d] = i;
							a[1+ii][st+d+1] = i;
						}
						
						
						
					}
					printf("\n");
				 } 
				
				
				
			}
			
		}
		
		
//		for(int i = 1;i<=h+1;i++)
//		{
//			for(int j = 1;j<=w+1;j++)
//			{
//				printf("%3d",a[i][j]);
//			}
//			printf("\n");
//		}
//		
	}
	



 return 0;
}


