#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<map>
#include<iostream>
#include<math.h>
#include<string>
const double eps=1e-8;
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)
using namespace std;

void print(double x)
{
	// printf("%.2f",x);
	if(x<0.5)
	{
		printf(" noob\n");
		return ;
	}
	if((x>=0.5&&x<0.8)||zero(x-0.5))
	{
		printf(" random\n");
		return ;
	}
	if(x>=0.8&&x<0.9||zero(x-0.8))
	{
		printf(" average\n");
		return ;
	}
	if(x>=0.9&&x<0.99||zero(x-0.9))
	{
		printf(" hardcore\n");
		return ;
	}
	printf(" pro\n");
	
}


int main()
{
	int nnn;
	while(~scanf("%d",&nnn))
	{
		std::map<string,int> ma;
		std::map<std::string,int>::iterator it;
		int sor[1010];
		for(int i = 1;i <= nnn;i++)
		{
			char name[20];
			int sco;
			scanf("%s%d",name,&sco);
		
			string ss(name);
//			cout<<ss<<endl;
			it = ma.find(ss);
			
			if(it==ma.end()||i==0)
			{
				ma.insert(pair<string,int>(ss,sco));
			}
			else 
			{
		//printf(">%d\n",sco>(it->second));
				if(sco>(it->second))
				{
					it->second = sco;
//					ma.erase(it);
//					ma.insert(pair<string,int>(ss,sco));
				 } 
			}
//			printf("~~%d\n",nnn);
			
		}
//		printf("!!%d\n",ma.size());
//		for(it = ma.begin();it!=ma.end();it++)
//		{
//			cout<<it->first<<"  " <<it->second <<endl;
//			//printf("%s %d\n",it->first,it->second);
//		}
//		
		int sori = 1;
		for(it = ma.begin();it!=ma.end();it++)
		{
			sor[sori++] = it->second;
			
		}
		sori--;
		sort(sor+1,sor+sori+1);
		double cy[1010];
		for(int i = 1;i <= sori;i++)
		{
			cy[sor[i]] = (double)i/sori;
		}
		printf("%d\n",ma.size());
		for(it = ma.begin();it!=ma.end();it++)
		{
			cout<<it->first;
			print(cy[it->second]);
		}
	}
}
