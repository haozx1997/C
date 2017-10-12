#include<bits/stdc++.h>

using namespace std;

long long trans(char s[])
{
	if(strcmp(s,"negative") == 0)
	{
		return -1;
	}
	if(strcmp(s,"zero") == 0)
	{
		return 0;
	}
	if(strcmp(s,"one") == 0)
	{
		return 1;
	}
	if(strcmp(s,"two") == 0)
	{
		return 2;
	}
	if(strcmp(s,"three") == 0)
	{
		return 3;
	}
	if(strcmp(s,"four") == 0)
	{
		return 4;
	}
	if(strcmp(s,"five") == 0)
	{
		return 5;
	}
	if(strcmp(s,"six") == 0)
	{
		return 6;
	}
	if(strcmp(s,"seven") == 0)
	{
		return 7;
	}
	if(strcmp(s,"eight") == 0)
	{
		return 8;
	}
	if(strcmp(s,"nine") == 0)
	{
		return 9;
	}
	if(strcmp(s,"ten") == 0)
	{
		return 10;
	}
	if(strcmp(s,"eleven") == 0)
	{
		return 11;
	}
	if(strcmp(s,"twelve") == 0)
	{
		return 12;
	}
	if(strcmp(s,"thirteen") == 0)
	{
		return 13;
	}
	if(strcmp(s,"fourteen") == 0)
	{
		return 14;
	}
	if(strcmp(s,"fifteen") == 0)
	{
		return 15;
	}
	if(strcmp(s,"sixteen") == 0)
	{
		return 16;
	}
	if(strcmp(s,"seventeen") == 0)
	{
		return 17;
	}
	if(strcmp(s,"eighteen") == 0)
	{
		return 18;
	}
	if(strcmp(s,"nineteen") == 0)
	{
		return 19;
	}
	if(strcmp(s,"twenty") == 0)
	{
		return 20;
	}
	if(strcmp(s,"thirty") == 0)
	{
		return 30;
	}
	if(strcmp(s,"forty") == 0)
	{
		return 40;
	}
	if(strcmp(s,"fifty") == 0)
	{
		return 50;
	}
	if(strcmp(s,"sixty") == 0)
	{
		return 60;
	}
	if(strcmp(s,"seventy") == 0)
	{
		return 70;
	}
	if(strcmp(s,"eighty") == 0)
	{
		return 80;
	}
	if(strcmp(s,"ninety") == 0)
	{
		return 90;
	}
	if(strcmp(s,"hundred") == 0)
	{
		return 100;
	}
	if(strcmp(s,"thousand") == 0)
	{
		return 1000;
	}
	if(strcmp(s,"million") == 0)
	{
		return 1000000;
	}
	return 999999999;
}

int main()
{
	char s[2000];
	while(gets(s))
	{
		if(strlen(s) == 0)
		{
			continue;
		}
		
		int FFF = 1;long long len = strlen(s);
		for(long long i = 0;i<len;i++)
		{
			if(s[i] != ' ')
			{
				FFF = 0;
			}
		}
		if(FFF)
		{
			continue
;		}
		
		
		
		for(long long i = 0;i<len;i++)
		{
			if(s[i] == ' ')
			{
				s[i] = '\0';
			}
		}
		
		char w[1000][20];
		long long k = 0;
		memset(w,0,sizeof(w));
		for(long long i = 0;i<len;i++)
		{
			if(s[i] != '\0')
			{
				sscanf(&s[i],"%s",w[k]);
				i += strlen(w[k++]);
			}
		}
		
		
		
		
		long long ans = 0;
		long long ne = 1;
		long long mill = 0;
		long long thou = 0;
		long long hund = 0;
		
	
		long long sum =  0;
		
		for(long long i = 0;i < k;i++)
		{
			
			if(trans(w[i]) == -1)
			{
				ne = -1;
				continue; 
			}			
			else if(trans(w[i]) == 1000000)
			{
				ans +=sum * 1000000;
				sum = 0;
			}
			else if(trans(w[i]) == 1000)
			{
				ans += sum* 1000;
				sum = 0;
			}
			
			else if(trans(w[i]) == 100)
			{
				sum *= 100;
				
			}
			else
			{
				sum +=  trans(w[i]);
			}
			
	//		prlong longf("%s %d %d %d %d\n",w[i],ans,sum,k,i);
		}
		ans += sum;
		printf("%d\n",(long long )ans*ne);
		memset(s,0,sizeof(s));
	}
}

