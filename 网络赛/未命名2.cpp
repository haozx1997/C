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


using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define lc id << 1
#define rc id << 1 | 1
#define lson low, mid, lc
#define rson mid + 1, high, rc

typedef pair<int, int> pii;

struct Node {
    int x, y1, y2; int flag;
    bool operator < (const Node& a) const {
        if (x == a.x) { return flag > a.flag; } return x < a.x;
    }
};

const int maxn = 1e4;
vector<int> y;
int n, id1, id2, Size, Case = 0;
int a, b, c, d, len_t;
long long ans;
Node node[maxn];
int cnt[maxn * 4];
int len[maxn * 4];

int id(int x) { return lower_bound(y.begin(), y.end(), x) - y.begin() + 1; }
void build(int low, int high, int id) {
    cnt[id] = 0; len[id] = 0; if (low == high) { return; }
    int mid = (low + high) / 2; build(lson); build(rson);
}
inline void push_up(int id, int low, int high) {
    if (cnt[id]) { len[id] = y[high] - y[low - 1]; return; }
    len[id] = len[lc] + len[rc];
}
void update(int l, int r, int key, int low, int high, int id) {
    if (l == low && r == high) {
        if (key) { ++cnt[id]; } else { --cnt[id]; }
        if (low == high && cnt[id] == 0) { len[id] = 0; return; }
        push_up(id, low, high); return;
    }
    int mid = (low + high) / 2;
    if (r <= mid) { update(l, r, key, lson); }
    else if (l >= mid + 1) { update(l, r, key, rson); }
    else { update(l, mid, key, lson); update(mid + 1, r, key, rson); }
    push_up(id, low, high);
}

int main() {

    while (scanf("%d", &n) != EOF) {
        if (n == 0) 
		{ 
			printf("*\n"); 
			break; 
		} 
		y.clear();
        for (int i = 0; i < n; i++) 
		{
            scanf("%d %d %d %d", &a, &b, &c, &d); 
			y.push_back(b); 
			y.push_back(d);
            node[i * 2] = Node{a, b, d, 1}; 
			node[i * 2 + 1] = Node{c, b, d, 0};
        }
        sort(y.begin(), y.end()); 
		y.erase(unique(y.begin(), y.end()), y.end());
        n *= 2; 
		sort(node, node + n); 
		Size = y.size(); 
		build(1, Size, 1); 
		ans = len_t = 0;
        for (int i = 0; i < n;i++) 
		{
            id1 = id(node[i].y1); 
			id2 = id(node[i].y2);
            update(id1, id2 - 1, node[i].flag, 1, Size, 1);
            if (i > 0) 
			{ 
				ans += 1ll * len_t * (node[i].x - node[i - 1].x); 
			} 
			len_t = len[1];
        }
        printf("%lld\n", ans);
    }

    return 0;
}


