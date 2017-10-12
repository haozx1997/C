#include<stdio.h>
#include<algorithm>
#include    <string.h>  
#include    <string>  
#include    <vector>
#include    <stdlib.h>  
#include    <math.h> 
#include<map> 
#define ll long long
using namespace std;

map <string,vector<int> > m1;
map <string,vector<int> >::iterator it;

int nton[100010];//name to num
int wtf(string qns)
{
	int ntonn = 0;
	it = m1.find(qns);
	if(it != m1.end())
	{
		vector<int> v111(it->second);
//		printf("wtf v.size %d\n",v111.size());
		vector <int>::iterator vit;
		for(vit = v111.begin();vit!=v111.end();vit++)
		{
			
			nton[ntonn++] = (*vit);
		}
		return ntonn;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n,qn;
	while(~scanf("%d%d",&n,&qn))
	{
		char name_c[10];
		
   		m1.clear();
   		
		for(int i = 0;i<n;i++)
		{
			scanf("%s",name_c);
			string name_s(name_c);
			it = m1.find(name_s);
			if(it!=m1.end())
			{
//				printf("yes\n");
				vector<int> v1(it->second);
				v1.push_back(i);
				m1.erase(name_s);
//				printf("v1.size%d\n",v1.size());
				m1.insert ( pair <string,vector<int> > 
				 ( name_s , v1) );
			}
			else
			{
//				printf("no\n");
				vector<int> v11;
				v11.clear();
				v11.push_back(i);
				m1.insert ( pair <string,vector<int> > 
				 ( name_s , v11) );
			}
			
		}
//			it = m1.find("Chen");
//	if(it != m1.end())
//	{
//		vector<int> v111(it->second);
//		printf("chenwtf v.size %d\n",v111.size());
//		vector <int>::iterator vit;
////		for(vit = v111.begin();vit!=v111.end();vit++)
////		{
////			
////			nton[ntonn++] = (*vit);
////		}
////		return ntonn;
//	}
		for(int i = 0;i < qn;i++)
		{
			char qname[10];
			scanf("%s",qname);
			string qns(qname);
			int ntonn = wtf(qname);
			printf("ntonn : %d\n",ntonn);
			if(ntonn)
			{
				for(int ii = 0;ii < ntonn;ii++)
				printf("%d %d\n",ii,nton[ii]);
			}
			else
			{
				printf("нч\n");
			}
		}
		
	}
}
