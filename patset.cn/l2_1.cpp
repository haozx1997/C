#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;


struct st
{
	int nn;
	double num;
	int out,in;
	int luck;
}pp[1010];



int cmp(const void *a,const void *b)
{
	struct st *c = (st *)a; 
	struct st *d = (st *)b; 
	if(c->in != d->in) return d->in - c->in ; 
	else if(c->luck != d->luck) return d->luck- c->luck  ; 
	else return  d->nn -   c->nn  ;

}

int main()

{
	memset(pp,0,sizeof(pp));
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		int k,sum=0;
		int ppn,ppin;
		scanf("%d",&k);
		for(int ii = 0; ii<k;ii++)
		{
			scanf("%d%d",&ppn,&ppin);
			ppn--;
			sum+=ppin;
			pp[ppn].luck++;
			pp[ppn].in+=ppin;
			
		}
		pp[i].out+=sum;
		pp[i].nn = i+1;
		
	}
	for(int i =0;i<n;i++)
	{
		pp[i].in-=pp[i].out;
		pp[i].num  = (double)pp[i].in/100;
		
	}
	
	qsort(pp,n,sizeof(pp[0]),cmp);
	for(int i = 0;i<n;i++)
	{
		
		printf("%d %.2f\n",pp[i].nn,pp[i].num );
	}
	
}
