#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	char m[20]={'1','0','X','9','8','7','6','5','4','3','2'};
	int q[20]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int f=1;
	while(T--)
	{
		char a[20];
		char b[20];
		char c;
		int z=0;
		int ans= 0;
		scanf("%s",a);
		int ff=1;
		for(int i=0;i<17;i++)
		{
			ans+=((a[i]-'0')*q[i]);
			if(a[i]>'9'||a[i]<'0')
			{
				f=0;
				ff=0;
				printf("%s\n",a);
			}
		}
		if(!ff)
		{
			continue;
		}
		z=ans%11;
		if(a[17]!=m[z])
		{
			f=0;
			printf("%s\n",a);
		}
		
	}
	if(f)
	{
		printf("All passed\n");
	}
}
