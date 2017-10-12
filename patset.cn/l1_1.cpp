#include<stdio.h>
#include<string.h>
int main()

{
	char num[100];
	scanf("%s",num);
	int ans = 0;
	double anss = 0;
	int len = strlen(num);
	int i = 0;
	for(;i<len;i++)
	{
		
		if(num[i] == '2')
		{
			ans++;
		}
	}

	if(num[0] == '-')
	 {
	 	len--;
	 	anss = (double)ans/len;
	 	anss *=1.5;
	 }
	 else
	 anss = (double)ans/len;
	if(!((num[i - 1]-'0')%2)) 
	 {
	 	anss *=2;
	 }
	printf("%.2f",anss*100);
	printf("%c\n",'%');
	
}
