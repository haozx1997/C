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

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

char pri[8][8] = 
//算符优先级

{ //  +	  -	  *	  /	  (	  )	  # 
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=','0'},
	{'>','>','>','>','0','>','>'},
	{'<','<','<','<','<','0','='},
	
};

char procede(char a,char b)  
{  
    int i,j;  
    switch(a)  
    {  
        case'+':i=0;break;  
        case'-':i=1;break;  
        case'*':i=2;break;  
        case'/':i=3;break;  
        case'(':i=4;break;  
        case')':i=5;break;  
        case'#':i=6;break;  
    }  
    switch(b)  
    {  
        case'+':j=0;break;  
        case'-':j=1;break;  
        case'*':j=2;break;  
        case'/':j=3;break;  
        case'(':j=4;break;  
        case')':j=5;break;  
        case'#':j=6;break;  
    }  
    return pri[i][j];  
}    

char s[200];
char snum[200];

int snow = 0;

double dometh(double a,char d,double b)
{
	if(d == '+')
	{
		return a+b;
	}
	if(d == '-')
	{
		return a-b;
	}
	if(d == '*')
	{
		return a*b;
	}
	if(d == '/')
	{
		return (double)a/b;
	}
	
}


double operand()
{
	snow = 0;
	stack <char>oper;
	stack <double> num;
	while(!oper.empty())
	{
		oper.pop();
	}
	while(!num.empty())
	{
		num.pop();
	}
	oper.push('#');
	char now = s[snow++];
	while(now != '#'||oper.top() != '#')
	{
		if(now<='9'&&now>='0')
		{
			double nownum ;
			snow--;
//			printf("snow %d  now %c\n",snow,now);
			sscanf(snum+snow,"%lf",&nownum);
//			printf("123\n");
		
//			printf("snum[snow] %s\n",&snum[snow]);
//			printf("nownum %.2f\n",nownum);
			num.push(nownum);
			snow += strlen(&snum[snow]);
			now = s[snow++];
		}
		else
		{
//				printf("!@ snow %d  now %c\n",snow,now); 
			switch(procede(oper.top(),now))
			{
				case'<':
//						printf("< snow %d  now %c\n",snow,now); 
					oper.push(now);
					now = s[snow++];
					break;
				case'=':
					oper.pop();
					now = s[snow++];	
					break;
				case'>':
//						printf("> snow %d  now %c\n",snow,now); 
					double b = num.top();
					num.pop();
					double a = num.top();
					num.pop();
					double ans = dometh(a,oper.top(),b);//注意ab的先后 
					oper.pop();
					num.push(ans);
					break;
					
			}
		}
	}
	return num.top();
	
}

int main()
{
//	freopen("1.in","r",stdin);
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		if(s[len-1] == '=')
		{
			len--;
			s[len] = 0;
		}
		strcpy(snum,s);
		for(int i = 0;i< len;i++)
		{
			if(snum[i]>'9'||snum[i]<'0')
			{
				snum[i] = '\0';
			}
		}
//		printf("snum %s\n",snum);
//		for(int i = 0;i< len;i++)
//		{
//			printf("%c ",snum[i]);
//		}
//		printf("\n");
		strcat(s,"#");
//		puts(s);
		printf("%g\n",operand());
	}


    return 0;
}


