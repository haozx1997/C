#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;

set<int> b;
int stp[300];//set to people

void see()
{
	if(b.empty()) printf("ø’\n");
	set<int>::iterator it; 
        for(it=b.begin();it!=b.end();it++) 
        {
        	
        	printf("                    »À %d ∫≈ %d\n",stp[*it],*it);
        	
		}
}


void add()
{
	int k,p;
	scanf("%d%d",&k,&p);
	stp[p] = k;
	b.insert(p);		
}
void min()
{
	if(b.empty())
	{
		printf("0\n");
		return;
	}

	int k = stp[*b.begin()];
	printf("%d\n",k);
	b.erase(b.begin());
	
}


void max()
{
	if(b.empty())
	{
		printf("0\n");
		return;
	}
	set<int>::iterator it;
	it = b.end();
	it--;
	int k = stp[*it];
	printf("%d\n",k);
	b.erase(it);
}

int main()
{
	b.clear();
	memset(stp,0,sizeof(stp));
	int c;
	
	
	while(scanf("%d",&c),c)
	{
		switch(c)
		{
			case 0:  ;
			case 1: add();
			
			see();
			
			 break;
			case 2: max();
			see();
			break;
			case 3: min();
			see();
			break;
			
		}
	}
	printf("0\n");
	
	return 0 ;
}
