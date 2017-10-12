#include<bits/stdc++.h>

using namespace std;

int main()
{
	getchar();
	clock_t start, end; 
	for(int ii = 3;ii < 21;ii++)
	{
		int a[1000];
		long long ans=0;
		long long ans1=1;
		
		for(int i=1;i<=ii;i++)
		{
			ans1 *= i ;
		 } 
		printf("%2d ans %20lld ",ii,ans1);
		printf("预计用时%8d秒\n",ans1/10000/1000); 
		for(int i=0;i<ii;i++)
		{
			a[i] = i ;
		 }
		  
//		start = clock();  
//        
//        
//		do
//		{
//			ans++;
//		}
//		while(next_permutation(a, a + ii)) ;//顺序过 看7行 一定注意范围 
//		end = clock() - start;   
//		printf("%2d ans %20lld ",ii,ans);
//		printf("    用时%8d毫秒\n",end);  

	}


 return 0;
}


