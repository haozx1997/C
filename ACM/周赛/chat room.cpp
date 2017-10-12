#include<stdio.h>
#include<string.h>
int main()
{
	char hello[105];
	int num,i,f1,f2,f3,f4,f5;
    while(scanf("%s",hello)!=EOF)
    {
    	f1=f2=f3=f4=f5=0;
    	num=strlen(hello);
    	for(i=0;i<num;i++)
    	{
    		if(hello[i]=='h')
    		 {
    		 	f1=1;
    		 	break;
			 }
		}
    	for(i++;i<num;i++)
    	{
    		if(hello[i]=='e')
    		 {
    		 	f2=1;
    		 	break;
			 }
		}		
		
    	for(i++;i<num;i++)
    	{
    		if(hello[i]=='l')
    		 {
    		 	f		3=1;
    		 	break;
			 }
		}		
		
    	for(i++;i<num;i++)
    	{
    		if(hello[i]=='l')
    		 {
    		 	f4=1;
    		 	break;
			 }
		}		
		    	for(i++;i<num;i++)
    	{
    		if(hello[i]=='o')
    		 {
    		 	f5=1;
    		 	break;
			 }
		}
		if(f1+f2+f3+f4+f5==5)printf("YES\n");
		else printf("NO\n");
	}
	
}
