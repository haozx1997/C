#include<stdio.h>
main()
{ //��һ��4*4�����жԽ���Ԫ��֮��//
	int a[4][4],i,j,s;

	for(i=0;i<4;i++)
	   for(j=0;j<4;j++)
	   scanf("%d",&a[i][j]);
	
	for(s=0,i=0,j=0;i<4;i++,j++)
	    s=s+a[i][j];
	printf("���Խ���=%d\n",s);
	for(s=0,i=3,j=0;j<4;i--,j++)
	    s=s+a[i][j];
	printf("�ζԽ���=%d",s);
	
	return 0;
 } 
