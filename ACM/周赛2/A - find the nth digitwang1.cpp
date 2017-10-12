#include <iostream>
#include <math.h>
using namespace std;

int main(){
int n;
double m;
double i,j;
unsigned long k;
scanf("%d",&n);
while(n--){
   scanf("%lf",&m);

   i = ceil((sqrt(1+8*m)-1)/2);

   k =m - i*(i-1)/2;
    
   if (k%9==0)
   {
    printf("9\n");
   }else{
    printf("%ld\n",k%9);
   }
}
return 0;
}
