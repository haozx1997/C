#include<stdio.h>
#include<string.h>
void reverse(char a[])
{
	int i=0,j=strlen(a)-1,t;
	for(;i<strlen(a)/2;i++,j--)//一定除以二不然会又翻回去 
	 {
	 	t=a[i];
	 	a[i]=a[j];
	 	a[j]=t;
	 }
	 
}
int main()//编写一个字符串逆序存放的函数reverse()，并由主函数调用实现对字符串的逆序操作 
{
	char a[1024];
	printf("输入字符串！！！！！\n");
	scanf("%s",&a);
	reverse(a);
	printf("%s",a);
	return 0;
}
