#include <stdio.h>
#include <math.h>
main()
{
	float a,c;
	char b;
	scanf("%.4f%c%.4f",a,b,c);
	switch(b)
	{case'+':printf("%.4f\n",a+c);break; 
	 case'-':printf("%.4f\n",a-c);break; 
	 case'*':printf("%.4f\n",a*c);break; 
	 case'/':printf("%.4f\n",a/c);break; 
	 default:printf("error\n");
	 } 
 return 0;
}
