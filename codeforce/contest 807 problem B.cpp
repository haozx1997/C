#include<bits/stdc++.h>

using namespace std;
int p,x,y;
int check(int s)
{
	int i = (s/50)%475;
//	printf("s   %d\n",s);
	
	for(int j = 0; j < 25;j++)
	{
		i = (i*96 + 42)%475;
//		printf("%d%c",i," \n"[j == 24]);
		if(p == (26 + i))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	
	while(~scanf("%d%d%d",&p,&x,&y))
	{
		int ans = 0;
		int F = 0;
		if(x>=y)
		{
			int xx = x;
			while(xx>=y)
			{
				if(check(xx))
				{
					F = 1;
					break;
				}
				xx-=50;
			}
		}
		if(F)
		{
			printf("%d\n",ans);
			continue;
		}
		while(x<y)
		{
			x += 100;
			ans++;
		}
		for(int i = 0 ;;i++)
		{
			if(check(x))
			{
				break;
			}
			if((i%2) == 0)
			{
				ans++;
			}
			x+=50;
			
		}
		printf("%d\n",ans);
	}
	
	/*
	
	239 10880 9889
	26 7258 6123
	493 8000 8000
	101 6800 6500
	329 19913 19900
	
	*/



 return 0;
}


