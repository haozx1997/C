
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

char pri[8][8] = 
//算符优先级

{ //  +	  -	  *	  /	  (	  )	  # 
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=','0'},
	{'>','>','>','>','0','>','>'},
	{'<','<','<','<','<','0','='},
	
};

char procede(char a,char b)  
{  
    int i,j;  
    switch(a)  
    {  
        case'+':i=0;break;  
        case'-':i=1;break;  
        case'*':i=2;break;  
        case'/':i=3;break;  
        case'(':i=4;break;  
        case')':i=5;break;  
        case'#':i=6;break;  
    }  
    switch(b)  
    {  
        case'+':j=0;break;  
        case'-':j=1;break;  
        case'*':j=2;break;  
        case'/':j=3;break;  
        case'(':j=4;break;  
        case')':j=5;break;  
        case'#':j=6;break;  
    }  
    return pri[i][j];  
}    

char s[2000];
char snum[2000];

int snow = 0;

double dometh(double a,char d,double b)
{
	if(d == '+')
	{
		return a+b;
	}
	if(d == '-')
	{
		return a-b;
	}
	if(d == '*')
	{
		return a*b;
	}
	if(d == '/')
	{
		return (double)a/b;
	}
	
}


double operand()
{
	snow = 0;
	stack <char>oper;
	stack <double> num;
	while(!oper.empty())
	{
		oper.pop();
	}
	while(!num.empty())
	{
		num.pop();
	}
	oper.push('#');
	char now = s[snow++];
	while(now != '#'||oper.top() != '#')
	{
		if(now<='9'&&now>='0')
		{
			double nownum ;
			snow--;
//			printf("snow %d  now %c\n",snow,now);
			sscanf(snum+snow,"%lf",&nownum);
//			printf("123\n");
		
//			printf("snum[snow] %s\n",&snum[snow]);
//			printf("nownum %.2f\n",nownum);

			num.push(nownum);
			snow += strlen(&snum[snow]);
			now = s[snow++];
		}
		else
		{
//				printf("!@ snow %d  now %c\n",snow,now); 
			switch(procede(oper.top(),now))
			{
				case'<':
//						printf("< snow %d  now %c\n",snow,now); 
					oper.push(now);
					now = s[snow++];
					break;
				case'=':
					oper.pop();
					now = s[snow++];	
					break;
				case'>':
//						printf("> snow %d  now %c\n",snow,now); 
					double b = num.top();
					num.pop();
					double a = num.top();
					num.pop();
					double ans = dometh(a,oper.top(),b);//注意ab的先后 
					oper.pop();
					num.push(ans);
					break;
					
			}
		}
	}
	return num.top();
	
}
char anss[1000];
double solve(char ss[])
{
	strcpy(s,ss);
	printf("solve %s?\n",s);
	int len = strlen(s);
	memset(snum,0,sizeof(snum));

	{
		int FFF = 0;
		
		strcpy(snum,s);
		for(int i = 0;i< len;i++)
		{
			if((snum[i]>'9'||snum[i]<'0')&&snum[i]!='.')
			{
				snum[i] = '\0';
			}
			if(snum[i]=='.')
			{
				FFF = 1;
			}
		}
//		printf("snum %s\n",snum);
//		for(int i = 0;i< len;i++)
//		{
//			printf("%c ",snum[i]);
//		}
//		printf("\n");
		strcat(s,"#");
//		puts(s);
		printf("ASD\n");
		if(FFF)
		{printf("%.6f\n",operand());
			sprintf(anss,"%.6f\n",operand());
			
		}
		
		else
		{printf("%lld\n",(long long)operand());
			sprintf(anss,"%lld\n",(long long)operand());
			
		}
		return 2333333;
	}

}

int main()
{
//	freopen("1.in","r",stdin);
	int nnn;
	char smain[1010];
	scanf("%d",&nnn);
	puts("fuck");
	
	scanf("%s",smain);
	int len = strlen(smain);
	for(int i = 0;i< len;i++)
	{
		printf("smain %s\n",smain);
		if(smain[i] == 'i'&&smain[i+1] == 'n'&&smain[i+2] == 't'&&smain[i+3] == '(')
		{
			int star = i,end;
			for(int j = i+4;j< len;j++)
			{
				if(smain[j] == ')')
				{
					end = j;
					smain[j] = '\0';
					break;
				}
			}printf("end %s\n",&smain[end+1]);
			double transint;
			solve(&smain[i+4]);
			printf("anss %s\n",anss);
			sscanf(anss,"%lf",&transint);
			printf("transint %lf\n",transint);
			long long transint_ = (long long)transint;
			char transint_s[1111];
			sprintf(transint_s,"%lld",transint_);
			printf("transint_s %s\n",transint_s);
			
			strcat(transint_s,&smain[end+1]);
			printf("transint_s %s\n",transint_s);
			strcat(&smain[i-1],transint_s);
			len = strlen(smain);
			i = 0;
		}
		
		
	}
	
	solve(smain);
	printf("%s\n",anss);
    return 0;
}

