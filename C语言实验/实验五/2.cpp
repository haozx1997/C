#include<stdio.h>
int main()
{//求一个方阵（例如： 3 3方阵）对角线元素之和
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
