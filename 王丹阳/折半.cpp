/*
5 83 74 2 61 39 18 29 90 78 58 8 26 11 42 51 36 16 31 22
*/
#include <stdio.h>
int num[20]; 

void BubbleSort ()//冒泡 
{
	int i,j ,t;
	for(i=0;i<20-1;i++) 
    for(j=0;j<20-1-i;j++)
    if(num[j]<num[j+1]) 
      {
	  	t=num[j];
		num[j]=num[j+1];
		num[j+1]=t;
	  }
 } 
int main()
{
	int i, j, n, k=0, Found=0;
	
	printf("请输出20个整数：\n");
	for(i = 0;i<20;i++)
	 scanf("%d",&num[i]);  
	printf("请输出一个整数：\n");
	scanf("%d", &n);
	BubbleSort ();//冒泡 
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
