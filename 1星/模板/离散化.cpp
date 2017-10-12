/*
有些数据本身很大， 自身无法作为数组的下标保存对应的属性。

如果这时只是需要这堆数据的相对属性， 那么可以对其进行离散化处理！

离散化：当数据只与它们之间的相对大小有关，而与具体是多少无关时，可以进行离散化。

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
	//size为离散化后元素个数
	for(int i=0;i<9;i++)
		b[i]=lower_bound(a,a+size,b[i])-a + 1;
		//k为b[i]经离散化后对应的值
	for(int i = 0;i < 9;i++)	
	{
		printf("%d ",b[i]);
	}
	
	
	

}	
	
