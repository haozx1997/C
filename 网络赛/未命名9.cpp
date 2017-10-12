#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
char str[10];
struct point
{
    double x,y,z;
    point(double a,double b,double c):x(a),y(b),z(c){}
};
vector<point>G[15];
int main()
{
    int a;
    scanf("%d",&a);
    int p = 0; int pos = 0; double tmp[4];
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        int f = -1; int pp  ;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='.') {f = i;  break;}
        }
        if(f!=-1){
                double po = 1;
            p++; int flag = 1; double sum = 0;
            for(int i=f-1;i>=0;i--)
            {
                sum += po*(1.0*(str[i]-48));
                //printf("%f %f",po,1.0*(str[i]-48));
                po*=10.0;
            }
            po = 0.1;
            for(int i=f+1;i<len;i++)
            {
                sum += po*(1.0*(str[i]-48));
               // printf("%f %f",po,1.0*(str[i]-48));
                po/=10.0;
            }
            tmp[p] = sum;
            //printf("%f\n",sum);
            if(p==3){
                p=0;
                G[pos].push_back(point(tmp[1],tmp[2],tmp[3]));
            }
        }
        else pos++;
    }
//    for(int i=1;i<=pos;i++){
//        printf("%d\n\n",i);
//        for(int j=0;j<G[i].size();j++)
//    {
//        printf("%f %f %f\n",G[i][j].x,G[i][j].y,G[i][j].z);
//    }}
    return 0;
}

