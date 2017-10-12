#include<stdio.h>
#include<math.h>
int main()
{	
	float pi,sum = 0;
	int i,n;
	scanf("%d",&n);
	for(i = 1;i<=n;i++)
	{
		sum += (float)1/i/i;	//把1强制转换为float才能除法商为小数 
	}	
	pi = sqrt(6*sum);//sqrt是开方函数 
	printf("n=%d pi=%f\n",n,pi);
}
