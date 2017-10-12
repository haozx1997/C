#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
char str[10010][100];
int R,C;
bool same1(int i,int j)//行和相等
{
    for(int k=0;k<C;k++)
    {
    	if(str[i][k]!=str[j][k])
            return false;
	}
    return true;
}
bool same2(int i,int j)//列相等
{
    for(int k=0;k<R;k++)
    {
    	if(str[k][i]!=str[k][j])
        	return false;
	}
    return true;
}
const int MAXN=10010;
int next[MAXN];
int main()
{
    while(scanf("%d%d",&R,&C)==2)
    {
        for(int i=0;i<R;i++)
		{
			scanf("%s",str[i]);
		}
		int i,j;
        j=next[0]=-1;
        i=0;
        while(i<R)
        {
            while(-1!=j && !same1(i,j))
            {
            	j=next[j];
			}
            next[++i]=++j;
        }
        int ans1=R-next[R];
        j=next[0]=-1;
        i=0;
        while(i<C)
        {
            while(-1!=j && !same2(i,j))
            {
            	j=next[j];
			}
            next[++i]=++j;
        }
        int ans2=C-next[C];
        printf("%d\n",ans1*ans2);
    }
    return 0;
}
