#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
 
int father[50002],a,b,m,n,p;
int find(int x)
{
	if(father[x]!=x)
	father[x]=find(father[x]);
	/*
	x���������е��ˣ�father[x]���������������һ�����������˶���һ���������ݹ�ϵ
	�൱�������е�һ���������е�Ԫ�ض����һ��Ԫ�������ݹ�ϵ
	����ʱֻҪ��Ԫ����ָ���father[x]=x��Ԫ��(����Ԫ��)
	Ȼ��Ƚ�����Ԫ�صĸ�Ԫ���Ƿ���ͬ�Ϳ����ж����ϵ
	*/
	return father[x];
}
int main()
{
  int i;
  scanf("%d%d%d",&n,&m,&p);
  for(i=1;i<=n;i++)
    father[i]=i;
    for(i=1;i<=m;i++)
    {
      scanf("%d%d",&a,&b);
      a=find(a);
      b=find(b);
      father[a]=b;
    }
    for(i=1;i<=p;i++)
    {
      scanf("%d%d",&a,&b);
      a=find(a);
      b=find(b);
      if(a==b)
        printf("Yes\n");
      else
        printf("No\n");
    }
  return 0;} 
