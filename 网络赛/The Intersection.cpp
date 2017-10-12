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
#include<cstdio>
#include<cmath>
#include<iostream>
#define For(i,j,k) for(register int i=j;i<=k;++i)
using namespace std;
int main(){
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long double xs,cha=10.0,f; //cha????????????????
    int m,zi,mu,n,ans=-1,js; //ans???-1,?????
    m = LONG_LONG_MAX;
    n = 100000;
     cin>>xs; //??,xs?????,n???,m???,??????
     xs = xs*xs;
  ///   xs = pow(xs,(long double)1/3);
     printf("%.20Lf\n",xs);
    For(i,1,m){//????
        js=xs*i; //????????,?????
        if (js>n) break; //??n??????
        f=(long double)js/(long double)i; //f???????
        if (i==1) {ans=1; cha=xs-f; zi=js; mu=i;} //zi???,mu???,???????,???????,?????
        else if (zi*i!=mu*js){ //??i?js????,?????
            if (xs-f==cha) ans++; //?????????????????ans++,?????ans??1???too many
        //??f?????????,??????????????,??????
            if (xs-f<cha){
                ans=1; cha=xs-f; zi=js; mu=i;
            }
        }
        js++; //???????,??????????????
        if (zi*i!=mu*js&&js<=n){
            f=(long double)js/(long double)i;
            if (f-xs==cha) ans++; //?????????????????,???????
            if (f-xs<cha){
                ans=1; cha=f-xs; zi=js; mu=i;
            }
        }
    }
    if (ans>1) printf("TOO MANY\n");
    else if (ans==-1) printf("%d/1\n",n); //??ans????-1,???????????n?????xs(??i=1?????),??????????,???????(??????????????)
    else printf("%d/%d\n",zi,mu); //??ans?1?????
	}
    
    return 0;
}
