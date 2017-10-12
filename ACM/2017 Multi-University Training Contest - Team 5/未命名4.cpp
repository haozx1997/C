#include<cstdio>
#include<cstring>
int n,m;
int num[10005];
int fu[10005];
int ans[10005];
int c[10005];
int tot ;
int main()
{
	
/*

10
4 10
1 1 1 2 2 2 2 2 1 1 1
2 3
1 1 1 1
3 3
1 3 3 1

10

2 3
1 1 1 1
3 3
1 3 3 1

4 10
1 1 1 2 2 2 2 2 1 1 1


*/	
	puts("123");
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        tot = 0;
        scanf("%d%d",&n,&m);
        memset(ans,-1,sizeof(ans));
        memset(num,0,sizeof(num));
        memset(fu,0,sizeof(fu));
        memset(c,0,sizeof(c));
        
        for(int i=0;i<=m;i++) 
			scanf("%d",&num[i]);
        for(int i=0;i<=m;i++) 
			fu[i] = num[i];
        int l = 1; 
		int k = m; 
		int sum = 0;
        while(l<=m&&tot<n)
        {
            if(ans[l]==0) {l++;continue;}
            if(fu[l]>0)
            {
                c[tot++] = l;
                fu[l]--;
                sum+= l;
                for(int i=m;i-l>1;i--)
                {
                    if(num[i-l]>num[i]) ans[i-l] = 0;
                }
            }
            else
            {
                l++;
            }
            if(tot==n-1)
            {
                c[tot++] = m-sum;
                break;
            }
           // for(int i=1;i<=m;i++) printf("%d ",ans[i]); printf("\n");
        }
        for(int i=0;i<tot;i++)
        {
            if(i!=0) printf(" ");
            printf("%d",c[i]);
        }
        printf("\n");
    }
    return 0;
}

