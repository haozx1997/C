#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void*b)//�������Ƚϵĺ�����
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int a[10] = {2,4,1,5,5,3,7,4,1,5};//��������顣
    int i;
    qsort(a,10,sizeof(int),comp);//����qsort����
    for(i=0;i<10;i++)//�������������
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
