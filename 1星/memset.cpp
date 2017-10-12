#include<stdio.h>
#include<string.h>
int main() 
{
	int map[10];
	memset(map,-1,sizeof(map));

		for(int i=0;i<10;i++)
		 {
		 	printf("%d",map[i]);
		 	printf("\n");
		 }
	memset(map,0,sizeof(map));

		for(int i=0;i<10;i++)
		 {
		 	printf("%d",map[i]);
		 	printf("\n");

		 }
	memset(map,1,sizeof(map));

		for(int i=0;i<10;i++)
		 {
		 	printf("%d",map[i]);
		 	printf("\n");
		 	
		 }		 
		

}
