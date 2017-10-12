#include <stdio.h>
int main()
{
	int s1,s2,s3,s4;
	char ch;
	s1=s2=s3=s4=0;
	printf ("please input a string:");
	for ( ;(ch=getchar())!='\n';)
	   if (ch>='a'&&ch<='z'||ch>='A'&&ch<='z')
	     s1++;
	 else
	    if (ch>='0'&&ch<='9')
	      s2++;
	    else
	        if (ch==' ')
	        s3++;
	        else
	         s4++;
	printf ("%d \n ",s1);
    printf ("%d ",s2);
	printf ("%d ",s3);
	printf ("%d ",s4);    
	return 0;    
}
