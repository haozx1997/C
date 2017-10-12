#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

class BigNum
{
private:
    int a[50000];    //?谷辰?????∩車那y米???那y
    int len;       //∩車那y3∟?豕
public:
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //11?足o‘那y
    BigNum(const int);       //??辰???int角角D赤米?㊣?芍?℅a?‘?a∩車那y
    BigNum(const BigNum &);  //??㊣∩11?足o‘那y
    BigNum &operator=(const BigNum &);   //?????3?米????﹞?㏒?∩車那y??????DD?3?米????
    BigNum operator*(const BigNum &) const;   //????3?﹞“????﹞?㏒?芍???∩車那y????米??角3?????

    void print();       //那?3?∩車那y
};
BigNum::BigNum(const int b)     //??辰???int角角D赤米?㊣?芍?℅a?‘?a∩車那y
{
    int c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const BigNum & T) : len(T.len)  //??㊣∩11?足o‘那y
{
    int i;
    memset(a,0,sizeof(a));
    for(i = 0 ; i < len ; i++)
        a[i] = T.a[i];
}
BigNum & BigNum::operator=(const BigNum & n)   //?????3?米????﹞?㏒?∩車那y??????DD?3?米????
{
    int i;
    len = n.len;
    memset(a,0,sizeof(a));
    for(i = 0 ; i < len ; i++)
        a[i] = n.a[i];
    return *this;
}
BigNum BigNum::operator*(const BigNum & T) const   //芍???∩車那y????米??角3?????
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i = 0 ; i < len ; i++)
    {
        up = 0;
        for(j = 0 ; j < T.len ; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if(temp > MAXN)
            {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if(up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
void BigNum::print()    //那?3?∩車那y
{
	//int anss  =0;
    int i;
    cout << a[len - 1];
	//anss += (a[len-1]-'0');
    for(i = len - 2 ; i >= 0 ; i--)
    {
        cout.width(DLEN);
        cout.fill('0');
        cout << a[i];

    }
    cout << endl;
}
BigNum quick_pow(BigNum a,int b)
{
	
	BigNum yaoyuan = BigNum(1);
	if(b == 0)
	{
		return yaoyuan;
	}
	while(b)
	{
		if(b&1)
		{
			yaoyuan = (yaoyuan*a);//辦厒傚衄馮ㄛ昦蚚ㄐ 
		}
		a = (a*a);
		b>>=1; 
	}
	return yaoyuan;
}




int main()
{
    int cases,n,t=1; scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        if(n==0){printf("Case #%d: 1\n",t++); continue;}
        
        BigNum s = BigNum (32);
        BigNum ans = quick_pow(s,n);
        
        printf("Case #%d: ",t++);
        ans.print();
    }
    return 0;
}
