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

char s[222200];
char s2[444400];
int len2,anslen;

int p[444400];

int manacher()
{
	memset(p,0,sizeof(p));
	int id = 0;
	int maxx = 0;int mid = 0;
	for(int i = 2;i < len2;i++)
	{
		if(p[id]+id > i)
		{
			p[i] = min(p[id*2-i],p[id]-(i-id));
		}
		else
		{
			p[i] = 1;
		}
		while(s2[i+p[i]] == s2[i-p[i]])
		{
			p[i]++;
		}
		if(id+p[id] < i+p[i])
		{
			id = i;
		}
		
		if(maxx < p[i])
		{
			maxx = p[i];
			mid = i;
		}
		anslen = maxx;
		
	}
	
	return mid;
	
	
}

int main()
{
	char  cc[10];
	while(~scanf("%s%s",cc,s))
	{
		int ans = 0;
		int len = strlen(s);
		int cn = 'a' - cc[0];
		for(int i = 0; i < len;i++)
		{
			s[i] = 'a'+((s[i]-'a'+cn+26)%26);
		}
	//	puts(s);
		len2 = 0;
		
		s2[len2++] = '!';
		s2[len2++] = '#';
		
		for(int i = 0;i < len;i++)
		{
			s2[len2++] = s[i];
			s2[len2++] = '#';
		}
		s2[len2] = 0;
	//	puts(s2);
	
    //    
    	
		int mid = manacher();
		anslen--;
		if(anslen == 1)
		{
			printf("No solution!\n");
			continue;
		}
	//	printf("midd %d  %d\n",mid,anslen);
		int be = 0;
		if(mid%2)
		{
			mid--;
			be = mid/2 - anslen/2;
		}
		else
		{
			mid--;
			be = mid/2 - anslen/2;
		}
		printf("%d %d\n",be,be+anslen-1);
		for(int i = be;i<be+anslen;i++)
		{
			//if(isalpha(s2[i]))
			printf("%c",s[i]);
		}
		puts("");
		
		
	}




 return 0;
}


