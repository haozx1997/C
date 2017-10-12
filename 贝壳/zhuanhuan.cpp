#include <stdio.h>
main ( )
{
	char ch1,ch2;
	while ((ch1=getchar( ))!='\n')
	{
		if (ch1>=65&&ch1<=91)
		   ch2 = ch1+32;
		   printf ("%c", ch2);
		if (ch1>=97&&ch1<=123)
		   ch2 = ch1-32;
		   printf ("%c", ch2);
	}
}
