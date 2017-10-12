#include <stdio.h>
#include <stdlib.h>

void check(int *p) 
{ int i;
   printf("They are fail:");
   for(i=0;i<5;i++)
      if (p[i]<60) 
         printf("%d ",p[i]); 
   printf("\n");
} 

int main()
{ 
	int *p1,i; 
	p1=(int *)malloc(5*sizeof(int)); //开辟空间 
	for(i=0;i<5;i++) 
	{
		scanf("%d",p1+i); 
	}
	for(i=0;i<5;i++) 
	{
		printf("%d ",*(p1+i));    
	}
	check(p1); 
	//printf("\n%lld\n",p1);
	free(p1);//释放空间 
	for(i=0;i<5;i++) 
	{
		printf("%d",*(p1+i)); //再看一遍指针指的数 
	}
	return 0;
}

