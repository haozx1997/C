#include<stdio.h>
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
	char v[15];

	t1=925;t2=714;a=6;b=8;c=3;
	 	 	        	  	
	memset(v,0,sizeof(v));
		 	 	        		printf("cat%d %d %d %d %d %d %d %d %d \n",cat(t1/100),cat(t1/10%10),cat(t1%10),cat(t2/100),cat(t2/10%10),cat(t2%10),cat(a),cat(b),cat(c));

	yes=cat(t1/100)+cat(t1/10%10)+cat(t1%10)+cat(t2/100)+cat(t2/10%10)+cat(t2%10)+cat(a)+cat(b)+cat(c);
    printf("VVV%d %d %d %d %d %d %d %d %d \n",v[t1/100],v[t1/10%10],v[t1%10],v[t2/100],v[t2/10%10],v[t2%10],v[a],v[b],v[c]);
	 	 	        		printf("cat%d %d %d %d %d %d %d %d %d \n",cat(t1/100),cat(t1/10%10),cat(t1%10),cat(t2/100),cat(t2/10%10),cat(t2%10),cat(a),cat(b),cat(c));

	printf("%d",yes);
	if(yes==0)ans++;   	
						 
	 printf("%d",ans);
	
 } 
