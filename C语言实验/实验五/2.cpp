#include<stdio.h>
int main()
{//��һ���������磺 3 3���󣩶Խ���Ԫ��֮��
	int a[3][3],i,j;
	for(i=0;i<3;i++)
	 {
		for(j=0;j<3;j++)
		  {
		  	scanf("%d",&a[i][j]);
		  }
	 }
	printf("%d",(a[0][0])+(a[1][1])+(a[2][2]));
	return 0;
}
