#include<stdio.h>

int main()
{
	int N,Q;
	int A[100010];
	scanf("%d%d",&N,&Q);
	for(int i = 0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}

	for(int i = 0;i<Q;i++)
	{
		int a,b,c;
		char w;
		scanf("%s",&w);
		if(w == 'Q')
		 {
		 	scanf("%d%d",&a,&b);
		 
		 	a--;b--;
		 	int sum = 0;
		 	for(int j = a;j<=b;j++)
		 	{
		 		sum+=A[j];
			 }
			printf("%d\n",sum); 
		
		 }
		if(w == 'C')
		 {
		 	scanf("%d%d%d",&a,&b,&c);
		 	a--;b--;
		 	int sum = 0;
		 	for(int j = a;j<=b;j++)
		 	{
		 		A[j]+=c;
			 }
			
		 }		 
		 
	}
	return 0;
}
