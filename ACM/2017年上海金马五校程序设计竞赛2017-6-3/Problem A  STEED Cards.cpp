#include<bits/stdc++.h>

using namespace std;

int main()
{
	char s[] = "DEEST";
	char ss[100][10];
	int n = 0;
	do
	{
		n++;
		strcpy(ss[n],s);
		if(n>60)
		{
			break;
		}
	}
	while(next_permutation(s, s + 5)) ;
	int a;
	while(~scanf("%d",&a))
	{
		printf("%s\n",ss[a]);
	}



 return 0;
}


