#include<stdio.h>
#include<algorithm>//���ͷ�ļ�����max����
using namespace std;
int max(int x,int y)//���ⶨ��һ������� 
{
	return x>y?y:x;
}
int main()
{
	printf("%d\n",max(1,2));
	return 0;
}


