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
class Solution {
public:
	int ans;
	int findMinStep(string board, string hand) {
		ans = 10000;
		map<char, int> table;
		for (int i = 0; i < hand.length(); i++) {
			if (table.find(hand[i]) == table.end()) table.insert(make_pair(hand[i], 1));
			else table.find(hand[i])->second++;
		}
		dfs(stack<pair<char, int> >(), board, table, 0);
		return (ans == 10000) ? -1 : ans;
	}
	void dfs(stack<pair<char, int> > pre, string left, map<char, int> table, int cur) {
		for (int i = 0; i < left.length(); i++) {
			while (!pre.empty() && pre.top().first != left[i] && pre.top().second >= 3) {
				pair<char, int> top = pre.top();
				dfs(stack<pair<char, int> >(), left.substr(0, i - top.second) + left.substr(i, left.length() - i), table, cur);
				pre.pop();
			}
			if (pre.empty()) pre.push(make_pair(left[i], 1));
			else if (pre.top().first == left[i]) pre.top().second++;
			else if (pre.top().first != left[i]) {
				pair<char, int> top = pre.top();
				if (table.find(top.first) != table.end() && table.find(top.first)->second + top.second >= 3) {
					table.find(top.first)->second -= (3 - top.second);
					dfs(stack<pair<char, int> >(), left.substr(0, i - top.second) + left.substr(i, left.length() - i), table, cur + 3 - top.second);
					table.find(top.first)->second += (3 - top.second);
				}
				pre.push(make_pair(left[i], 1));
			}
		}
		while (!pre.empty()) {
			pair<char, int> top = pre.top();
			if (top.second >= 3) pre.pop();
			else if (table.find(top.first) != table.end() && table.find(top.first)->second + top.second >= 3) {
				table.find(top.first)->second -= (3 - top.second);
				cur += (3 - top.second);
				pre.pop();
			}
			else break;
		}
		if (pre.empty()) ans = min(ans, cur);
	}
}FFF;
int main()
{
	int T,TT = 1;
	scanf("%d",&T);
	string hand = "";
	string tttt;
	for(int i = 0;i <300;i++)
	{
		hand = hand + "01";
	}
	while(T--)
	{
		cin>>tttt;
		printf("Case #%d: %d\n",TT++,FFF.findMinStep(tttt,hand));
	}




 return 0;
}


