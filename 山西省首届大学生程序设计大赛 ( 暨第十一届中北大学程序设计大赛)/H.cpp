#include<stdio.h>
#include<string.h>

char f1[5][5];
char f2[5][5];


char add(char a,char b)
{
	if(a == '1'&&b =='1')
	 return '.';
	if(a == '1'&&b =='.')
	 return '1';
	if(a == '.'&&b =='1')
	 return '1';
	if(a == '.'&&b =='.')
	 return '.';
	  
}



int  main()
{
	int T,t;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		
		for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			scanf("%s",&f1[i][j]);
		}
		 for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			scanf("%s",&f2[i][j]);
		}
		int f=0;
		
		for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			{
				
				if(add(f1[i][j],f2[i][j])=='.')
				{
					f=1;
					break;
				}
			}
			if(f)
			{
				break;
			}
		}
		if(!f)
		{
		  printf("case %d: YES\n",t+1);
		  continue;
		}
		
		f=0;
		
		for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			{
				
				if(add(f1[i][j],f2[j][2-i])=='.')
				{
					f=1;
					break;
				}
			}
			if(f)
			{
				break;
			}
		}
		if(!f)
		{
		  printf("case %d: YES\n",t+1);
		  continue;
		}
		
		 f=0;
		
		for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			{
				
				if(add(f1[i][j],f2[2-i][2-j])=='.')
				{
					f=1;
					break;
				}
			}
			if(f)
			{
				break;
			}
		}
		if(!f)
		{
		  printf("case %d: YES\n",t+1);
		  continue;
		}
		
		f = 0;
			for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			{
				
				if(add(f1[i][j],f2[2-j][i])=='.')
				{
					f=1;
					break;
				}
			}
			if(f)
			{
				break;
			}
		}
		if(!f)
		{
		  printf("case %d: YES\n",t+1);
		  continue;
		}
		if(f)
		{
			printf("case %d: NO\n",t+1);
		}
		
		

	}
	
	
}
