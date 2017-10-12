
#include<stdio.h>
int main()
{
    int a,t,n;
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        n=1;
         while(a>n)
        {
              a-=n;
              n++;
        }
        
        printf("%d\n",a);
    }
}
