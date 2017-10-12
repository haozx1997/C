#include<stdio.h>
#include<string.h>
char s[10010][80];
int next[10010];
int main()
{
    int i,j,x,y,r,c,f[80];
    char a[80];
    scanf("%d%d",&r,&c);
    for(i=0;i<c;i++)f[i]=0;
    for(i=0;i<r;i++){
        scanf("%s",s[i]);
        strcpy(a,s[i]);
        //将每行的每种重复子串长度都求出来
        for(j=c-1;j>0;j--){
            a[j]=0;
            for(x=0,y=0;s[i][y];x++,y++){
                if(!a[x])x=0;
                if(a[x]!=s[i][y])break;
            }
            if(!s[i][y])f[j]++;
        }
    }
    for(i=0;i<c;i++)//找出所有行的最小相同的子串长度,为最小重复子矩阵的列数
        if(f[i]==r)break;
    x=i;//最小重复子矩阵的列数
    for(i=0;i<r;i++)s[i][x]=0;
    next[0]=-1;//按纵列求KMP的next函数，以求最小重复子矩阵的行数
    for(i=1,j=-1;i<r;i++){
        while(j!=-1&&strcmp(s[j+1],s[i]))j=next[j];
        if(!strcmp(s[j+1],s[i]))j++;
        next[i]=j;
    }
    printf("%d\n",(r-1-next[r-1])*x);//行列相乘即为最终结果
    return 0;
}

