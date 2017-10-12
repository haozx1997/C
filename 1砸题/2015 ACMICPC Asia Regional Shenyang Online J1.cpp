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

ll ans[300000];
ll num[300000];
ll sum1[300000];//first hang
ll sum2[300000];//last 
ll sum3[300000];//last one
ll sum4[300000];

int main()
{
	
	ans[5] = 5ll;
	ans[6] = 16ll;
	num[5] = 1ll;
	num[6] = 2ll;
	sum1[6] = 11ll;
	sum1[5] = 5ll;
	sum2[6] = 131ll;
	sum2[5] = 5ll;
	sum3[6] = 8ll;
	sum3[5] = 5ll;
	
	for(int i = 7; i < 9;i++)
	{
		ans[i] = ans[i-1]+ans[i-2];
		ll add = (i%2)? 5ll : 3ll;
		ans[i] = ans[i]+add*(num[i-2]+1)*(num[i-1]+1)%mod;
		printf("%d %I64d\n",i,ans[i]);
		
		ans[i] = ans[i]+(sum1[i-1])*(num[i-2]+1)%mod;
		printf("%I64d %d %I64d\n",sum1[i-1],i,ans[i]);
		
		ans[i] = ans[i]+(sum2[i-2])*(num[i-1]+1)%mod;
		printf("add %d \n",add);
		printf("%I64d %d %I64d\n",sum2[i-2],i,ans[i]);
		num[i] = num[i-1]+num[i-2]+1%mod;
		sum1[i] = sum1[i-2]+(sum3[i-2]+add)*(num[i-1]+1)+sum1[i-1];
		sum2[i] = sum2[i-1]+add*(num[i-2]+1)+sum2[i-2]+(num[i-2]+1)*(sum3[i-1]+add+sum3[i-2]);
		sum3[i] = sum3[i-1]+add+sum3[i-2];
		
	}




 return 0;
}


