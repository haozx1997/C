#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;

struct FFF
{
	int k;
	int p;
};


deque <FFF> d;

void see()
{
	if(d.empty()) printf("空\n");
	deque<FFF>::iterator it; 
        for(it=d.begin();it!=d.end();it++) 
        {
        	FFF f = *it;
        	printf("                    人 %d 号 %d\n",f.k,f.p);
        	
		}
}

void add()
{
	FFF ff;
	int kk,pp;
	scanf("%d%d",&kk,&pp);
	ff.k = kk;
	ff.p = pp;
	if(d.empty())
	 {
	 	d.push_back(ff);
	 }
	else
	{
		FFF beg = d.front();
		if(d.front().p>ff.p)
		{
		//	printf("入头 %d %d\n",beg.p,ff.p);
			d.push_front(ff);
			return;
		}
		beg = d.back();
		if(d.back().p<ff.p)
		{
		//	printf("入头 %d %d\n",beg.p,ff.p);
			d.push_back(ff);
			return;
		}
		
		 deque<FFF>:: iterator it;
        for(it=d.begin();it!=d.end();it++) 
        {
        	FFF t = *it;
        //	printf("!%d %d\n",ff.p,t.p);
        	if(ff.p<t.p)
        	{
        //		printf("213\n");
        		d.insert(it,1,ff);
        		return;
			}
			
		}
	}
	 
}


void max()
{
	if(d.empty())
	{
		printf("0\n");
		return;
	}
	
	printf("%d!\n",d.back().k);
	d.pop_back();
	
}
void min()
{
	if(d.empty())
	{
		printf("0\n");
		return;
	}
	
	printf("%d!\n",d.front().k);
	d.pop_front();
	
}




int main()
{
	d.clear();
	int c;
	while(scanf("%d",&c),c)
	{
		switch(c)
		{
			case 0:  ;
			case 1: 
				add();
			//	see();
			 	break;
			case 2:
				max();
			//	see();
				break;
			case 3: 
				min();
			//	see();
				break;
			
		}
	}
	
	
	return 0 ;
}







