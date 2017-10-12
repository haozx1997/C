#include<stdio.h>
#include<string.h>

char num[26]={'2','2','2' , '3','3' , '3','4','4','4','5' ,'5' ,'5' , '6','6' ,'6','7' ,'0' ,'7' ,'7' ,'8' ,'8' ,'8' ,'9' , '9', '9','0' };
int main()
{
	int T;
	scanf("%d",&T);
	//getchar();
	while(T--)
	{
		int n;
		scanf("%d",&n);
		char s[100010][20];
		for(int i = 0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		
		int k,j;
		for(int i = 0;i<n;i++)
		 {
		 	for(j = 0,k = 0;j<strlen(s[i]);j++)
		 	 {
		 	 
		 	 	if(s[i][j]=='-')continue;
		 	 	else 
		 	 	 {
		 	 	 	if(s[i][j]>='A'&&s[i][j]<='Z')
		 	 	 	 {
		 	 	 	 	s[i][k] = num[s[i][j]-'A'];
						}
					else if(s[i][j]>='0'&&s[i][j]<='9')	 
					       {
					       	  s[i][k] = s[i][j];
						   }
					k++;	   
				   }
			  }
			 s[i][7]='\0';
		 }
		 		for(int i = 0;i<n;i++)
		{
			printf("%s \n",s[i]);
		  }  
		 
		 int all = n;
		 int  out[10010];
		 memset(out,0,sizeof(out));
		for(int i = 0;i<n;i++)
		 {
		 	for(int j = i+1;j<n;j++)
		 	{
		 		if(strcmp(s[i],s[j]))
		 		{
		 			if((j+1)!=n)
		 			{
		 				strcpy(s[j],s[j+1]);
		 				all--;
		 				out[i]++;
					 }
		 			
				 }
			 }
		  } 
		for(int i = 0;i<all;i++)
		{
			printf("%s %d\n",s[i],out[i]);
		  }  
		 
						 
		  
	}
 } 
