/*
 3 ans                    6 预计用时       0毫秒 
 3 ans                    6     用时       0??
 4 ans                   24 ????       0??
 4 ans                   24     ??       0??
 5 ans                  120 ????       0??
 5 ans                  120     ??       0??
 6 ans                  720 ????       0??
 6 ans                  720     ??       0??
 7 ans                 5040 ????       0??
 7 ans                 5040     ??       1??
 8 ans                40320 ????       4??
 8 ans                40320     ??       5??
 9 ans               362880 ????      36??
 9 ans               362880     ??      36??
10 ans              3628800 ????     362??
10 ans              3628800     ??     356??
11 ans             39916800 ????    3991??
11 ans             39916800     ??    3884??
12 ans            479001600 ????   47900??
12 ans            479001600     ??   47518??
13 ans           6227020800 ????  622702??
13 ans           6227020800     ??  840151??
14 ans          87178291200 ???? 8717829??

*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[10];
	long long ans=0; 
	for(int i=0;i<10;i++)
	 a[i]=i;
	do
	{
		ans++;
//		for(int i=0;i<10;i++)
//	  printf("%d",a[i]);//必do while 
//	  printf("\n");

	}
	while(next_permutation(a, a + 10)) ;//顺序过 看7行 一定注意范围 
	printf("ans %lld\n",ans);
	for(int i=0;i<10;i++)
	 a[i]=9-i;
	do
	{
	
		for(int i=0;i<3;i++)
	  printf("%d",a[i]);//必do while 
	  printf("\n");

	}
	while(next_permutation(a, a + 3)) ;//顺序过 看7行 一定注意范围 
	
	
	printf("%d\n",ans);
	
	
	
		a[0]=3;a[1]=2;a[2]=1;
	do
	{
		for(int i=0;i<3;i++)
	  printf("%d",a[i]);//必do while 
	  printf("\n");
	}
	while(prev_permutation(a, a + 3)) ;//逆序过 看19行 
	
	
	 
}
