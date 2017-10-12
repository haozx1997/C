#include <iostream>  
#include <string>  
#include <cstring>  
#define INF 0x3f3f3f3f  
#define MAXN 100005  
  
using namespace std;  
int n,V;  
struct Node{  
    int v;  
    string path;  
    void Init()  
    {  
        string init(n,'0');  
        v = 0;  
        path = init;  
    }  
}dp[MAXN];  
int val[MAXN];  
int vol[MAXN]; 
int out[MAXN]; 
 
int main()  
{  
    int T,TT = 1;
    
    
	scanf("%d",&T);
	while(T--) 
    {  
    	int outn = 0;
//    	memset(dp,MAXN,sizeof(dp));
//    	memset(vol,n,sizeof(vol));
//    	memset(val,n,sizeof(val));
//    	memset(out,n,sizeof(out));
    	
    	scanf("%d%d",&V,&n);
        for(int i=1;i<=n;i++)  
            scanf("%d%d",&val[i],&vol[i]);  
        for(int i=0;i<=V;i++)  
        {  
            dp[i].Init();  
        }  
        for(int i=1;i<=n;i++)  
        {  
            for(int j=V;j>=vol[i];j--)  
            {  
                if(dp[j].v<dp[j-vol[i]].v+val[i])  
                {  
                    dp[j].v=dp[j-vol[i]].v+val[i];  
                    dp[j].path=dp[j-vol[i]].path;  
                    dp[j].path[i-1]='1';  
                }  
            }  
        }  
        for (int i = 0;i < n;i++)  
        {  
            if (dp[V].path[i] == '1')  
            {  
                out[outn++] = i+1;  
                //printf("%d")
            }  
        }
        
      //   cout<<dp[V].path<<endl;  
        printf("Case #%d:\n",TT++);
        int ans2 = 0;
        for(int i = 0;i < outn;i++)
		{
			ans2 += vol[out[i]];
		 }
		printf("%d %d\n",dp[V].v,ans2);
		if(outn)
		{
			printf("%d",out[0]);
			for(int i = 1;i < outn ;i++)
			{
				printf(" %d",out[i]);
			}
			puts("");
		  } 
    }  
    return 0;  
}  
