#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>
#include<queue>
#include<math.h>

using namespace std;





int main()
{
	int NN;
	scanf("%d",&NN);
	
	while(NN--)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		int m = 0;
		int sum = 0;
		int aa[10010];
		for(int i = 0;i < n;i++)
		{
				int A;
				scanf("%d",&A);
				if(A<=b&&A>=a)
				{
					aa[m++] = A;
					sum += A;
				}
		 } 
		 double ave  = (double)sum/m;
		 printf("%.2f ",ave);
		double ans = 0;
		 for(int i = 0;i < m;i++)
		 {
		 	
		 	ans += ((double)((double)aa[i]-ave)*((double)aa[i]-ave));
		 	 
		 }
		 ans  = sqrt(ans);
		 ans /= m;
		 printf("%.2f\n",ans);
	}
	
	return 0;
}






