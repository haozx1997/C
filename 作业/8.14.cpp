#include<stdio.h>
long F(int n)
{
	long f;
	if(n==1||n==0)
	   f=1;
	else
	   f=F(n-1)+F(n-2);
	return f;
}
main()
{//n�׷Ʋ���������
	int n,i;
	printf("���볤��\n");
	scanf ("%d",&n);
	for(i=0;i<=n;i++)
	printf("%d ",F(i));
	return 0;
	
}
