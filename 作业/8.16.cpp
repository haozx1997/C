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
{ //дһ����������ʵ�δ���һ���ַ�����ͳ�ƴ��ַ�������ĸ�����֡��ո�������ַ��ĸ��������������������ַ����Լ��������ͳ�ƽ����
	int i;
	char a[1024];
	gets(a);
	i=A(a);//���ڵ��ú��� 
	return 0;
}
