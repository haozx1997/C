#include <set>  
#include <map>  
#include <queue>  
#include <math.h>  
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <iostream>  
#include <algorithm>  
  
#define eps 1e-6  
#define pi acos(-1.0)  
#define inf 107374182  
#define inf64 1152921504606846976  

#define iabs(x)  ((x) > 0 ? (x) : -(x))  
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))  
#define clearall(A, X) memset(A, X, sizeof(A))  
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))  
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))  
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )  
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )  
  
using namespace std;  
  
struct node  
{  
    long long num[75];  
    node()  
    {  
        clearall(num,0);  
    }  
    void clen()  
    {  
        clearall(num,0);  
    }  
};  
  
struct node matrix[75];  
int n,m,len;  
bool free_x[75];  
  
long long X[75],p;  
  
void Debug(void)  
{  
    puts("");  
    int i, j;  
    for (i = 0; i < m; i++)  
    {  
        for (j = 0; j < n + 1; j++)  
        {  
            printf("%4d ", matrix[i].num[j] );
        }  
        cout << endl;  
    }  
    cout << endl;  
}  
  
int Guass()  
{  
    int i,j,k,col;  
    clearall(X,0);  
    clearall(free_x,1);//�ѽ⼯��գ����б�������Ϊ���ɱ���  
  
    //Debug();  
  
    for (k = 0,col = 0; k < m && col < n; ++k, ++col) //ö������  
    {  
        int max_r = k;//�ҵ���col��Ԫ�ؾ���ֵ�����������k�н���.(Ϊ���ڳ���ʱ��С���)  
        for (i = k + 1; i < m; ++i)  
        {  
            if (iabs(matrix[i].num[col]) > iabs(matrix[max_r].num[col])) max_r = i;  
        }  
        if (max_r != k) //����  
        {  
            for (i = k; i < n + 1; ++i) swap(matrix[k].num[i],matrix[max_r].num[i]);  
        }  
        /*if (matrix[k].num[col]!=0 ) //�����Ӧ���ж�Ϊ0��ö�ٸ��е���һ�� 
        { 
            k--; 
            continue; 
        }*/  
        for (i = k + 1; i < m; ++i) //��k��ߵ�col���г��ȱ任���н��ݾ���  
        {  
            if (matrix[i].num[col]!=0)  
            {  
                long long x1=matrix[i].num[col],x2=matrix[k].num[col];  
                for (j = col; j < n + 1; ++j)  
                {  
                    matrix[i].num[j] = matrix[i].num[j] *x2- x1*matrix[k].num[j];  
                    matrix[i].num[j] = (matrix[i].num[j]%p+p)+p;  
                }  
            }  
        }  
    }  
  
      
    // 1. �޽�����: ������������д���(0, 0, ..., a)��������(a != 0). ��R(A) != R(A')�޽�  
    /*for (i = k; i < m; ++i) 
    { 
        if (iabs(matrix[i].num[col]) >eps) return -1; 
    }*/  
    // 2. ���������: ��n * (n + 1)���������г���(0, 0, ..., 0)�������У���˵��û���γ��ϸ����������.  
    // �ҳ��ֵ�������Ϊ���ɱ�Ԫ�ĸ���.   ��R(A) = R(A') < n  
    //printf("%d %d\n",k,n);  
    /*if (k < n) 
    { 
        //ע�ʹ�Ϊ��������ɱ��� 
        // ���ȣ����ɱ�Ԫ��n - k��������ȷ���ı�Ԫ������n - k��. 
        int num = 0,freeidx; 
        for (i = k - 1; i >= 0; --i) 
        { 
            num = 0;// �����жϸ����еĲ�ȷ���ı�Ԫ�ĸ������������1�������޷���⣬������ȻΪ��ȷ���ı�Ԫ. 
            double tmp = matrix[i].num[n]; 
            // ��i��һ��������(0, 0, ..., 0)���������Ϊ�����������ڵ�k�е���m��. 
            // ͬ������i��һ��������(0, 0, ..., a), a != 0��������������޽��. 
            for (j = 0; j < n; ++j) 
            { 
                if (iabs(matrix[i].num[j]) > eps && free_x[j]) 
                { 
                    num++; 
                    freeidx = j; 
                } 
            } 
            if (num > 1) continue; // �޷�����ȷ���ı�Ԫ. 
            // ˵����ֻ��һ����ȷ���ı�Ԫfree_index����ô���������ñ�Ԫ���Ҹñ�Ԫ��ȷ����. 
            tmp = matrix[i].num[n]; 
            for (j = 0; j < n; ++j) 
            { 
                if (iabs(matrix[i].num[j])>eps && j != freeidx) tmp -= matrix[i].num[j]*X[j]; 
            } 
            X[freeidx] = tmp/matrix[i].num[freeidx]; 
            free_x[freeidx] = 0; 
        } 
        return n - k; 
    }*/  
    // 3. Ψһ������: ��n * (n + 1)�����������γ��ϸ����������.  
    // �����Xn-1, Xn-2 ... X0.  
    for (i = k - 1; i >= 0; --i)  
    {  
        long long tmp = matrix[i].num[n];  
        for (j = i + 1; j < n; ++j)  
        {  
            tmp =((tmp- matrix[i].num[j]*X[j])%p+p)%p;  
        }  
        while(tmp%matrix[i].num[i])tmp+=p;  
        X[i] = ((tmp/matrix[i].num[i])%p+p)%p;  
    } Debug(); 
    return 0;  
}  
char s[75];  
int main()  
{  
	freopen("in.txt", "r", stdin);
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        clearall(matrix,0);  
        scanf("%lld%s",&p,s);  
        n=strlen(s);  
        m=n;  
        for(int i=0;i<n;i++)  
        {  
            if(s[i]!='*')  
            matrix[i].num[n]=(s[i]-'a'+1)%p;  
            matrix[i].num[0]=1;  
            for(int j=1;j<n;j++)  
            {  
                matrix[i].num[j]=(matrix[i].num[j-1]*(i+1))%p;  
            }  
        }  
        Debug();  
        Guass();  
        for(int i=0;i<n;i++)  
        {  
            if(i!=0)printf(" ");  
            printf("%lld",X[i]);  
        }  
        //Debug();  
        puts("");  
    }  
    return 0;  
}  
