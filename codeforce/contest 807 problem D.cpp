#include<bits/stdc++.h>

using namespace std;

int n;
int sol[10];
int w[10];
int l[10];

int point(int j,int mint)
{
	if(mint == -1)
	{
		return 0;
	}
	int le = n/sol[j];
	if(le>=32)
	{
		return 3000/250*(250 - mint);
	}
	if(le>=16)
	{
		return 2500/250*(250 - mint);
	}
	if(le>=8)
	{
		return 2000/250*(250 - mint);
	}
	if(le>=4)
	{
		return 1500/250*(250 - mint);
	}
	if(le>=2)
	{
		return 1000/250*(250 - mint);
	}
	if(le>=1)
	{
		return 500/250*(250 - mint);
	}
	
	
}

int pointds(int ds,int mint)
{
	if(ds == 0)
		return 3000/250*(250 - mint);
	return 500/250*(250 - mint);
}


int main()
{
	while(~scanf("%d",&n))
	{
		int nn = n;
		memset(sol,0,sizeof(sol));
		scanf("%d%d%d%d%d",&w[0],&w[1],&w[2],&w[3],&w[4]);
		scanf("%d%d%d%d%d",&l[0],&l[1],&l[2],&l[3],&l[4]);
		for(int j = 0;j < 5;j++)
		{
			if(w[j] != -1)
			{
				sol[j]++;
			}
			if(l[j] != -1)
			{
				sol[j]++;
			}
		}
		for(int i = 2;i<n;i++)
		{
			for(int j = 0;j < 5;j++)
			{
				int wtf;
				scanf("%d",&wtf);
				if(wtf != -1)
				{
					sol[j]++;
				}
				
			}
		}
		int pw = 0,pl = 0;
		for(int j = 0;j < 5;j++)
		{
			if(w[j] == -1)
			{
				if(l[j] == -1)
				{
				//	puts("0");
					continue;
				}
				else
				{//puts("01");
					pl += point(j,l[j]);
				}
			}
			else
			{
				
				if(l[j] == -1||w[j]<l[j])
				{//puts("02");
					if(w[j]<l[j])
					{
						pw += pointds(0,w[j]);
						pl += pointds(0,l[j]);
					}
					else
					{
						pw += pointds(0,w[j]);
					}
				}
				else
				{//puts("03");
					pl += pointds(1,l[j]);
					pw += pointds(1,w[j]);
				}
			}
		}
	//	printf("%d %d\n",pl,pw);
		if(pw>pl)
		{
	//		printf("WTF\n");
		}
		else
		{
			printf("-1\n");
			continue;
		}
	
		int i;
		for(i = 0;i < 150*40;i++,n++)
		{
			pl = 0; pw = 0;
			for(int j = 0;j < 5;j++)
			{
				pl += point(j,l[j]);
				pw += point(j,w[j]);
				
			}	
			if(pw>pl)
			{
				break;
			}
			for(int j = 0;j < 5;j++)
			{
				if(w[j] == -1)
				{
					continue;
				}
				if(l[j] == -1)
				{
					
				}
				else if(w[j]<l[j])
				{
					
				}
				else if(w[j]>=l[j])
				{
					sol[j]++;
				}
			}
		//	printf("%d %d\n",pl,pw);
		}	
		if(i>(nn*32))
		{
			i = -1;
		}
		printf("%d\n",i);
		
				
	}
	

 return 0;
}


