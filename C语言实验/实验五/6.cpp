#include <stdio.h>
main ( )
{//�Ӽ�������һ���ַ�������Сд��ĸȫ��ת���ɴ�д��ĸ
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

