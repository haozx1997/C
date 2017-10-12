#include<stdio.h>
int main()
{
	int n,sum = 1,s = 0;
	char x;
	scanf("%d %c",&n,&x);
	for(int i = 1;;i++)
	{
		
		s = 2*i+1;
		sum+=2*s;
		if(sum>=n)
		 break;
	}
	sum-=(s*2);
	s-=2;

	for(int i = s;i>1;i-=2)
	 {
	 	for(int j = (s-i)/2;j>0;j--)
	 	 printf(" ");
	 	for(int j = 0;j<i;j++)
	 	 printf("%c",x);
	 	printf("\n");
	 }
	 for(int i = 1;i<=s;i+=2)
	 {
	 	for(int j = (s-i)/2;j>0;j--)
	 	 printf(" ");
	 	for(int j = 0;j<i;j++)
	 	 printf("%c",x);
	 	printf("\n");
	 }
	 printf("%d\n",n-sum);
	
	return 0 ;
}
