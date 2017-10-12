#include<bits/stdc++.h>

using namespace std;

int n,m,A,B,C; 
unsigned x = A, y = B, z = C;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  printf("%10d %10d %10d %10d\n",x,y,z,t);
  return z;
}

unsigned a[1000100];
int b[200];
int main()
{
	int TT = 1;
	while(~scanf("%d%d%u%u%u",&n,&m,&A,&B,&C))
	{
		x = A, y = B, z = C;
		for(int i = 0;i<n;i++)
		{
			a[i] = rng61();
		}
		sort(a,a+n);
		for(int i = 0;i < m;i++ )
		{
			scanf("%d",&b[i]);
		//	printf("%u\n",a[b[i]]);
			
			
		}
		printf("Case #%d:",TT++);
		for(int i = 0;i < m;i++ )
		{
			
			printf(" %u",a[b[i]]);
			
			
		}
		puts("");
		
		
	}




 return 0;
}


