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

int er[] = {1,2,4,8,16,32,64,128,256,512,1024};

string ttt(int aa)
{
	int a;
	int b[1024],B[1024];
	string ans = "00000000";
	
	int I = 2; //2~10 进制 
	
	int i = 0,j; 
	a = aa;
	memset(b,0,sizeof(b));
	while(a)  
	{   
	 	b[i]=a%I;     //输入的数字求余存入数组b中;
		a/=I;      //输入的数字整除3并赋值给变量a;
		i++;   
	}
	
   	for(j=0;j<i;j++)     //反向输出数组b中的数即为所输入数字的三进制数  
	{   
	//	printf("%d?\n",j);
		ans[7-j] = b[j]+'0';
	}  
	
	return ans;
}

int tt(string s1)
{
	int len = s1.size();
	int ans = 0;
	for(int i = 0;i < len;i++)
	{
		ans += ((s1[i]-'0')*er[5-i]);
	}
	return ans;
}
char wtf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string ktime(string s)
{
	int len = s.size();
		string s24 = "000000000000000000000000";
		string ans = "";int nu = 0;
		for(int i = 0;i < len;i++)
		{
			string s1 = ttt(s[i]);
			for(int j = 0;j < 8;j++)
			{
				s24[j] = s1[j];
			}
			i++;
			
			if(i >= len)
			{
				s1 = "00000000";
				nu++;
			}
			else
			{
				s1 = ttt(s[i]);
			}
			for(int j = 0;j < 8;j++)
			{
				s24[j+8] = s1[j];
			}
			i++;
			if(i >= len)
			{
				s1 = "00000000";
				nu++;
			}
			else
			{
				s1 = ttt(s[i]);
			}
			for(int j = 0;j < 8;j++)
			{
				s24[j+16] = s1[j];
			}
	//		cout<<s24<<endl;	
			for(int ii = 0;ii < 4;ii++)
			{
				string s1 = "000000";
				
				for(int j = 0;j < 6;j++)
				{
					s1[j] = s24[ii*6+j];
				}
	//			cout<<s1<<endl;
	//			printf("wtf %d\n",tt(s1));
				ans += wtf[tt(s1)];
			}
		
		}
		if(nu == 1)
		{
			ans[ans.size()-1] = '=';
		}
		if(nu == 2)
		{
			ans[ans.size()-1] = '=';
			ans[ans.size()-2] = '=';
			
		}
		
		
//		cout<<ans<<endl;
		return ans;
}


int main()
{
	int T,ca = 1;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		char s[1000];
		scanf("%d%s",&n,s);
		string ans = s;
		for(int i = 0;i < n;i++)
		{
			ans = ktime(ans);
		}
		printf("Case #%d: ",ca++);
		cout<<ans<<endl;
		
//		
//		
//		
//		printf("%d %d\n",ans/72,ans);
//		
	}

/*
Case #1: TWlrZQ==
Case #2: Vmtaa2MyTnNjRkpRVkRBOQ==
Case #1: TWlrZQ==
4 Mike
Case #2: Vmtaa2MyTnNjRkpRVkRBOQ==
*/


 return 0;
}


