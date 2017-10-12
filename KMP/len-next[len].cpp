/*
pku3461(Oulipo), hdu1711(Number Sequence)
���ģ�� �ַ����Ǵ�0��ʼ��
Next�����Ǵ�1��ʼ��


*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int N = 1000002;
int nnext[N];
char S[N], T[N];
int slen, tlen;

void getNext()
{
    int j, k;
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
����ģʽ��������S�г��ֵĴ���
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
    
    int TT = 1;
    int i, cc;
    
//	while(~scanf("%d%s",&tlen,T))
//    while(~scanf("%s%s",S,T))
/*
ababcababcccccababcabab
*/
	while(~scanf("%s",T))
    {
        
        tlen = strlen(T);
        slen = strlen(S);
        getNext();
        putchar(' ');
	//	printf("%d",KMP_Count());
		puts(T);
		
        for(int i = 0; i <=tlen;i++)
        {
        	printf("%d",nnext[i]);
		}
		puts("");
		printf("%d %d %d\n",tlen,tlen-nnext[tlen],tlen-nnext[tlen-1]);
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
