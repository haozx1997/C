#include<stdio.h>
#include<string.h>

void mcpy(char *str1,char *str2)
{
	int len_1 = strlen(str1);
	int len_2 = strlen(str2);
	int f = 0;
	for(int i = 0;i<len_2;i++)
	{
		for(int j = 0;j<len_1;j++)
		{
			int jj;
			if(str1[j] == str2[i])
			{
				for(jj = i;jj<len_2;jj++)
				{
					str1[j++] = str2[++i];
				}
				f = 1;
				break;
			}
		}
		if(f)
		{
			break;
		}
	}
	
	
	
 } 
 
 
 int main()
 {
// 	char s1[] = {"hello"};
//	char s2[] = {"world"};

	char s1[100];
	char s2[100];
	scanf("%s",s1);
	scanf("%s",s2);
	printf("%s\n",s1);
	printf("%s\n",s2);
	mcpy(s1,s2); 
 	printf("%s\n",s1);
	return 0;
 }
