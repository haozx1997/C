#include<stdio.h>

using namespace std;
/*
10
3 4
2 5 2
3 6 3 1

4 6
4 4 4 5
4 4 4 4 4 6

4 4 
4 4 4 3
4 4 4 1

3 5
4 4 4 
4 4 4 4 5

3 4 
4 4 4
4 4 4 1


*/
int main()
{
	int T;
	scanf("%d",&T);
	for(int I = 0; I < T;I++)
	{
		int n,m;
		int a[100100],b[100100];
		
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n;i++)
		{
			scanf("%d",&a[i]);
			
		}
		for(int i = 0; i < m;i++)
		{
			scanf("%d",&b[i]);
			
		}
		int pa = 0,pb = 0;
		printf("Case %d: ",I+1);
		while(pa<n||pb<m)
		{
		//	printf("	%d %d \n",pa,pb);
			if(pa == n)
			{
				while(pb<m)
				{
					printf("%d",b[pb++]);
				}
				break;
			}
			else if( pb == m)
			{
				while(pa<n)
				{
					printf("%d",a[pa++]);
				}
				break;
			}
			else if(a[pa]>b[pb])
			{
				printf("%d",a[pa++]);
				
			}
			else if(a[pa]<b[pb])
			{
				printf("%d",b[pb++]);
			}
			if(a[pa] == b[pb])
			{
				int pao = pa,pad;
				int ds = 0;
				int pbo = pb,pbd;
				while(1)
				{
					if(a[pa] == b[pb])
					{
						printf("%d",a[pa]);
						ds++;
					}
					else
					{
						if(a[pa] > b[pb])
						{
							printf("%d",a[pa++]);
							pb = pbo;
							break;
						}
						else
						{
							printf("%d",b[pb++]);
							pa = pao;
							break;
						}
					}
					pa++;pb++;
					if(pa == n&&pb == m)
					{
						for(int i =0 ;i < ds;i++)
						{
							printf("%d",a[pa]);
						}
					}
					else if(pa == n&&pb != m)
					{
						int i;
						for(i = pb;i<m;i++)
						{
							if(b[i]!=b[pbo])
							{
								break;
							}
						}
						if(i == m)
						{
							i = m-1;
						}
						if(b[i]>=b[pbo])
						{
							for(int j = pb;j<=i;j++)
							{
								printf("%d",b[j]);
							}
							pa = pao;
							pb = i+1;
							
						}
						else
						{
							for(int j = pbo;j<=i;j++)
							{
								printf("%d",b[j]);
							}
							pb = i+1;
						}
						break;
					}
					else if(pa != n&&pb == m)
					{
						int i;
						for(i = pa;i<n;i++)
						{
							if(a[i]!=a[pa])
							{
								break;
							}
						}
						if(i == n)
						{
							i = n-1;
						}
						if(a[i]>=a[pao])
						{
							for(int j = pa;j<=i;j++)
							{
								printf("%d",b[j]);
							}
							pb = pbo;
							pa = i+1;
							
						}
						else
						{
							for(int j = pao;j<=i;j++)
							{
								printf("%d",a[j]);
							}
							pa = i+1;
						}
						break;
					}
					
				}
				
				
				
			}
			
		}
		printf("\n");
	}




 return 0;
}


