#include<stdio.h>
int main()
{//�������2/1��3/2��5/4��8/8������ǰ10��֮��
	int  a=0,b=1,c=1,d=1,i=1;
	for(;i<11;i++)
	  {b=c-b;
	  c=b+c;
	  printf("%d ",c);
	  }
	  
}
