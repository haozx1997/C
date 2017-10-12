#include<stdio.h>
#include<string.h>
int main()
{
 	char a[1024][1024],t[1024];
 	int i,j;
 	printf("输入字符串空格隔开== \n");
 	for(j=0;;j++)
 	 {
 	 	scanf("%s",&a[j]);
 	 	if(getchar()=='\n') break;//j为字符串个数 ，别动 
	  }
	for(i=0;i<j;i++)
	 if(strcmp(a[i],a[i+1])<0)
	  {
	  	strcpy(t,a[i]);
	  	strcpy(a[i],a[i+1]);
	  	strcpy(a[i+1],t);
	  }
	printf("%s",a[j]);
	return 0;  
     
} 
