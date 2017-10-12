#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;



set<int> s[70]; 


double same(int n1,int n2)
{
	n1--;n2--;
	int same = 0;
	int s1 = s[n1].size();
	int s2 = s[n2].size();
	
	set<int>::iterator it;
    for(it = s[n1].begin(); it != s[n1].end(); it++)
	 {
        if(s[n2].find(*it) != s[n2].end()) 
		{
			
           same++;
        }
     }
	
	double kill = (double)same/(s1+s2-same);
	
	return kill;
}


int main()
{
	int N,n,nn;
	int qn;
	
	scanf("%d",&N);
	for(int i = 0;i < N; i++)
	{
		scanf("%d",&n);
		for(int j = 0;j < n;j++)
		{
			scanf("%d",&nn);
			s[i].insert(nn);
		}

		
	}
	
	scanf("%d",&qn);
	while(qn--)
	{
		int q1,q2;
		scanf("%d%d",&q1,&q2);
		printf("%.2f",same(q1,q2)*100);
		printf("%c\n",'%');
	}
	
	
	
	
	
	
	
		
 } 
