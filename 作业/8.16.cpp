#include<stdio.h>
#include<string.h>
int A(char a[1024])	
{
	int i,len,z,s,k,q;
	z=s=k=q=0;
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if((a[i]>='a'&&a[i]<'z')||(a[i]>='A'&&a[i]<'Z'))
		z++;
	    else 
		     if(a[i]>='0'&&a[i]<='9')
	          s++;
	         else 
	            if(a[i]==' ')
	               k++;
	            else
	             q++;
    }
    
	printf("%d %d %d %d",z,s,k,q);
    
    return  666;
}
int main()
{ //写一个函数，由实参传入一个字符串，统计此字符串中字母、数字、空格和其他字符的个数，在主函数中输入字符串以及输出上述统计结果。
	int i;
	char a[1024];
	gets(a);
	i=A(a);//用于调用函数 
	return 0;
}
