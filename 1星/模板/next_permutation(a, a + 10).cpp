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
//	  printf("%d",a[i]);//��do while 
//	  printf("\n");

	}
	while(next_permutation(a, a + 10)) ;//˳��� ��7�� һ��ע�ⷶΧ 
	printf("%d",ans);
	
	
	
		a[0]=3;a[1]=2;a[2]=1;
	do
	{
		for(int i=0;i<3;i++)
	  printf("%d",a[i]);//��do while 
	  printf("\n");
	}
	while(prev_permutation(a, a + 3)) ;//����� ��19�� 
	 
}
