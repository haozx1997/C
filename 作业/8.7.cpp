#include<stdio.h>
int main()
{ // ��д����ʵ�ְ�����n�任�ɶ�Ӧ�������ַ����������ظ��ַ������׵�ַ
	int a,b,c;
	int two(int);
	scanf("%d",&a);
	b=two(a);
	printf("%d",b);
}
int two(int a)
{
	int b[1024],B[1024];
    int i=0,j=0;
    for(;a>0;i++)
	   {
	   	b[i]=a%2;
	   	a=a/2;
	   }
	for(;j<=i+1;j++,i--)
	    {
		B[j]=b[i-1];
        printf("%d",B[j]);
        }
         printf("\n");
        return B;

}
