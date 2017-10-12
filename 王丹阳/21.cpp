#include<stdio.h>

float rese(float*a,int n)
{
	float ave =  0;
	float ans =  0;
	
	for(int i = 0;i<n;i++)
 	 {
 	 	ave+=a[i];
	  }
	ave /=(float)n;
	ave *=ave;
	for(int i = 0;i<n;i++)
 	 {
 	 	ans+=(a[i]*a[i]-ave);
	  }
	ans /=n*(n-1);  
	
	
	
	return ans;
 } 
 int  main()
 {
 	int n;
 	float a[100];
 	scanf("%d",&n);
 	for(int i = 0;i<n;i++)
 	 {
 	 	scanf("%f",&a[i]);
	  }
	  printf("%f",rese(a,n));
 }
