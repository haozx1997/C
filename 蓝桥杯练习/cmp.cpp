#include<bits/stdc++.h>

using namespace std;

char a[10010][10];

bool cmp(char s1[],char s2[])
{
	return strcmp(s1,s2);
}
string aa[10010];
int main()
{

	int n;//输入列表大小
	scanf("%d",&n);
	char num[10];
	
	for(int i =0 ; i < n;i++)
	{
		scanf("%s",&a[i]);
	
	//	aa[i] = num;
	 } 
	sort(a,a+n);
	for(int i =n-1 ; i >=0 ;i--)
	{
		cout<<aa[i];
	 }
/*
4
9 50 2 3


*/

 return 0;
}


