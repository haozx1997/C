#include<stdio.h>
#include<string.h>
char biao[36]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char re(char c)
 {
 	if(c<60) return biao[c-'0'+25];
 	return biao[c-'A'];
 }
 
int main()
{
	char s[25];
	int i,f1,f2,len;
	while(scanf("%s",s)==1)
	{
		f1=1;f2=1;
		len=strlen(s);
		for(i=0;i<(len+1)/2;i++)
		  if(s[i]!=s[len-i-1]) f1=0;
		for(i=0;i<(len+1)/2;i++)
		  if(s[i]!=re(s[len-1-i])) f2=0;
		if(f1&&f2)printf("%s -- is a mirrored palindrome.\n\n",s);
		else
		{
			if(f1) printf("%s -- is a regular palindrome.\n\n",s);
		    if(f2) printf("%s -- is a mirrored string.\n\n",s);
		    if(f1==0&&f2==0) printf("%s -- is not a palindrome.\n\n",s);
		}
	}
	return 0;
}
