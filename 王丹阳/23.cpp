#include<stdio.h>
#include<string.h>
int check(char *s)
{
	
	if(s[0]>='0'&&s[0]<='9')
		return	0;
    for(int i = 0;i<strlen(s);i++)
	{
		if(!((s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z')
					||s[0]=='_')  )
			return	0;		
		
	}
	return	1;
	
		
}

int main()
{
	char s[100];
	scanf("%s",s);
	printf("%d",check(s));
}
