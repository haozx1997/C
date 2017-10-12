#include<stdio.h>
#include<algorithm>//这个头文件中有max函数
using namespace std;
int max(int x,int y)//故意定义一个错误的 
{
	return x>y?y:x;
}
int main()
{
	printf("%d\n",max(1,2));
	return 0;
}


