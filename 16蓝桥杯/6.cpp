#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int map[20];
int cat(int x)
{
	int f=0;
	if(x!=3&&x!=7)
	if(abs(map[x]-map[x+1])==1) f=1;
	if(x!=4)
	if(abs(map[x]-map[x+3])==1) f=1;
	if(abs(map[x]-map[x+4])==1) f=1;
	if(x!=3)
	if(abs(map[x]-map[x+5])==1) f=1;
	return f;
	
}

int main() 
{
	for(int i=0;i<20;i++)
		 {
		 	map[i]=-20;
		 }	
	int ans=0;
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	do
	{
		 //	printf("!!%d%d%d%d%d%d%d%d%d%d\n",map[1],map[2],map[3],map[4],map[5],map[6],map[7],map[8],map[9],map[10]);
		
		
		int f=0;
		for(int i=0;i<10;i++)
		 {
		 	map[i+1]=a[i];
		 }
		for(int i=1;i<=10;i++)
		 {
		  	if(cat(i)) f=1;
		 }
		if(!f) 
		 {ans++;
		 	 
		// 	printf(" %d%d%d\n%d%d%d%d\n%d%d%d\n",map[1],map[2],map[3],map[4],map[5],map[6],map[7],map[8],map[9],map[10]);
		 //	printf("\n");
		 }
		 
		
	}while(next_permutation(a,a+10));
	printf("%d",ans);
}
