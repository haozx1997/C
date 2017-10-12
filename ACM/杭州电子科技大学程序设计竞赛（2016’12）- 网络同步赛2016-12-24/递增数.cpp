#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int abs(int n)
{
	if(n > 0)
		return n;
	return -n;	
}

int main() 
{
//	freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		char nn[100];
		sprintf(nn,"%d",n);
		int len = strlen(nn) - 1;
		int ans = 0;
		
		printf("%s\n",nn);
	 } 
	return 0;
}
