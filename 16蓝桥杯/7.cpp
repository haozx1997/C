#include<stdio.h>
#include<algorithm>
using namespace std;

int link(int x,int y)
{
	if((x==4&&y==5)||(x==5&&y==4)||(x==9&&y==8)||(x==8&&y==9))
	return 0;
	if(abs(x-y)==1) return 1;
	if(abs(x-y)==4) return 1;	
	return 0;
 } 
int main()
{
	int stamp[15]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int cut[15]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int last[15];
	do
	{
		int f=0;
		for(int i=1;i<6;i++)
		 if(last[i]!=cut[i])f=1;
		if(f)
		{
			int
			for(int i=1;i<6;i++)
			 printf("%d ",cut[i]);
			printf("\n");
			for(int i=1;i<5;i++)
			  {
			  	for(int j=i+1;j<5;j++)
			      if(link(cut[i],cut[j]) ) 
			  } 
			
			for(int i=1;i<6;i++)
		      last[i]=cut[i];
		}
		
	}while(next_permutation(cut+1,cut+13));
 } 
 
