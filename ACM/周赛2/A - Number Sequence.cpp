#include<stdio.h>
#include<string.h>
int main()
{
	int f[100000];
	int i,j;//iÿ�����ֵ  jÿ�и��� 
	int hangj; //ÿ������ִ�в�� 
	int jnum;//λ�� 
	int fi=1;//��fi���� 
	int t;
	for(i=1;i<100;i++)
	 {
	 	for(j=1;j<=i;j++)
	 	{
	 		hangj=j; 
	 		jnum=0;
	 		while(1)
	 		{
	 			
	 			f[fi]=hangj%10;
	 			fi++;jnum++;
	 			if(!(hangj/10)) break;
	 			hangj/=10;
	 			
			 }
		
			 
			 for(int ii=0;ii<jnum/2;ii++)
			  {
			  	t=f[fi-jnum+ii];
			  	f[fi-jnum+ii]=f[fi-1-ii];
			  	f[fi-1-ii]=t;
			  }

			 
		 }
		 
		  
	 }
	 int y=100;
	 for(i=0;i<100;i++)
	  printf("%d %d\n",f[i],i);
	int qq,tt;
	scanf("%d",&tt);
	while(tt--)
	
	{
		scanf("%d",&qq);
		printf("%d\n",f[qq]);
	}

}

