#include<stdio.h>
#include<string.h>

int main()
{
	char a[10010];
	char b[10010];
	gets(a);
	gets(b);
	int l1 = strlen(a);
	int l2 = strlen(b);
	
	for(int i = 0;i<l1;i++)
	{
		int f = 1;
		for(int j = 0;j<l2;j++)
		{
			if(a[i]==b[j])
			{
				f = 0;
				break;
			}
		}
		if(f) 
		{
			printf("%c",a[i]);
		}
	}
	printf("\n");

	
}
