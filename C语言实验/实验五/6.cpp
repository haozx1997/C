#include <stdio.h>
main ( )
{//从键盘输入一个字符串，将小写字母全部转换成大写字母
	char ch1,ch2;
	while ((ch1=getchar( ))!='\n')
	{
		
		if (ch1>=97&&ch1<=123)
		   {
		   ch2 = ch1-32;
		   printf ("%c", ch2);
	       }
	    else 
	       printf ("%c", ch1);
	}
	return 0;
}

