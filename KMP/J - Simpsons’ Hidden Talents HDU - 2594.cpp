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
char S[N], T[N];
int slen, tlen;

void getNext(char T[])
{
    int j, k;
	tlen = strlen(T);
    j = 0; k = -1; nnext[0] = -1;
    while(j <= tlen)
        if(k == -1 || T[j] == T[k])
            nnext[++j] = ++k;
        else
            k = nnext[k];

}
/*
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
*/

int main()
{
    
    int TT;
    int i, cc;
    
    while(cin>>S>>T)
    {
    	int os = strlen(S);
    	int ot = strlen(T);
    	
        strcat(S,T);
        getNext(S);
        slen = strlen(S);
        int ans =  nnext[slen];
        ans = min(ans,os);
        ans = min(ans,ot);
        
        for(int i = 0; i < ans;i++)
        {
        	printf("%c",S[i]);
		}
		if(ans)
		{
			printf(" ");
		}
		printf("%d\n",ans);
		
		
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
