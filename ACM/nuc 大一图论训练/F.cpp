#include<stdio.h>
int main()
{
	int y;
	while(scanf("%d",&y)!=EOF)
	{
		int n1,n2,n3,n4;
		while(y++)
		{
		 n1=y/1000;
		 n2=(y%1000)/100;
		 n3=(y%100)/10;
		 n4=y%10;
		 if(n1!=n2&&n1!=n3&&n1!=n4&&n2!=n3&&n2!=n4&&n3!=n4)
		  {printf("%d%d%d%d\n",n1,n2,n3,n4);break;}
		}

		
		
	}
}
