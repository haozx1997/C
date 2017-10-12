#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#include<set>
#include<math.h>
 
int er[] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
using namespace std;

int main()
{
	int k,w;
	while(~scanf("%d%d",&k,&w))
	{
		k++;
		int i;
		for( i = 11;i>=0;i--)
		{
			if(er[i]<k)
			{
				break;
			}
		}
		printf("iiiiii  %d\n",i);
		int ban = k/2;
		int sum = (ban+1)*(i+1);
		sum += ban*i;
		printf("%d %d %d\n",ban*(i+1),(ban+1)*i,sum);
		double ans = (double)sum/k;
		printf("%.6f\n",ans);
	}
	
}
