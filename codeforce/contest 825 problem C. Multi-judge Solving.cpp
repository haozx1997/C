#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k,ans;
	int a,aa[2000];
	int maxx = 0;
	int an;
	while(~scanf("%d%d",&n,&k))
	{
		ans = maxx = an = 0;
		for(int i = 0; i < n;i++)
		{
			scanf("%d",&a);
			if(a<=k)
			{
				maxx = max(a,maxx);
			}
			else
			{
				aa[an++] = a;
			}
		}
		aa[an++] = maxx;
		
		sort(aa,aa+an);
//		for(int i = 0 ;i < an;i++)
//		{
//			printf("%d ",aa[i]);
//		}
//		printf("\n");
		k *= 2;
		for(ans = 0;;ans++)
		{
			if(k>aa[0])
			{
				break;
			}
			k *= 2;
		}
		
		k = max(aa[0]*2,k);
		int i = 0;
		while(k < aa[an-1])
		{
	//		puts("wtf");
		
			int g = upper_bound(aa+i,aa+an,k)-(aa)-1;
	//		printf("%d %d %d\n",i,g,k);	
			if(g == i)
			{
				while(k<aa[g+1])
				{
					k *= 2;
					ans++;
				}
			}
			else
			{
				i = g;
				k = max(aa[g]*2,k);
			}
		}
		printf("%d\n",ans);
		
		
		
		
	}




 return 0;
}

/*
1 1000000000
1

3 3
2 1 9

4 20
10 3 6 3

100 10
246 286 693 607 87 612 909 312 621 37 801 558 504 914 416 762 187 974 976 123 635 488 416 659 988 998 93 662 92 749 889 78 214 786 735 625 921 372 713 617 975 119 402 411 878 138 548 905 802 762 940 336 529 373 745 835 805 880 816 94 166 114 475 699 974 462 61 337 555 805 968 815 392 746 591 558 740 380 668 29 881 151 387 986 174 923 541 520 998 947 535 651 103 584 664 854 180 852 726 93

50 100
74 55 33 5 83 24 75 59 30 36 13 4 62 28 96 17 6 35 45 53 33 11 37 93 34 79 61 72 13 31 44 75 7 3 63 46 18 16 44 89 62 25 32 12 38 55 75 56 61 82

1 1
3

*/
