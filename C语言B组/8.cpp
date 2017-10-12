#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		while(n)
		{
			int i = sqrt(n);
			printf("%d ",i);
			n -= i*i;
			printf("%d\n",n);
		}
	}
}


