#include <stdio.h>
int main() 
{
    int n,a[10]={0};
    for(n=0;n<10;n++)
     a[n]=0;
    printf("����������ֱ�ո�\n"); 
   while(1)
   {
       scanf("%d",&n);
       a[n]++;
       if(getchar()=='\n')break;
   }
   for(n=0;n<10;n++)
       printf("%d: %d\n",n,a[n]);
   return 0;
}

