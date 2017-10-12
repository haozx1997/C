#include<bits/stdc++.h>

using namespace std;
int q[10100][10];


int main()
{
	printf("%d\n",1000000007);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(q,0,sizeof(q));
		int qn,cn;
		int qnum,th,tm;
		int all = 0;
		int allln = 0;
		char s[100];
		scanf("%d%d",&qn,&cn);
		for(int i = 0;i<cn;i++)
		{
			scanf("%d%d:%d%s",&qnum,&th,&tm,s);
		//	printf("%d %d %d %s\n",qnum,th,tm,s);
			if(s[0] == 'A'&&q[qnum][0] == 0)
			{
			//	printf("%d %d\n",qnum,(th*60+tm));
				q[qnum][0] = 1;
				allln++;
				all += (th*60+tm);
				all += q[qnum][1];
			}
			else if(s[0] != 'A'&&q[qnum][0] == 0)
			{
				q[qnum][1]+=20;
			}
		}
	
		printf("%d %d\n",allln,all);
	
	}

 return 0;
}


