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


char s[200][200];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i = 0; i < n;i++ )
		{
			scanf("%s",s[i]);
			strlwr(s[i]);
		}
		char ss[200];
		scanf("%s",ss);
		int len = strlen(ss);
		int u[200];
		for(int i = 0; i < len;i++ )
		{
			if(ss[i]<='Z'&&ss[i]>='A')
			{
				u[i] = 1;
			}
			else
			{
				u[i] = 0;
			}
		}
		strlwr(ss);
		int cha[200];
		memset(cha,0,sizeof(cha));
		for(int i = 0; i < n;i++ )
		{
			char *now = ss;
			while(strstr(now,s[i])!=NULL)
			{
				int chai = strstr(now,s[i]) - ss;
		//		printf("chai %d %d %c \n",chai,i,ss[chai]);
				for(int j = 0;j < strlen(s[i]);j++)
				{
					cha[chai++] = 1;
				}
				now ++;
			}
			
		}
		char cc[10];
		scanf("%s",cc);
		char c = cc[0];
	//	puts(ss);
		for(int i = 0; i < len;i++)
		{
			if(cha[i] == 1)
			{
				if(ss[i]!=c)
				{
					ss[i] = c;
				}
				else if(ss[i] == 'a'&&c =='a')
				{
					ss[i] = 'b';
				}
				else
				{
					ss[i] = 'a';
				}
				
			}
		}
		
		for(int i = 0; i < len;i++)
		{
			
			if(u[i])
			{
				printf("%c",'A'+ss[i]-'a');
			}
			else
			{
				printf("%c",ss[i]);
			}
		}
		puts("");
//		puts(ss);
//		for(int i = 0;i <len;i++)
//		{
//			printf("%d",cha[i]);
//		}
		
		
		
	}
}
/*
3
bers
ucky
elu
PetrLoveLuckyNumbersPetrLoveLuckyNumbersPetrLoveLuckyNumbers

2
aCa
cba
abAcaba


4
hello
party
abefglghjdhfgj
IVan
petrsmatchwin






3
bers
ucky
elu
PetrLoveLuckyNumbers
t

4
hello
party
abefglghjdhfgj
IVan
petrsmatchwin
a

2
aCa
cba
abAcaba
c








*/





