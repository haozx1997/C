#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
	long long a[10];
	scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	printf("%lld->%lld->%lld",a[0],a[1],a[2]);
}
