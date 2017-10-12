#include<stdio.h>
#include<string.h>
int main()
{
	char a[128],b[128];
	int i,j,d;
	gets(a);
	d=strlen(a);
	for(i=0,j=0;i<d;i++)
	    {
		    if(a[i]==' ')
		      {
		    	continue;
			  }
	        b[j]=a[i];
	        j++;
			}
	printf("%s",b);
	return 0;
}
