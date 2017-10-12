#include<stdio.h>
long fac(int n)//n!
{
	long s=0;
	if(n==1||n==0) s=1;
	else s=n*fac(n-1);
	return (s);
}
long xgm(int n)//¶≤
{
	long s=0;
	for(;n>0;n--)
	 s=s+fac(n);
	return (s);
}
int main()//¶≤n!
{
	int n,s;
	printf(" ‰»În£∫");
	scanf("%d",&n);
	printf("¶≤n!=%d",xgm(n));
	return 0;
	
}
