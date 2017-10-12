#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
 double a,b,c,t,p,s;
 printf("请输入三边的长度\n");
 scanf("%lf,%lf,%lf", &a, &b, &c);
 if (a > b) t = a, a = b, b = t;
 if (b > c) {
	 t = b, b = c, c = b;
	 if (a > b) t = a, a = b, b = t;
            }
 if((a+b)>c)
 {
 printf("能构成三角形 \n");    
 p=(a+b+c)/2;
 s=sqrt(p*(p-a)*(p-b)*(p-c));
 printf("面积 s=%.3f\n",s);
 }
 else printf("不能构成三角形\n");
 system("pause");
 return 0;
}

