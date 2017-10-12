#include<stdio.h>
int main()
{
	printf("输入两个数字\n");
	char a[10],b[10];
	scanf("%s",a);
	scanf("%s",b);
	int i,pi;
	int F = 0,p = 0;
	double aa = 0,bb = 0;
	double point = 0;
	for(i = 0;a[i] != '\0';i++)
	{
		if(a[i]<'9'&&a[i]>'0')
		{
		    aa = aa*10+(a[i]-'0');
			continue;
		}
		if(a[i] == '.')
		{
			p = 1;
			break;
		}
		F = 1;
		break;
		
		
	}
	
	if(p)
	{
		for(pi = 1,i++;a[i] != '\0';i++,pi++)
		{
			point = a[i]-'0'; 
			for(int ii = 0;ii<pi;ii++)
			{
				point *=0.1; 
			}
			
			aa+=point;
		}
	}
	
	if(0)
	{
		printf("字符串\"%s\"无法转换成数字！请重新输入两个数字。\n请输入两个数字",a);
	}
	else
	{
		 F = 0,p = 0;
	 	 point = 0;
		for(i = 0;b[i] != '\0';i++)
		{
			if(b[i]<'9'&&b[i]>'0')
			{
				bb = bb*10+(b[i]-'0');
				continue;
			}
			if(b[i] == '.')
			{
				p = 1;
				break;
			}
			
			F = 1;
			break;	
			
			
		}
		
		if(p)
	{
		for(pi = 1,i++;b[i] != '\0';i++,pi++)
		{
			point = b[i]-'0'; 
			for(int ii = 0;ii<pi;ii++)
			{
				point *=0.1; 
			}
			
			bb+=point;
		}
	}
		
		
		
		
	}if(F)
		{
			printf("字符串\"%s\"无法转换成数字！请重新输入两个数字。\n请输入两个数字",b);
		}
	else
	{
		printf("%g+%g=%g\n",aa,bb,aa+bb);
	printf("%g-%g=%g\n",aa,bb,aa-bb);
	printf("%g*%g=%g\n",aa,bb,aa*bb);
	printf("%g/%g=%g\n",aa,bb,aa/bb);
	}
	
	
 } 
