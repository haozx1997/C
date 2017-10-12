#include<cstdio>
#include<cstring>
const int maxn = 100005;
const int MOD = 1000000007;
int num1[maxn];
int num2[maxn];
int vis[maxn];
long long  s[maxn];
long long x[maxn];
long long  in[maxn];
int n,m;
int xtot,stot;
void dfs(int u,int root,int d)
{
    vis[u] = 1;
    if(num1[u]==root)
    {
        s[stot++] = d; 
        return ;
    }
    dfs(num1[u],root,d+1);
}
void ddfs(int u,int root,int d)
{
    vis[u] = 1;
    if(num2[u]==root)
    {
        x[xtot++] = d;
        return ;
    }
    ddfs(num2[u],root,d+1); 
}
int main()
{
    int T = 1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        stot = 0;
        xtot = 0;
        for(int i=0;i<n;i++)
        scanf("%d",&num1[i]);
        for(int i=0;i<m;i++) scanf("%d",&num2[i]);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,i,1);
            }
        }
    //    for(int i=0;i<stot;i++) printf("%d\n",s[i]);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            if(!vis[i])
            {
                ddfs(i,i,1);
            }
         } 
         memset(in,0,sizeof(in));
    //         for(int i=0;i<xtot;i++) printf("%d\n",x[i]);
        for(int i=0;i<xtot;i++) in[x[i]]++;
    //    for(int i=1;i<=n;i++) printf("%d\n",in[i]); 
        long long ans = 0;
        long long gggg = in[1];
        long long sg = s[0];
        long long sgg = sg;
        if(sgg!=1)
        gggg+=(in[sgg]*sgg);
        for(int i = 2;i*i<=sg;i++  )
        {
            if(!(sg%i))
            {
                if(i*i!=sg)
                {
                    gggg+=(in[sg/i]*sg/i);
                    gggg%=MOD;
                }
        //        printf("%lld\n",gggg);
                gggg+=(in[i]*i);
        //        printf("%lld\n",gggg);
                gggg%=MOD;
            }
            if(sg == 1)
            {
                break;
            }
        }
        ans = gggg;//printf("%lld\n",ans);
        ans%=MOD;
        for(int si = 1;si<stot;si++)
        {
            sg = s[si];
            gggg = in[1];
            if(sg!=1)
            gggg+=(in[sg]*sg);;
            for(int i = 2;i*i<=sg;i++  )
            {
                if(!(sg%i))
                {
                    if(i*i!=sg)
                    {
                        gggg+=(in[sg/i]*sg/i);
                        gggg%=MOD;
                    }
                    gggg+=(in[i]*i);
                    
                    gggg%=MOD;
                }
                if(sg == 1)
                {
                    break;
                }
            }
            ans *= gggg;
            ans%=MOD;
        }
        
        printf("Case #%d: %I64d\n",T++,ans);
    }
    return 0;
}

