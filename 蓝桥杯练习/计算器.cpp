
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
//������ȼ�

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

char s[200];
char snum[200];

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
					double ans = dometh(a,oper.top(),b);//ע��ab���Ⱥ� 
					oper.pop();
					num.push(ans);
					break;
					
			}
		}
	}
	return num.top();
	
}

int main()
{
//	freopen("1.in","r",stdin);
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		if(s[len-1] == '=')
		{
			len--;
			s[len] = 0;
		}
		strcpy(snum,s);
		for(int i = 0;i< len;i++)
		{
			if(snum[i]>'9'||snum[i]<'0')
			{
				snum[i] = '\0';
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
		printf("%g\n",operand());
	}


    return 0;
}

