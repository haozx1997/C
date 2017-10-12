#include<stdio.h>
#include<algorithm>
using namespace std;
int max(int x,int y)
{
	return x>y?y:x;
}
int main()
{
	printf("%d\n",max(1,2));
	return 0;
}


