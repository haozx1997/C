#include<stdio.h>
#include<string.h>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<iostream>


using namespace std;

	queue<string> f1;
	queue<string> f2;
	string q1,q2;

int main()
{
	char s1[1010];
	char s2[1010];
	scanf("%s",s1);
	scanf("%s",s2);
	int len1=0,len2 =0;
	int ans= 0;
	char* p1 = strtok(s1,"/");
	
	while(p1!=NULL)
	{
		len1++;
		f1.push(p1);
		p1 = strtok(NULL,"/");
	}
	
	char* p2 = strtok(s2,"/");
	while(p2!=NULL)
	{
		len2++;
		f2.push(p2);
		p2 = strtok(NULL,"/");
	}
	
	int len = len1>len2? len1:len2;
	for(int i = 0;i<len;i++)
	{
		if(!f1.empty()&&!f2.empty())
		{
	
			q1=f1.front();
			q2=f2.front();	
			f1.pop();
			f2.pop();
			
			if(q1.compare(q2)!=0)
			{
				
				ans+=2;
			}
			
			continue;
			
		}
		if(!f2.empty())
		{
			q2=f2.front();
			f2.pop(); 
			ans++;
			continue;
		}
		if(!f1.empty())
		{
			q1=f1.front();
			f1.pop(); 
			ans++;
			continue;
		}
		
		
	}
	

	printf("%d\n",ans);
	
	
}
