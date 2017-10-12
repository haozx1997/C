/**
 *               ii.                                         ;9ABH,
 *              SA391,                                    .r9GG35&G
 *              &#ii13Gh;                               i3X31i;:,rB1
 *              iMs,:,i5895,                         .5G91:,:;:s1:8A
 *               33::::,,;5G5,                     ,58Si,,:::,sHX;iH1
 *                Sr.,:;rs13BBX35hh11511h5Shhh5S3GAXS:.,,::,,1AG3i,GG
 *                .G51S511sr;;iiiishS8G89Shsrrsh59S;.,,,,,..5A85Si,h8
 *               :SB9s:,............................,,,.,,,SASh53h,1G.
 *            .r18S;..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,.1H315199,rX,
 *          ;S89s,..,,,,,,,,,,,,,,,,,,,,,,,....,,.......,,,;r1ShS8,;Xi
 *        i55s:.........,,,,,,,,,,,,,,,,.,,,......,.....,,....r9&5.:X1
 *       59;.....,.     .,,,,,,,,,,,...        .............,..:1;.:&s
 *      s8,..;53S5S3s.   .,,,,,,,.,..      i15S5h1:.........,,,..,,:99
 *      93.:39s:rSGB@A;  ..,,,,.....    .SG3hhh9G&BGi..,,,,,,,,,,,,.,83
 *      G5.G8  9#@@@@@X. .,,,,,,.....  iA9,.S&B###@@Mr...,,,,,,,,..,.;Xh
 *      Gs.X8 S@@@@@@@B:..,,,,,,,,,,. rA1 ,A@@@@@@@@@H:........,,,,,,.iX:
 *     ;9. ,8A#@@@@@@#5,.,,,,,,,,,... 9A. 8@@@@@@@@@@M;    ....,,,,,,,,S8
 *     X3    iS8XAHH8s.,,,,,,,,,,...,..58hH@@@@@@@@@Hs       ...,,,,,,,:Gs
 *    r8,        ,,,...,,,,,,,,,,.....  ,h8XABMMHX3r.          .,,,,,,,.rX:
 *   :9, .    .:,..,:;;;::,.,,,,,..          .,,.               ..,,,,,,.59
 *  .Si      ,:.i8HBMMMMMB&5,....                    .            .,,,,,.sMr
 *  SS       :: h@@@@@@@@@@#; .                     ...  .         ..,,,,iM5
 *  91  .    ;:.,1&@@@@@@MXs.                            .          .,,:,:&S
 *  hS ....  .:;,,,i3MMS1;..,..... .  .     ...                     ..,:,.99
 *  ,8; ..... .,:,..,8Ms:;,,,...                                     .,::.83
 *   s&: ....  .sS553B@@HX3s;,.    .,;13h.                            .:::&1
 *    SXr  .  ...;s3G99XA&X88Shss11155hi.                             ,;:h&,
 *     iH8:  . ..   ,;iiii;,::,,,,,.                                 .;irHA
 *      ,8X5;   .     .......                                       ,;iihS8Gi
 *         1831,                                                 .,;irrrrrs&@
 *           ;5A8r.                                            .:;iiiiirrss1H
 *             :X@H3s.......                                .,:;iii;iiiiirsrh
 *              r#h:;,...,,.. .,,:;;;;;:::,...              .:;;;;;;iiiirrss1
 *             ,M8 ..,....,.....,,::::::,,...         .     .,;;;iiiiiirss11h
 *             8B;.,,,,,,,.,.....          .           ..   .:;;;;iirrsss111h
 *            i@5,:::,,,,,,,,.... .                   . .:::;;;;;irrrss111111
 *            9Bi,:,,,,......                        ..r91;;;;;iirrsss1ss1111
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxx = 1010;
const ll mod = (ll)530600414;


long long quick_mul(ll a,ll b)
{
	ll yaoyuan = 0;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = (yaoyuan+a)%mod;
		}
		a = (a+a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}

long long quick_pow(ll a,ll b)
{
	ll yaoyuan = 1;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = quick_mul(yaoyuan,a)%mod;
		}
		a = quick_mul(a,a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}

ll a[1001000];

int main()
{
	string s1,s2,s3;
	s1 = "c";
	s2 = "ff";
	for(int i = 3;i < 20;i++)
	{
	//	getchar();
		s3 = s1+s2;
		s1 = s2;
		s2 = s3;
		printf("%d ",i);
	//	cout<<s3<<endl;
		int pre = -1;
		ll ans = 0ll;
		ll ai = 0;
		for(int j = 0; j < s3.size()-2;j++)
		{
			
			if(s3[j] == 'c'&&s3[j+1] == 'f'&&s3[j+2] == 'f')
			{
			//	printf(" %d",j);
				if(pre == -1)
				{
					pre = j;
				}
				else
				{
					printf("%d ",j-pre);
					a[ai++] = (j-pre);
					pre = j;
				}
				
			}
		}
		puts("");
	//	printf("%I64d    %d\n",ans,ai);
		ll n3 = 0;
		ll n5 = 0;
		for(int j = 0; j < ai;j++)
		{
			ll sum = 0ll;
			ll nn3=  0,nn5 = 0;
			for(int jj = j;jj<ai;jj++)
			{
				sum += a[jj];
				if(a[jj] == 3)
				{
					nn3++;
				}
				if(a[jj] == 5)
				{
					nn5++;
				}
				ans += sum;
				n3+=nn3;
				n5+=nn5;
				ans = ans %mod;
			}
		}
//		printf(" %I64d %I64d %I64d\n",n3,n5,n3*3+n5*5);
	//	printf("rnm %I64d\n",rnm);
	//		printf(" %I64d\n",n3);
		printf("%I64d\n",ans);
		
	}
	void init()  
{  
    sum1[1] = sum2[1] = sum3[1] = 0;  
    sum1[2] = sum2[2] = sum3[1] = 0;  
    sum1[3] = sum2[3] = sum3[1] = 0;  
    sum1[4] = sum2[4] = sum3[1] = 0;  
    num[1] = 1; num[2] = 0;  
    num[3] = 1; num[4] = 1;  
    ans[1] = ans[2] = 0;  
    ans[3] = ans[4] = 0;  
    for(int i = 5; i < maxn; i ++)  
    {  
        ans[i] = (ans[i - 1] + ans[i - 2]) % MOD;  
        int add = 3;  
        if(i & 1) add = 5;  
        ans[i] = (ans[i] + sum2[i - 2] * num[i - 1] % MOD) % MOD;  
        ans[i] = (ans[i] + sum3[i - 1] * num[i - 2] % MOD) % MOD;  
        ans[i] = (ans[i] + add * num[i - 1] % MOD * num[i - 2] % MOD) % MOD;  
        num[i] = (num[i - 1] + num[i - 2]) % MOD;  
        sum1[i] = (sum1[i - 1] + sum1[i - 2] + add) % MOD;  
        sum2[i] = (sum2[i - 2] + sum2[i - 1] + add * num[i - 2] + (num[i - 2]) * sum1[i - 1] % MOD) % MOD;  
        sum3[i] = (sum3[i - 1] + sum3[i - 2] + add * num[i - 1] + (num[i - 1]) * sum1[i - 2] % MOD) % MOD;  
//        if(i <= 10) printf("%d - %lld %lld %lld %lld\n", i, num[i], sum1[i], sum2[i], ans[i]);  
    }  
}  

/*
这题显然ans[n]是可以通过ans[n-1]和
ans[n-2]算出来的，其实就是将两个数列
（每个数是相隔C的距离）拼起来，然后中间会产生一个新的数。
然后写一下求和，然后更新一下答案就行了。
中间需要用到sum1表示总和，sum2表示1C[1]+2C[2]......

[cpp] view p

*/


 return 0;
}


