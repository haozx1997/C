#include<stdio.h>

int maze[7][7];
int main()
{
	int i,j;
	for(i=1;i<6;i++)
	 for(j=1;j<6;j++)
	 scanf("%d",&maze[i][j]);
	for(i=0;i<7;i++)
	 {
	 	maze[i][0]=1;
	 	maze[i][6]=1;
	  } 
	for(j=0;j<7;j++)
	 {
	 	maze[0][j]=1;
	 	maze[6][j]=1;
	  }
	for(i=0;i<7;i++)
	 {
	 	for(j=0;j<7;j++)
	      printf("%d",maze[i][j]);	
	    printf("\n");  
	 }
	 	  
}
