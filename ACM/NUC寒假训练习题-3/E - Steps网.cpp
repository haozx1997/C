#include <stdio.h>


int main()
{
    int m,n;
    int i,j;
    while (scanf("%d%d",&m,&n)!=EOF) {
        int sum=0,flag=0;
        if(n-m==0)
        {
          printf("0\n");
            continue;
        }
        for(i=1;;i++)
        {
            for(j=0;j<2;j++)
            {
                sum+=i;
               if((n-m)<=sum)
               
                   flag=1;
                   break;
               }
            }
            if(flag==1)
                break;
        }
        if(j==1)
            printf("%d\n",2*i);
        else
            printf("%d\n",2*i-1);
    }
    return 0;
}
