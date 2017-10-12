#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;

set<int> b;
int stp[1000];//set to people

int pts[1000][1000];
int ptsn[1000];

void see()
{
	if(b.empty()) printf("¿Õ\n");
	set<int>::iterator it; 
        for(it=b.begin();it!=b.end();it++) 
        {
        	
        	printf("                    ÈË %d ºÅ %d\n",stp[*it],*it);
        	
		}
}

void del(int kk)
{
	//printf("É¾³ý %d\n",kk);
	for(int i = 0;i < ptsn[kk];i++)
	{
		b.erase(pts[kk][i]);
	}
	ptsn[kk] = 0;
}


void add()
{
	int k,p;
	scanf("%d%d",&k,&p);
	pts[k][ptsn[k]++] = p;
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
	del(k);
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
	del(k);
}

int main()
{
	b.clear();
	memset(stp,0,sizeof(stp));
	memset(pts,0,sizeof(pts));
	memset(ptsn,0,sizeof(ptsn));
	
	int c;
	
	
	while(scanf("%d",&c),c)
	{
		switch(c)
		{
			case 0:  ;
			case 1: 
				add();
				//see();
			 	break;
			case 2:
				max();
				//see();
				break;
			case 3: 
				min();
				//see();
				break;
			
		}
	}
	printf("0\n");
	
	return 0 ;
}

 
