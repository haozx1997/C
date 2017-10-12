#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);int tt = 0;
	while(T--)
	{
		int len;
		scanf("%d",&len);
		char s1o[1010];
		char s2o[1010];
		char s12o[3010];
		char s12[3010];
		char s1[1010];
		char s2[1010]; 
		scanf("%s%s%s",s1o,s2o,s12o);
		
		strcpy(s1,s1o);
		strcpy(s2,s2o);
		strcpy(s12,s12o);
		
		int ans = 0;
		
		while(1)
		{
		//	printf("1	%s %s %s\n",s1,s2,s12); 
			for(int i = 0;i < len;i++)
			{
				int j  = i*2;
				s12[j] = s2[i];
				s12[j+1] = s1[i];
				
			}
			for(int i = 0;i < len;i++)
			{
				s1[i] = s12[i];
			}
			for(int i = len;i < 2*len;i++)
			{
				s2[i-len] = s12[i];
			}
			ans++;
			s1[len] = '\0';
			s2[len] = '\0';
			s12[len*2] = '\0';
			
		//	printf("2	%s %s %s\n",s1,s2,s12); 
			if(strcmp(s12,s12o) == 0)
			{
				printf("%d %d\n",++tt,ans);
				break;
			}
			else if((strcmp(s1,s1o) == 0)&&(strcmp(s2,s2o) == 0))
			{
				printf("%d -1\n",++tt);
				break;
			}
			
			
			
		}
		
		
	}





 return 0;
}


