#include<bits/stdc++.h>

using namespace std;
char s[10010000];
char ss[10010000];


int main()
{
	int  t1= clock();
	
	int c = 10000000;
	for(int i =0;i<c;i++)
	{
		s[i] = '1';
	}
	int  t2= clock();
	
	s[c] = 0;
	
	strcpy(ss,s);
	int  t3= clock();
	int j = 0;
	for(int i =0;i<c;i++)
	{
		ss[i] = s[j++];
	}
	
	int  t4= clock();
	printf("%d\n%d\n%d\n",t2-t1,t3-t2,t4-t3);
	getchar();
	printf("%d\n",clock()-t3);
	



 return 0;
}


