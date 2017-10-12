#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	int a[100100];
	scanf("%d",&T);
	while(T--)
	{
		int n,s;
		int sum = 0;
		scanf("%d%d",&n,&s);
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		if(sum<s)
		{
			printf("0\n");
			continue;
		}
		sum = 0;
		int h = 0;
		int t = 0;
		int ans = n+1;
		while(1)
		{
//			sum = 0;
//		//	printf("h %d  t %d\n",h,t);
//			
//			for(int i = h;i<t;i++)
//			{
//				sum += a[i];
//			}
//			if(t == n&&sum<s)
//			{
//				break;
//			}
//			if((t-n) == 1&&sum>=s)
//			{
//				break;
//			}
//			if(sum>=s)
//			{
//				if(min>(t-h))
//				{
//					min = (t-h);
//				}
//				h++;
//				continue;
//			}
//			if(sum<s)
//			{
//				t++;
//			}
			while(t < n && sum <= s)
					sum += a[t++];
				
				if(sum < s)	break;
					ans = min(t-h,ans);
					sum -= a[h++];
		}
		if(ans>n)
		{
			ans = 0;
		}
		printf("%d\n",ans);
	}
}
