#include<stdio.h> 
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		if(b<a)
		swap(a,b);
		int k ;
		k = b - a;
		int a_ = (int)(k*(1.0+sqrt(5.0))/2);
		printf("%s\n",(a == a_) ? "B" : "A");
		
	}
}
