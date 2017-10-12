#include<stdio.h>
long A(int n)
{

	if (n == 1 || n == 0)
		n = 1;
	else
		n = n*A(n - 1);
	return n;

}
long C(int m, int n)
{  //C(n,m)=n!/m!(n-m)!
	long  a, b, c;
	a = A(n); printf("     %d£¡=%d ",n, A(n));
	b = A(m); printf("%d£¡=%d ",m,A(m));
	c = A(n - m); printf("(%d-%d)£¡=%d\n",n,m ,A(n-m));

	return a / (b*c);
}
int main()
{  //C(0,N)+C(1,N)C(2,N)......C(N,N)
	int i, a;
	long  b, s = 0;
	scanf("%d", &a);
	for (i = 0; i <= a; i++)
	{
		b = C(i, a);
		s = s + b;
		printf("C(%d,%d)=%d\n ", i, a, b);
	}
	printf("\ns=%d", s);

	return 0;
}

