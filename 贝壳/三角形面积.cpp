#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
 double a,b,c,t,p,s;
 printf("���������ߵĳ���\n");
 scanf("%lf,%lf,%lf", &a, &b, &c);
 if (a > b) t = a, a = b, b = t;
 if (b > c) {
	 t = b, b = c, c = b;
	 if (a > b) t = a, a = b, b = t;
            }
 if((a+b)>c)
 {
 printf("�ܹ��������� \n");    
 p=(a+b+c)/2;
 s=sqrt(p*(p-a)*(p-b)*(p-c));
 printf("��� s=%.3f\n",s);
 }
 else printf("���ܹ���������\n");
 system("pause");
 return 0;
}

