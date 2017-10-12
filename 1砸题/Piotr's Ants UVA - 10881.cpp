#include<stdio.h>
#include<string.h>
#include<algorithm>


using namespace std;

struct node
{
	int x;
	int i,d;
	bool operator < (const node& l)const 
	{
		return x<l.x;
	}
}a[20000];

int in[20000];

int main()
{
	int l,t;
	int T,n;
	int ca = 1;
	scanf("%d",&T);
	
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(in,0,sizeof(in));
		
		scanf("%d%d%d",&l,&t,&n);
		int x;
		char d[10];
		for(int i = 0;i < n;i++)
		{
			scanf("%d%s",&a[i].x,d);
			if(d[0] == 'L')
			{
				a[i].d = 1;
			}
			else
			{
				a[i].d = 2;
			}
			a[i].i = i;
		}
		sort(a,a+n);
		for(int i = 0;i < n;i++)
		{
			in[a[i].i] = i;
		}
		for(int i = 0;i < n;i++)
		{
			
			if(a[i].x<0||a[i].x>l)
			{
				continue;
			}
			if(a[i].d == 1)
			{
				a[i].x -= t;
			}
			else
			{
				a[i].x += t;
			}
		}
		sort(a,a+n);
		
		for(int i = 1;i < n;i++)
		{
			if(a[i].x == a[i-1].x)
			{
				a[i].d = a[i-1].d = 0;
			}
		}
		printf("Case #%d:\n",ca++);
		for(int i =0;i < n;i++)
		{
			
			if(a[in[i]].x<0||a[in[i]].x>l)
			{
				printf("Fell off\n");
				continue;
			}
			if(a[in[i]].d == 0)
			{
				printf("%d Turning\n",a[in[i]].x);
				continue;
			}
			if(a[in[i]].d == 1)
			{
				printf("%d L\n",a[in[i]].x);
				continue;
			}
			else
			{
				printf("%d R\n",a[in[i]].x);
				continue;
			}
			
		}
		puts("");
	}

/*

2
10 1 4
1 R
5 R
3 L
10 R
10 2 3
4 R
5 L
8 R

10 10 3
1 L
2 L
3 l

5 5 7
5 L
10 L
4 L
3 L
2 L
1 R
-1 R


5 5 6
10 L
4 L
3 L
2 L
1 R
-1 R

5 5 5

4 L
3 L
2 L
1 R
-1 R

5 0 5
5 L
4 L
3 L
2 L
1 R


5 1 5
5 L
4 L
3 L
2 L
1 R

5 2 5
5 L
4 L
3 L
2 L
1 R

5 3 5
5 L
4 L
3 L
2 L
1 R

5 4 5
5 L
4 L
3 L
2 L
1 R

5 5 5
5 L
4 L
3 L
2 L
1 R


6
5 0 5
1 R
2 L
3 L
4 L
5 L
Case #1:
1 R
2 L
3 L
4 L
5 L

5 1 5
1 R
2 L
3 L
4 L
5 L
Case #2:
1 L
2 Turning
2 Turning
3 L
4 L

5 2 5
1 R
2 L
3 L
4 L
5 L
Case #3:
0 L
1 L
2 L
3 Turning
3 Turning

5 3 5
1 R
2 L
3 L
4 L
5 L
Case #4:
Fell off
0 L
1 L
2 L
4 R

5 4 5
1 R
2 L
3 L
4 L
5 L
Case #5:
Fell off
Fell off
0 L
1 L
5 R

5 5 5
1 R
2 L
3 L
4 L
5 L
Case #6:
Fell off
Fell off
Fell off
0 L
Fell off


--------------------------------
Process exited after 3.609 seconds with return value 0
请按任意键继续. . .

*/



 return 0;
}


