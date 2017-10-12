//http://blog.sina.com.cn/s/blog_71dbfe2e0101f7zb.html
//http://dev.gameres.com/Program/Abstract/Geometry.htm#矢量的概念

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
const double eps=1e-8;
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)

int max(int a,int b)
{
	if(a > b)
	 return a;
	return b ;
}
int min(int a,int b)
{
	if(a < b)
	 return a;
	return b ;
}



struct point2d//点也是向量
{
	int x,y;
	point2d(int x=0,int y=0):x(x),y(y){}
};
point2d p[60];


struct polygon//多边形 点的集合;
{
	point2d pp[1010];
	int size;
};


int map[300][300];
int ans;

int ison(int i3,int maxx1,int minx1,int maxy1,int miny1)
{
    if(p[i3].x<=maxx1&&p[i3].x>=minx1&&p[i3].y<=maxy1&&p[i3].x>=miny1)
    {
        return 1;
    }



    return 0;
}

int check(int i1,int i2,int q1,int q2,int i3,int i4,int q3,int q4)
{
    int maxx1 = max(p[i1].x,p[i2].x);
    int maxy1 = max(p[i1].y,p[i2].y);
    int maxx2 = max(p[i3].x,p[i4].x);
    int maxy2 = max(p[i3].y,p[i4].y);
    int minx1 = min(p[i1].x,p[i2].x);
    int miny1 = min(p[i1].y,p[i2].y);
    int minx2 = min(p[i3].x,p[i4].x);
    int miny2 = min(p[i3].y,p[i4].y);

    int big = 0;
    if(maxx1>maxx2)
    {
        big = 1;
    }
    int all = 0;
    int touchin = 0;
    int ans = 0;
    if(big)//1 大
    {
        if(p[i3].x<maxx1&&p[i3].x>minx1&&p[i3].y<maxy1&&p[i3].x>miny1)
        {

            all++;
        }
        if(ison(i3,maxx1,minx1,maxy1,miny1))
            {
                touchin = 1;
            }
        if(p[i4].x<maxx1&&p[i4].x>minx1&&p[i4].y<maxy1&&p[i4].x>miny1)
        {

            all++;
        }
        if(ison(i4,maxx1,minx1,maxy1,miny1))
            {
                touchin = 1;
            }
        if(p[q3].x<maxx1&&p[q3].x>minx1&&p[q3].y<maxy1&&p[q3].x>miny1)
        {

            all++;
        }
        if(ison(q3,maxx1,minx1,maxy1,miny1))
            {
                touchin = 1;
            }
        if(p[q4].x<maxx1&&p[q4].x>minx1&&p[q4].y<maxy1&&p[q4].x>miny1)
        {

            all++;
        }
        if(ison(q4,maxx1,minx1,maxy1,miny1))
            {
                touchin = 1;
            }
//        puts("one");
//        printf("1111 %d %d %d %d\n",maxx1,minx1,maxy1,miny1);
//        printf("2222 %d %d %d %d\n",maxx2,minx2,maxy2,miny2);

        if(all == 4)
        {
//            printf("all  = 4");
            ans = (maxx1-minx1)*(maxy1-miny1);
            return ans;
        }
        else if(touchin == 0)
        {
            ans = (maxx1-minx1)*(maxy1-miny1)+(maxx2-minx2)*(maxy2-miny2);
//            printf("++++%d %d\n",(maxx1-minx1)*(maxy1-miny1),(maxx2-minx2)*(maxy2-miny2));
            return ans;
        }
        else
        {
            return 0;
        }

    }
    else
    {
        swap(maxx1 , maxx2);
        swap(maxy1 , maxy2);
        swap(minx1 , minx2);
        swap(miny1 , miny2);
        swap(i3 , i1);
        swap(i4 , i2);
        swap(q3 , q1);
        swap(q4 , q2);

        if(p[i3].x<maxx1&&p[i3].x>minx1&&p[i3].y<maxy1&&p[i3].x>miny1)
        {

            all++;
        }
        if(ison(i3,maxx1,minx1,maxy1,miny1))
            {
                touchin = 1;
            }
        if(p[i4].x<maxx1&&p[i4].x>minx1&&p[i4].y<maxy1&&p[i4].x>miny1)
        {

            all++;
        }
        if(ison(i4,maxx1,minx1,maxy1,miny1))
            {
                touchin = 1;
            }
        if(p[q3].x<maxx1&&p[q3].x>minx1&&p[q3].y<maxy1&&p[q3].x>miny1)
        {

            all++;
        }
        if(ison(q3,maxx1,minx1,maxy1,miny1))
            {
                touchin = 1;
            }
        if(p[q4].x<maxx1&&p[q4].x>minx1&&p[q4].y<maxy1&&p[q4].x>miny1)
        {

            all++;
        }
        if(ison(q4,maxx1,minx1,maxy1,miny1))
            {
                touchin = 1;
            }
//        puts("two");
//        printf("1111 %d %d %d %d\n",maxx1,minx1,maxy1,miny1);
//        printf("2222 %d %d %d %d\n",maxx2,minx2,maxy2,miny2);
//               puts("i1,i2,q1,q2,i3,i4,q3,q4");
//        printf("check%d %d %d %d %d %d %d %d \n",i1,i2,q1,q2,i3,i4,q3,q4);

        if(all == 4)
        {
//            printf("all  = 4");
            ans = (maxx1-minx1)*(maxy1-miny1);
            return ans;
        }
        else if(touchin == 0)
        {
            ans = (maxx1-minx1)*(maxy1-miny1)+(maxx2-minx2)*(maxy2-miny2);

//            printf("++++%d %d\n",(maxx1-minx1)*(maxy1-miny1),(maxx2-minx2)*(maxy2-miny2));
            return ans;
        }
        else
        {
            return 0;
        }
    }

}
void see()
{
    for(int i = 0;i < 5;i++)
    for(int j = 0;j < 5;j++)
    {
        printf("map %d %d = %d\n",i,j,map[i][j]);
    }

}
int main()
{

    int n;
    while(scanf("%d",&n),n)
    {
        memset(map,0,sizeof(map));
        ans = 0;

        for(int i = 1;i<=n;i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
            map[p[i].x][p[i].y] = i;
        }
        if(n<8)
        {
            printf("imp\n");
            continue;
        }
//        see();
        int q1,q2,q3,q4;
        for(int i1 = 1;i1 <= n;i1++)
        {
            for(int i2 = i1+1;i2 <= n;i2++)
            {
                if(p[i1].x==p[i2].x||p[i1].y==p[i2].y)
                {
                    continue;
                }
                if(map[p[i1].x][p[i2].y]&&map[p[i2].x][p[i1].y])
                {
                    q1 = map[p[i1].x][p[i2].y];
                    q2 = map[p[i2].x][p[i1].y];

                    for(int i3 = 1;i3 <= n;i3++)
                    {
                        if(i1==i3||i2==i3||q1==i3||q2==i3)
                        {
                            continue;
                        }
                        for(int i4 = i3+1;i4 <= n;i4++)
                        {
                            if(p[i3].x==p[i4].x||p[i3].y==p[i4].y||
                                i1==i4||i2==i4||q1==i4||q2==i4)
                            {
                                continue;
                            }
                             if(map[p[i3].x][p[i4].y]&&map[p[i4].x][p[i3].y])
                            {
                                q3 = map[p[i3].x][p[i4].y];
                                q4 = map[p[i4].x][p[i3].y];
                                int now = check(i1,i2,q1,q2,i3,i4,q3,q4);
                                if(now>ans)
                                {
                                    ans = now;
//printf("              check%d %d %d %d %d %d %d %d \n",i1,i2,q1,q2,i3,i4,q3,q4);

                                }
                            }
                        }
                    }
                }
            }
        }
        if(ans)
            printf("%d\n",ans);
        else
            printf("imp\n");
    }

}

