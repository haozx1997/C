#include<stdio.h>
#include<algorithm>
#include    <string.h>  
#include    <string>  

#include    <stdlib.h>  
#include    <vector> 
#include<map> 
#define ll long long
using namespace std;


int main()
{
	int n,qn;
	
	
		char name_c[10];
		map <string,vector<int> > m1;
   		map <string,vector<int> >::iterator it;
   		vector<int> v2;
   		v2.push_back(1);
   		v2.push_back(1);v2.push_back(2);
   		
   		m1.insert ( pair <string,vector<int> >  ( "123", v2) );
		for(int i = 0;i<n;i++)
		{
			
			string name_s("123");
			it = m1.find(name_s);
			if(it!=m1.end())
			{
				vector<int> v1(it->second);
				printf("%d\n",v1.size());
			}
			
		}
		
	
}
