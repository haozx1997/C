#include<cstdio>
#include<cstring>
char str[1000][1000] ;
char substr[1000] ;
char result[1000] ;
char temp[1000] ;
int next[1000] ;
int len, n, max ;
void getNext(){
    next[0] = -1 ;
    int j = -1 ;
    for(int i=1; i<len; i++)
	{
        while(j>-1&&substr[j+1]!=substr[i])
            j = next[j] ;
        if(substr[j+1]==substr[i])  j ++ ;
        next[i] = j ;
    }
}
void kmp(){
    int j, m ;
    getNext() ;
    for(int k=1; k<n; k++)
	{
        j = -1, m = -1 ;
        for(int i=0; i<60; i++)
		{
            while(j>-1&&substr[j+1]!=str[k][i])
                j = next[j] ;
            if(substr[j+1]==str[k][i]) 
				j ++ ;
            if(j>m) m = j ; 
        }
        if(m<max)
		   max = m ;
    }
}
int main(){
    int t, i, ans ;
    scanf("%d", &t) ;
    while(t--)
	{
        scanf("%d", &n) ;
        for(i=0; i<n; i++)
            scanf("%s", str[i]) ;
        ans = 0 ;
        for(i=0; i<58; i++)
		{
            strcpy(substr, str[0]+i) ;
            len = 60 - i ;
            max = 65 ;
            kmp() ;
            if(max>ans)
			{
                ans = max ;
                strncpy(result, str[0]+i, ans+1) ;
                result[ans+1] = '\0' ;
            }else if(max==ans)
			{ 
                strncpy(temp, str[0]+i, ans+1) ;
                temp[ans+1] = '\0' ;
                if(strcmp(result, temp)>0)
                    strcpy(result, temp) ;
            }
        }
        if(ans>=2)
            printf("%s\n", result) ;
        else
            printf("no significant commonalities\n") ;
    }
    return 0 ;
}
