#include<stdio.h>
#include<string.h>
void reverse(char a[])
{
	int i=0,j=strlen(a)-1,t;
	for(;i<strlen(a)/2;i++,j--)//һ�����Զ���Ȼ���ַ���ȥ 
	 {
	 	t=a[i];
	 	a[i]=a[j];
	 	a[j]=t;
	 }
	 
}
int main()//��дһ���ַ��������ŵĺ���reverse()����������������ʵ�ֶ��ַ������������ 
{
	char a[1024];
	printf("�����ַ�������������\n");
	scanf("%s",&a);
	reverse(a);
	printf("%s",a);
	return 0;
}
