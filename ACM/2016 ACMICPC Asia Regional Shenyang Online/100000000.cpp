#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define ll long long 
using namespace std;
int main()
{ll CompositeNumFilterV3(ll);
 ll m,c;
 scanf("%I64d",&m);
 c=CompositeNumFilterV3(m);
 printf("%I64d\n",c);
return 0;
}//�������ĳ���
ll CompositeNumFilterV3(ll n)
{ 
 ll  i, j; 
 //��������ͳ��
 ll  count = 0; 
 // ����������ǿռ䣬����+1ԭ���˰ɣ���Ϊ�˷���һ��flag[0] 
 char* flag = (char*)malloc( n+1 ); 
 // �����õģ�����ϸ�о����� 
 ll  mpLen = 2*3*5*7*11*13; 
 char magicPattern[2*3*5*7*11*13]; // ��ֵĴ��룬why��˼���޷����ͣ��룡  
 for (i=0; i<mpLen; i++)
 {
  magicPattern[i++] = 1;  
  magicPattern[i++] = 0;  
  magicPattern[i++] = 0;  
  magicPattern[i++] = 0;  
  magicPattern[i++] = 1;  
  magicPattern[i] = 0; 
 } 
 for (i=4; i<=mpLen; i+=5)  
  magicPattern[i] = 0; 
 for (i=6; i<=mpLen; i+=7)  
  magicPattern[i] = 0; 
 for (i=10; i<=mpLen; i+=11)  
  magicPattern[i] = 0; 
 for (i=12; i<=mpLen; i+=13)  
  magicPattern[i] = 0;  // �µĳ�ʼ������,��2,3,5,7,11,13�ı���ȫ�ɵ� 
  // ���Ҳ���memcpy��mpLen����magicPattern����������  
 ll  remainder = n%mpLen; 
 char* p = flag+1; 
 char* pstop = p+n-remainder; 
 while (p < pstop) 
 {  
  memcpy(p, magicPattern, mpLen);  
  p += mpLen; 
 }
  if (remainder > 0) 
  {  
   memcpy(p, magicPattern, remainder); 
  } 
  flag[2] = 1; 
  flag[3] = 1; 
  flag[5] = 1; 
  flag[7] = 1; 
  flag[11] = 1; 
  flag[13] = 1;    // ��17��ʼfilter����Ϊ2,3,5,7,11,13�ı����类kill��  
  // ��n/13ֹ�ģ����������˺ö�� 
  ll  stop = n/13; 
  for (i=17; i <= stop; i++) 
  {  
   // i�Ǻ�������Ъ�Űɣ���Ϊ���Ĺ����������������Ӵ�����   
  if (0 == flag[i]) continue;    
  // ��i��17����ʼ����  
  ll  step = i*2;  
  for (j=i*17; j <= n; j+=step)  
  {   
  flag[j] = 0;  
  } 
  }  
  
  // ͳ���������� 
  for (i=2; i<=n; i++) 
  {  
   if (flag[i]) count++; 
  }   
  
  // �������ʱ���Һ��㷨������ز��󣬹���   
  // �ͷ��ڴ棬�����˴�˵�е��ڴ�й©  
  free(flag);  
  
  return count;
}
