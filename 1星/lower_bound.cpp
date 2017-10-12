#include<bits/stdc++.h>

using namespace std;
/*

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0











*/
int main()
{
	int n,q;
	int a[100100];
	int c[100100];
	
	int b[] = {1,1,1,2,3,3,4,4,4};
		
		{
			int l,r,ln,rn;
			
			ln = lower_bound(b,b+9,4)-b;
			rn = upper_bound(b,b+9,4)-b-1;
			printf("%d %d\n",ln,rn);
			
		}
		
	




 return 0;
}


