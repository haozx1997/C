#include <stdio.h>
int main()
{
	int cases=1;
	int p,e,i,d,n;
	while(scanf("%d%d%d%d",&p,&e,&i,&d)!=EOF)
		{
			if(p==-1&&e==-1&&i==-1&&d==-1)
			break;
			printf("Case %d: the next triple peak occurs in ",cases++);
			n=(5544*p+14421*e+1288*i-d+23*28*33)%(23*28*33);
			printf("%d days.\n",n==0?21252:n);
		}
		return 0;
} 
