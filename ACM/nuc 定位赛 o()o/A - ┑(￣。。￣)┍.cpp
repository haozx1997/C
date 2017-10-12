#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<map>
#include<iostream>
#include<math.h>
#include<string>
#include<string.h>

const double eps=1e-8;
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)
using namespace std;

int main()
{
	char numb[100];
	while(~scanf("%s",numb))
	{
		char n[100] ={"\0"};
		int len = strlen(numb);
		for(int i = 0;i < len;i++)
		{
			if(numb[i]!='0')
			 {
			 	strcat(n,(numb+i));
				break;
			 }
		}
		printf("%s\n",n);
		len = strlen(n);
		if(len<3)
		 {
		 	printf("-1\n");
		 	continue;
		 }
		 if(len<13)
		 {
		 	long max = 0;
		 	int maxi = 0;
		 	long num;
		 	for(int i = 0;i < len-6+1;i++)
		 	{
		 		strcpy(numb,n+i);
		 		numb[6] = '\0';
				 printf("!%s\n",numb);
				  
		 		sscanf(numb,"%ld",&num);
		 		printf("~~%ld\n",num);
		 		if(num>max) 
		 		{
		 			max = num; 
		 			maxi = i;
				 }
			 }
			 long n1 ;
			 long n2 ;
			if(maxi != len-6)
			{
				n[maxi] = '\0';
				
				sscanf(n,"%ld",&n1);
				
				sscanf(n+maxi+6,"%ld",&n2);
				printf("%ld %ld %ld\n",n1,max,n2);				
			}
			else
			{
				sscanf(n+1,"%ld",&n1);
				
			}
		 }
		 
		 
	}
}
