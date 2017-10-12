#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int sum=0,n,m,i,j,c,F=0;
		scanf("%d%d",&n,&m);
		c=(n-m)>0?n-m:m-n;
		if(!c)
        {
          printf("0\n");
            continue;
        }
		for(i=1;;i++)
		 {
		 	for(j=0;j<2;j++)
            {
                sum+=i;
               if(c<=sum)
               {
                   F=1;
                   break;
               }
            }
            if(F)
                break;
		 }
		 if(j==1)
            printf("%d\n",2*i);
        else
            printf("%d\n",2*i-1);
		
	}
	return 0;
}
