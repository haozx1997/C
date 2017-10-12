#include<bits/stdc++.h>

using namespace std;


int len;
char s[1010];

int dp[1100][1100];
long long sum[1100][1100];
const int M = 1000000007;



int main()
{
	while(~scanf("%s",s))
	{ 
    	memset(dp,0,sizeof(dp));
    	memset(sum,0,sizeof(sum));
    	
        int len = strlen(s);  
        sum[0][1] = 1;  
        for(int i = 1;i <= len; i++) {  
            for(int j = 1;j <= i+1; j++) {  
                sum[i][j] = sum[i][j-1];  
                if(s[i-1] != 'D')  
                    sum[i][j] += sum[i-1][j-1];  
                if(s[i-1] != 'I')  
                    sum[i][j] += sum[i-1][i] - sum[i-1][j-1] + M;  
                sum[i][j] %= M;  
            }  
        }  
        printf("%I64d\n", sum[len][len+1]%M);  
    
	}

 return 0;
}


