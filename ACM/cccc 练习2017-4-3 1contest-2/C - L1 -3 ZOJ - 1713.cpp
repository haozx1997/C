#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	char s[300];
	
	
	while(1)
	{
		gets(s);
		if(strcmp(s,"e/o/i") == 0)
		{
			break;
		}
		for(int i = 0;i < strlen(s);i++)
		{
			if(s[i] == 'u'||s[i] == 'o'||s[i] == 'i'||s[i] == 'e'||s[i] == 'a'||s[i] == 'y')
			{
				s[i] = '!';
			}
		}
	//	printf("%d \n",strlen(s));
//		printf("%s\n",s);
		int num = 0;
		int line = 1;
		if(s[0] == '!')
		{
			num++;
		}
		int FF = 0;
		
		for(int i = 1;i < strlen(s);i++)
		{
			
			if(s[i] == '/')
			{
	//			printf("line %d\n",num);
				if(line == 1)
				{
					if(num != 5)
					{
						FF = 1;
						break;
					}
				}
				if(line == 2)
				{
					if(num != 7)
					{
						FF = 1;
						break;
					}
				}
				if(line == 3)
				{
					if(num != 5)
					{
						FF = 1;
						break;
					}
				}
				
				
				line++;
				num = 0;
				continue;
			}
			if(s[i] == '!'&&s[i-1]!='!')
			{
				num++;
			}
		}
		if(line == 3)
				{
					if(num != 5)
					{
						FF = 1;
						
					}
				}
		if(FF == 0)
		{
			printf("Y\n");
		}
		else
		{
			printf("%d\n",line);
		}
	}
}
