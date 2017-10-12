/*
pku3461(Oulipo), hdu1711(Number Sequence)
这个模板 字符串是从0开始的
Next数组是从1开始的


*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000002;
int nnext[N];
int S[N], T[N];
int slen, tlen;

void getNext()
{
    int j, k;
    j = 0; k = -1; nnext[0] = -1;
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            nnext[++j] = ++k;
        else
            k = nnext[k];

}
/*
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
*/
int KMP_Index()
{
    int i = 0, j = 0;
    getNext();

    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++; j++;
        }
        else
            j = nnext[j];
    }
    if(j == tlen)
        return i - tlen+1;
    else
        return -1;
}
/*
返回模式串在主串S中出现的次数
*/
int KMP_Count()
{
    int ans = 0;
    int i, j = 0;

    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext();
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = nnext[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = nnext[j];
        }
    }
    return ans;
}
int main()
{
    
    int TT;
    int i, cc;
    scanf("%d",&TT); 
    while(TT--)
    {
    	int n,m;
        scanf("%d%d",&n,&m);
        slen = n;
        tlen = m;
        for(int i = 0; i < n;i++)
        {
        	scanf("%d",&S[i]);
		}
		for(int i = 0; i < m;i++)
        {
        	scanf("%d",&T[i]);
		}
	//	getNext();
		printf("%d\n",KMP_Index());
    }
    return 0;
}
/*
test case
4
aaaaaa a
abcd d
aabaa b
*/
