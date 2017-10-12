

#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>

#define MAX 310000
#define FFFF 110000000

using namespace std;
set<int>SSS;

char s[400000];
int now;

int q,n;

struct Tree
{
	int l,r;
	int minn,add;
};
Tree tree[2000100];

void pushup(int x)
{
	int tmp=2*x;
	tree[x].minn=min(tree[tmp].minn,tree[tmp+1].minn);
}


void pushdown(int x)
{
	int tmp=2*x;
	tree[tmp].add+=tree[x].add;
	tree[tmp+1].add+=tree[x].add;
	tree[tmp].minn+=tree[x].add;
	tree[tmp+1].minn+=tree[x].add;
	tree[x].add=0;
}

void build(int l,int r,int x)
{
	tree[x].l=l;
	tree[x].r=r;
	tree[x].add=0;
	if(l==r)
	{
		if(s[l-1] == '(')
    	{
    		now++;
		}
		else
		{
			now--;
			SSS.insert(l);
		//	printf("	%d\n",l);
		}
		int asd;
		
		tree[x].minn=tree[x].add=now;
		return ;
	}
	int tmp=x<<1;
	int mid=(l+r)>>1;
	build(l,mid,tmp);
	build(mid+1,r,tmp+1);
	pushup(x);	 //??????????sum??,?????pushup
}


void update(int l,int r,int c,int x)
{
	if(r<tree[x].l||l>tree[x].r)
		return ;
	if(l<=tree[x].l&&r>=tree[x].r)
	{
		tree[x].add+=c;
		tree[x].minn+=c;
		return ;
	}
	if(tree[x].add)
		pushdown(x);
	int tmp=x<<1;
	update(l,r,c,tmp);	//  !!!
	update(l,r,c,tmp+1);
	pushup(x);
}

int ansmin;
void query(int l,int r,int x)
{
	if(r<tree[x].l||l>tree[x].r)		 //????????????
		return ;
	if(l<=tree[x].l&&r>=tree[x].r)	  //???????????
	{
		ansmin = min(ansmin,tree[x].minn);
		return ;
	}
	if(tree[x].add)
		pushdown(x);
	int tmp=x<<1;
	int mid=(tree[x].l+tree[x].r)>>1;
	if(r<=mid)
		query(l,r,tmp);
	else if(l>mid)
		query(l,r,tmp+1);
	else
	{
		query(l,mid,tmp);
		query(mid+1,r,tmp+1);
	}
}


int findmaxmin()
{
	int l = 1,r = n;
	while(l!=r)
	{
		int mid = (l+r)/2;
		ansmin = FFFF;
		if(query( mid, n,1),ansmin<2)
		{
			l = mid+1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}


int main()
{
   
    
    
    while(~scanf("%d%d", &n,&q)) 
	{
		SSS.clear();
		now = 0;
//		for(int i = 0;  i  <n;i++)
//		{
//			printf("%d",i+1);
//		}
//		printf("\n");
        scanf("%s",s);
        build(1,n,1);
        while(q--) 
		{
//		printf("%s\n",s);
        	int c,anss;
            scanf("%d", &c);
            c--;
            if(s[c] == '(') {
                s[c] = ')';
                update(c+1, n,-2,1);
                SSS.insert(c+1);
                anss = *SSS.begin();
                SSS.erase(SSS.begin());
                s[anss-1] = '(';
                printf("%d\n",anss);
               // if(anss != c+1)
                update(anss, n,2,1);
				
            }
            
            else {
//            	for(int i = 1 ; i <= n;i++)
//            	{
//            		printf("%d",query(i, i,1));
//				}
//				puts("");
				update(c+1, n,2,1);
//            	for(int i = 1 ; i <= n;i++)
//            	{
//            		ansmin = INT_MAX;query(i, i,1);
//            		printf("%d",ansmin);
//				}
//				puts("");
            	s[c] = '(';
            	SSS.erase(c+1);
            	anss = findmaxmin();
            	s[anss - 1] = ')';
            	SSS.insert(anss);
            	printf("%d\n",anss);
            	update(anss, n, -2,1 );
            	
            	
         //   printf("%lld\n", query(1, l, r));
            }
        }
    }
    return 0;
}

/*
6 3
((()))
4
3
1



20 9
()((((()))))()()()()
15
20
13
5
3
10
3
17
18

*/
