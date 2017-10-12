#include <stdio.h>
int main()
{
int i, j, n, k=0, Found=0;
int num[20] = {90,83,78,74,61,58,51,42,39,36,31,29,26,22,18,16,11,8,5,2};  
printf("???????:\n");
scanf("%d", &n);
    i = (int)20/2;   
j = (int)20/2;    
while(k<2)
{
          i = (int)i/2;
                if(i == 0) k++;     
          if(n<num[j])
                  j = j + (i + 1);
          else if(n>num[j])
                  j = j - (i + 1);
          else
          {
                  Found = 1;
                  break;         
          }
}
if(Found)
          printf("该数是数组中第%d个元素的值\n", j);
else
          printf("Not Found\n");
return 0;
}
