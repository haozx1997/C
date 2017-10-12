/*
pku3461(Oulipo), hdu1711(Number Sequence)
���ģ�� �ַ����Ǵ�0��ʼ��
Next�����Ǵ�1��ʼ��


*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000002;
int nnext[N];
char S[N], T[N];
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
����ģʽ��T������S���״γ��ֵ�λ��
���ص�λ���Ǵ�0��ʼ�ġ�
*/

int ans,ii;

int KMP_Index()
{
    int i = ii, j = 0;
    

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
    {
    	ans++;
    	ii = i;
    	KMP_Index();
    }
    else
    {
    	
	}
	return 0;
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
    
    
    while(true)
    {
        scanf("%s",S);
        if(S[0] == '#')
        {
        	break;
		} 
		scanf("%s",T); 
        slen = strlen(S);
        tlen = strlen(T);
        getNext();
        ans = 0;
        ii = 0;
        KMP_Index();
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
