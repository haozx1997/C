#include<string.h>
#include<stdio.h>


void prin(int aa)
{
	char a[6]={"00000"};
	a[4] = '0'+aa%10;aa/=10;
	a[3] = '0'+aa%10;aa/=10;
	a[2] = '0'+aa%10;aa/=10;
	a[1] = '0'+aa%10;aa/=10;
	a[0] = '0'+aa%10;
	printf("%s",a);
}


int main()
{
	prin(123);
}
