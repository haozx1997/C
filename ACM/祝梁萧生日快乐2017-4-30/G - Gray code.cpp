#include<bits/stdc++.h>

using namespace std;

char g[1010];
void trans(char bin[])
{
	
	int binlen = strlen(bin);
	bin[binlen] = '0';
	bin[binlen] = '\0';
	binlen = strlen(bin);
	
	for(int i = 0;i<binlen;i++)
	{
		g[i] = ((bin[i]-'0')^(bin[i+1]-'0'))+'0';
	}
	return ;
	
}

int main()
{
	char bin[200200];
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",bin);
		trans(bin);
		puts(g);
	}




 return 0;
}


