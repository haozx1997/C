/*
pku3461(Oulipo), hdu1711(Number Sequence)
���ģ�� �ַ����Ǵ�0��ʼ��
Next�����Ǵ�1��ʼ��


*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000002;
int nnext[N];
char S[N] ;
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
����ģʽ��T������S���״γ��ֵ�λ��
���ص�λ���Ǵ�0��ʼ�ġ�
*/


int out[400400];
int main()
{
    
    int TT = 1;
    int i, cc;
    
    
//	while(~scanf("%d%s",&tlen,T))
/*

ababcababababcabab

*/
    while(~scanf("%s",S))
    {
        char *T = S;
		int outn = 0; 
        int wtf = strlen(T);
        out[outn++] = wtf;
        getNext(T);
        while(wtf = nnext[wtf])
        {
			out[outn++] = wtf;
		}
		
		sort(out,out+outn);
		for(int i = 0;i < outn;i++)
		{
			printf("%d%c",out[i]," \n"[i == (outn-1)]);
		}
		
    }
    return 0;
}
/*
3
aaa
12
aabaabaabaab
8
abaabcac




*/
