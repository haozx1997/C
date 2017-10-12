#include<stdio.h>
#include<string.h>

int map[30][30];
int mmap[10][10];
int map1[10][10];
int L;

int main()
{
	memset(map,0,sizeof(map));
	for(int i=4;i<=18;i++)
	 for(int j=1;j<=10;j++)
	  scanf("%d",&map[i][j]);
	for(int i=0;i<4;i++)
	 for(int j=0;j<4;j++)
	  scanf("%d",&mmap[i][j]);
	scanf("%d",&L);
	int ll=0;
	for(int i=0;i<4;i++)
	 for(int j=0;j<4;j++)
	 {
	 	map[i][j+L]=mmap[i][j];
	 	if(map[i][j+L])
	 	 {
	 	 	map1[ll][0]=i;
	 	 	map1[ll][1]=j+L;
	 	 	ll++;
		  }
	 }	
	 
	int F=0;  
	for(int j=0;j<16;j++)
	{
		
	 for(int i=3;i>=0;i--)
	   {
	 	if(map[map1[i][0]+1][map1[i][1]]==0)
	 	 {
	 	 	map[map1[i][0]+1][map1[i][1]]=1;
	 	 	map[map1[i][0]][map1[i][1]]=0;
	 	 	map1[i][0]++;
		  }
		else
		 {
		 	F=1;
		 	for(int ii=i+1;ii<4;ii++)
		 	{
		 		map[map1[ii][0]][map1[ii][1]]=0;
		 		map[map1[ii][0]-1][map1[ii][1]]=1;
		 		map1[ii][0]--;
			 }
			break;
		   }  
 }
	   if(F)break;		
	}
	
		for(int i=4;i<=18;i++)
	 {
	 	for(int j=1;j<=10;j++)
	  printf("%d ",map[i][j]);
	  printf("\n");
	 }
	 return 0;

}
