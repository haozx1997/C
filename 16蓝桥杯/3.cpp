#include<stdio.h>///0²»ÒªÍü¼Ç 
#include<math.h>
#include<string.h>

char v[15];
int cat(int x)
{

	if(v[x]) return 1;
	v[x]=1;
	return 0; 
}

int main()
{
	int t1,t2,a,b,c,yes,ans=0;

	for(t1=100;t1<=999;t1++)
	 {
	 	for(t2=100;t2<=999;t2++)
	 	 {
	 	 	for(a=0;a<10;a++)
	 	 	{
		 	 	for(b=0;b<10;b++)
	 	 	    {
   	 	 	       for(c=0;c<10;c++)
	 	 	        {
	 	 	        	if(fabs(t1/(double)t2+b/(double)c+a-10)<0.0001)
	 	 	        	  {
	 	 	        	  	yes=0;
	 	 	        	  	
	 	 	        	  	for(int q=0;q<15;q++)
	 	 	        	  	 {
	 	 	        	  	 	v[q]=0;
	 	 	        	  	 	
								 }
	 	 	        	
	 
	 	 	        		yes=cat(t1/100)+cat(t1/10%10)+cat(t1%10)+cat(t2/100)+cat(t2/10%10)+cat(t2%10)+cat(a)+cat(b)+cat(c);
						
							if(yes==0){
							   ans++;
							   printf("%d + %d/%d + %d/%d\n",a,b,c,t1,t2);   
						}
						  }
			        }
			     }
	 	 		
			  }
			  
		  }
	 }
	 printf("%d",ans);
	
 } 
