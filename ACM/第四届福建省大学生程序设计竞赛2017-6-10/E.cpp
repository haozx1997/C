#include<bits/stdc++.h>

using namespace std;
/*

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0











*/
#define CLR(arr,val)  memset(arr,val,sizeof(arr))  
const int MAX=100100; 
int n,q;
	int a[100100];
	int c[100100];
class RMQ{   
public:   
    void rmq()  
    {   int temp=(int)(log((double)n)/log(2.0));  
        for(int i=0;i<n;i++)  
            DP[i][0]=c[i];  
        for(int j=1;j<=temp;j++)  
            for(int i=0;i<n;i++)  
                if(i+(1<<j)<n) DP[i][j]=max(DP[i][j-1],DP[i+(1<<(j-1))][j-1]);   
    }      
    int Minimum(int L,int H)  
    {   int k=(int)(log((double)H-L+1)/log(2.0));  
        return max(DP[L][k],DP[H-(1<<k)+1][k]);  
    }  
    void Init(){CLR(DP,0);}  
private:  
    int DP[2*MAX][20];          
}R;  

int main()
{
	
	
	while(scanf("%d",&n),n)
	{
		R.Init(); 
		scanf("%d",&q);
		int an = 1;
		a[0] = 1;
		int pre,now;
		scanf("%d",&pre);
		for(int i = 2;i <= n;i++)
		{
			scanf("%d",&now);
			if(now != pre)
			{
				a[an++] = i;
				pre = now;
			}
		}
		a[an] = n+1;
		for(int i = 0;i < an;i++)
		{
			c[i] = a[i+1] - a[i];
		}

		R.rmq();
		
		while(q--)
		{
			int l,r,ln,rn;
			scanf("%d%d",&l,&r);
			ln = lower_bound(a,a+an,l)-a;
			rn = upper_bound(a,a+an,r)-a-1;
		//	printf("	%d %d\n",ln,rn);
			
			int ans = max(a[ln]-l,r - a[rn]);
			ans  = R.Minimum(ln+1,rn+1);
			
			
			
			
			printf("%d\n",ans);
		}
		
		
	}




 return 0;
}


