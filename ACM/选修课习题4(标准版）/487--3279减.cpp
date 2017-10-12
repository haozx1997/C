#include<stdio.h>
#include<string.h>

char num[26]={'2','2','2' , '3','3' , '3','4','4','4','5' ,'5' ,'5' , '6','6' ,'6','7' ,'0' ,'7' ,'7' ,'8' ,'8' ,'8' ,'9' , '9', '9','0' };
int main()
{
	int T;
	scanf("%d",&T);
	//getchar();
	while(T--)
	{
		char s[10];
			scanf("%s",s);
			printf(" %s\n",s);
		for(int i = 0;i<strlen(s);i++)
		 	{
		 		printf("%c",s[i]);
				if(s[i]>='A'&&s[i]<='Z')
		 	 	 	 {
		 	 	 	 	printf("%c %c\n",s[i],num[s[i]-'A']);
		 	 	 	 	s[i] = num[s[i]-'A'];
		 	 	 	 	printf("%c %c\n",s[i],num[s[i]-'A']);
						}
			} 	 	
		 
		  
		 
	}
 } 
