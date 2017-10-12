#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int t;
int nudn[30010];//n下的数量 

int nup[30010];//n的up主 



void m()
{
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	
	nud[n1] = 1+nud[n2];
	
}


int main()
{
	
	while(~scanf("%d",&t))
	{
		for(int i = 0;i < 30009;i++)
		{
			nudn[i] = 0;
			nup[i] = i;
		}

		char mc[5];
		scanf("%s",mc);
		switch(mc[0])
		{
			case'M':
				m();
				break;
			case'C';
				c();
				break;	
		}
	}
}
