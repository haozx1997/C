#include <stdio.h>
int min(int x,int y,int z)
{   
 	int r;
	r=x<y?x:y;
	return(r<z?r:z);
}
int max(int x,int y,int z)
{    
	int r;
	r=x>y?x:y;
	return(r>z?r:z);
}
int dif(int x,int y,int z)
{  
	return max(x,y,z) - min(x,y,z); 
}
int main()
 {  
	int a,b,c,d;
	a = 1;b = 2;c = 3;
	d=dif(a,b,c);
	printf("Max-Min=%d\n",d);
 }

