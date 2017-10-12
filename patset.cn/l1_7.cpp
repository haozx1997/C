#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int main()

{
	int fff[5];
	char all[10010];
	scanf("%s",all);
	int len = strlen(all);
	memset(fff,0,sizeof(fff));
	for(int i = 0;i<len;i++)
	{
		if(all[i] == 'g'||all[i] == 'G')
		{
			fff[0]++;
		}
		if(all[i] == 'p'||all[i] == 'P')
		{
			fff[1]++;
		}
		if(all[i] == 'l'||all[i] == 'L')
		{
			fff[2]++;
		}
		if(all[i] == 't'||all[i] == 'T')
		{
			fff[3]++;
		}
		
	}
	while((fff[0]+fff[1]+fff[2]+fff[3])!=0)
	{
		if(fff[0])
		{
			printf("G");
			fff[0]--;
		}
		if(fff[1])
		{
			printf("P");
			fff[1]--;
		}
		if(fff[2])
		{
			printf("L");
			fff[2]--;
		}
		if(fff[3])
		{
			printf("T");
			fff[3]--;
		}
		
		
		
	}
	
	
	
	
	
	
}
