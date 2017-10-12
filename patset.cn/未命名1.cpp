#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

 int gcd(int a,int b) 
 { 
 	return b == 0 ? a : gcd(b,a%b);
 } 

using namespace std;
int main()

{
	printf("%d\n",gcd(36,24));
	printf("Hello world!\n");
}
