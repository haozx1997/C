/*
��Щ���ݱ���ܴ� �����޷���Ϊ������±걣���Ӧ�����ԡ�

�����ʱֻ����Ҫ������ݵ�������ԣ� ��ô���Զ��������ɢ������

��ɢ����������ֻ������֮�����Դ�С�йأ���������Ƕ����޹�ʱ�����Խ�����ɢ����

http://blog.csdn.net/gokou_ruri/article/details/7723378
*/


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;


int main()
{
	int a[] = {1,2,3,4,5,6,700,700,9};
	int b[] = {1,2,3,4,5,6,700,700,9};
	sort(a,a+9);
	int size=unique(a,a+9)-a;
	//sizeΪ��ɢ����Ԫ�ظ���
	/*
	unique(num,mun+n)���ص���numȥ�غ��β��ַ��
	֮����˵�Ȳ��������ظ���Ԫ��ɾ������ʵ�ǣ�
	�ú������ظ���Ԫ��һ������ȥ�ˣ�Ȼ����Ȼ���浽
	��ԭ�����У�Ȼ�󷵻�ȥ�غ����һ��Ԫ�صĵ�ַ��
	��Ϊuniqueȥ���������ڵ��ظ�Ԫ�أ�����һ����֮
	ǰ����Ҫ��һ����
	*/
	for(int i=0;i<9;i++)
		b[i]=lower_bound(a,a+size,b[i])-a + 1;
		//kΪb[i]����ɢ�����Ӧ��ֵ
	for(int i = 0;i < 9;i++)	
	{
		printf("%d ",b[i]);
	}
	
	
	

}	
	
