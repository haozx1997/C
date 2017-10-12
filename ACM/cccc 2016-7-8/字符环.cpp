#include<string.h>
#include<stdio.h>

void up(char *q1,char *q2)//q1´ó 
{
	int ans = 0;
	int cp1 = 0;
	int cp2 = 0;
	int max = 0;
	int l1 = strlen(q1);
	int l2 = strlen(q2);
	for(int i = 0;i < l1;i++)
	{
		cp1 = 0;cp2 = 0;
		for(int j = 0; j < l2;j++)
		{
			if(q1[i+j] == q2[j])
			{
				cp1++;
			}
			else
			{
		//		printf("%d\n",cp1);
				cp2 < cp1?cp2 = cp1:cp2 = cp2;
				cp1 = 0;
			}
		}
		ans>cp2 ? ans = ans:ans = cp2;
	}
	if(ans>(l2/2))
		printf("%d\n",l2/2);
	else	
		printf("%d\n",ans);
		
}


int main()
{
	char s1[300],s2[300];
	char s11[300],s22[300];
	
	scanf("%s",s1);
	scanf("%s",s2);
	strcpy(s11,s1);
	strcat(s11,s1);
	strcpy(s22,s2);
	strcat(s22,s2);
//	puts(s1);
//	puts(s2);
//	puts(s11);
//	puts(s22);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if(l1 > l2)
	{
		up(s11,s22);
	}
	else
	{
		up(s22,s11);
	}
	
}
