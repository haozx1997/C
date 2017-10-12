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

map <string,int > m1;
map <string,int>::iterator it;

int nton[100010];//name to num


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
				printf("yes\n");
				
				m1.insert ( pair <string,int > 
				 ( name_s , 2) );
			}
			else
			{
				printf("no\n");
				
				m1.insert ( pair <string,int > 
				 ( name_s , 1) );
			}
			
		}
			it = m1.find("Chen");
	if(it != m1.end())
	{
		printf("chen%d\n",it->second);
	}
	else
	{
		printf("    NO\n");
	}
//		for(int i = 0;i < qn;i++)
//		{
//			char qname[10];
//			scanf("%s",qname);
//			string qns(qname);
//			int ntonn = wtf(qname);
//			printf("ntonn : %d\n",ntonn);
//			if(ntonn)
//			{
//				for(int ii = 0;ii < ntonn;ii++)
//				printf("%d %d\n",ii,nton[ii]);
//			}
//			else
//			{
//				printf("нч\n");
//			}
//		}
//		
	}
}
