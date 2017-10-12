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
const ll mod = (ll)1e9+7;

char s[100];
string ss,so;

multimap<string,int>mm;
multimap<string,int>mm1;

string sc[10];

int main()
{
	sc[0] = "";
	sc[1] = "a";
	sc[2] = "b";
	sc[3] = "c";
	sc[4] = "d";
	sc[5] = "e";
	
	int n,aaam;
	while(~scanf("%d%d",&n,&aaam))
	{
		mm.clear();
		for(int i = 0;i < n;i++)
		{
			scanf("%s",s);
			ss = s;
			so = s;
			mm.insert(make_pair(s,i));
		}
		mm1 = mm;
		while(aaam--)
		{int ans = 0;
		mm = mm1;
		//	printf("%d\n",aaam);
			scanf("%s",s);
			int w[3],wn = 0;
			int len = strlen(s);
			for(int i = 0;i < len;i++)
			{
				if(s[i] == '?')
				{
					s[i] = 0;
					w[wn++] = i+1;
				}
			}
			if(wn == 0)
			{
				ss = s;
				int cc = mm.count(ss);
				if(cc!=0)
				{
					mm.erase(ss);
					ans+=cc;
				}
				
			}
			else if(wn == 1)
			{
				ss = s;
				string s1 = &s[w[0]];
				
			//	ans+=mm.count(ss+s1);
				for(int i =0 ;i < 6;i++)
				{
					string sss = ss+sc[i]+s1;
					int cc = mm.count(sss);
					if(cc!=0)
					{
						mm.erase(sss);
						ans+=cc;
					}
				}
			}
			else if(wn == 2)
			{
				ss = s;
				string s1 = &s[w[0]];
				string s2 = &s[w[1]];
				
			//	ans+=mm.count(ss+s1+s2);
				for(int i =0 ;i < 6;i++)
				{
					for(int j = 0;j < 6;j++)
					{
						string sss = ss+sc[i]+s1+sc[j]+s2;
						
						int cc = mm.count(sss);
						if(cc!=0)
						{
							mm.erase(sss);
							ans+=cc;
						}
					}
					
				}
			}
			else if(wn == 3)
			{
				ss = s;
				string s1 = &s[w[0]];
				string s2 = &s[w[1]];
				string s3 = &s[w[2]];
				
			//	ans+=mm.count(ss+s1+s2+s3);
				for(int i =0 ;i < 6;i++)
				{
					for(int j = 0;j < 6;j++)
					{
						for(int ij = 0;ij < 6;ij++)
						{
							string sss = ss+sc[i]+s1+sc[j]+s2+sc[ij]+s3;
						
							int cc = mm.count(sss);
							if(cc!=0)
							{
								mm.erase(sss);
								ans+=cc;
							}
						}
						
					}
					
				}
			}
			printf("%d\n",ans);
		//	printf("	%d\n",ans);
		}
		
	}
/*

5 3
abcde
abcde
abcde
abcde
abcde

?????
abcde
a??de
abcd?
ab?de

5 5
abcde
cabd
caca
cccc
cbcbbb

a???
cc??? 
cbc??? 
?b?d?
?ccc??

1 1
abcabcdabce
?bc?bcda?bce

1 1
abcabcdabce
?bc?bcdabce

1 1
abcabcdabce
a?bcab?cd?abce

1 1
abcabcdabce
?abc?abcdabce?

1 1
abcabcdabce
abc???abcdabce

1 1
abcabcdabce
abc???dabce


1 1
abcabcdabce
abc??dabce


*/



 return 0;
}


