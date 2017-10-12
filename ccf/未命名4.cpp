#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

struct file
{
	char name[100][1010];
	
}ff[10];
int  no()
{
	file a,next;
	stack<file> S;
	
}

int main()
{
	int p;
	scanf("%d",&p);
	char root[100];
	scanf("%s",root);
	int j=0,jj=0;
	
	for(int i=0;i<strlen(root);i++)
	 {
	 	if(root[i]=='/')
		 {
		 	j++;
			jj=0; 	
		 }
	 	else 
	 	{
	 	
	 		
	 		ff[0].name[j][jj++]=root[i];
	 		
		 }
	 }

	while(p--)
	{

	    
		char fix[1010];
		scanf("%s",fix);
		int if_point=0;
		for(int i=0;i<strlen(fix);i++)
		{
			if(fix[i]=='.') 
			{
				if_point=1;
				break;
			}
			
		}
		if(!if_point)//ц╩сп. 
			{
				for(int i=0;i<strlen(fix);i++)
				 {
				 	if(fix[i]=='/')
				 	 {
				 	 	if(fix[i+1]=='/')
				 	 	 {
				 	 	 	for(int ii=i+1;ii<strlen(fix);ii++)
				 	 	  		fix[ii]=fix[ii+1];
				 	 	    i--;
						   }
				 	 	  
					  }
				 	
				 }
				 if(fix[strlen(fix)-1]=='/')fix[strlen(fix)-1]='\0';
				 if(fix[0]=='\0') fix[0]='/';
				 printf("%s\n",fix);
					
			}
		else
		{
			char doo[100],doo_i;
			int mulu[100];
			int muli_i=0;
			for(int i=0;i<strlen(fix);i++)
			{
				if(fix[i]=='/') muli[mulu_i++]=i;
			}
			for(int i=0;i<mulu_i;i++)
			 {
			 	doo_i=0;
			 	for(int ii=mulu[i]+1;ii<mulu[i+1];ii++)
			 	 {
			 	 	doo[doo_i++]=fix[ii];
				  }
				 if(doo[0]=='.'&&doo[1]!='.')
				  ff[1]=ff[0];
			 }
			
			
			
		}	
		
	}	
	
}






