#include<bits/stdc++.h>

using namespace std;

int main()
{
	double l,v1,v2,t1,t2,l2;
	int n,k;
	while(~scanf("%d%lf%lf%lf%d",&n,&l,&v1,&v2,&k))
	{
		int ti = ceil((double)n/k);
		if(ti == 1)
		{
			printf("%.12f\n",(double)l/v2);
			continue;
		}
		ti--;
		l2 = (l*(v1+v2)*v2)/(ti*2*v1*v2+v2*(v1+v2));
		t2 = l2/v2;
		t1 = (l-l2)/v1;
		printf("%.12f\n",(double)t1+t2);
		
	}




 return 0;
}

/*
5 10 1 2 5
3 6 1 2 1
39 252 51 98 26




*/
