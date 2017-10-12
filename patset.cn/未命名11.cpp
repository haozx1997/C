#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int main()

{
	int n;
	scanf("%d",&n);
	n +=2;
	while(n>7)
	 n -= 7;
	printf("%d\n",n); 
}
