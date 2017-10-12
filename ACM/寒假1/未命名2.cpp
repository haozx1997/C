#include<stdio.h>
#include<string.h>

int main()
{
	char a[3][5]={"123","xy1","1ab"},t[3];
	int i,j,k;
	//for(i=0;i<3;i++)
	 //scanf("%s",a[i]);
	 printf("%s",a[1]);
	for(i=0;i<2;i++)
	 {
	 	k=i;
	 	for(j=0;j<3;j++)
	 	 if (strcmp(a[j],a[k])>0)k=j;
	 	if(k!=i)
	 	{
	 		strcpy(t,a[i]);strcpy(a[i],a[k]);strcpy(a[k],t);     //t=a[i];a[i]=a[k];a[k]=t;
		 }
	 }
	 for(i=0;i<3;i++)
	 printf("%s ",a[i]);
}
