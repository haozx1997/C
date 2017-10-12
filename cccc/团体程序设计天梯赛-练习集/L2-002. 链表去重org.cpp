#include<stdio.h>
#include<string.h>
int abs(int a)
{
	a<0? a=-a:a=a;
	return a;
}
struct line
{
	int n;
	int next;
	int pr;
}l[100010];

int head,num;
int rbs[100010],r;
void prin(int aa)
{
	if(aa == -1)
	 {
	 	printf("-1");
	 	return;
	 }
	char a[6]={"00000"};
	a[4] = '0'+aa%10;aa/=10;
	a[3] = '0'+aa%10;aa/=10;
	a[2] = '0'+aa%10;aa/=10;
	a[1] = '0'+aa%10;aa/=10;
	a[0] = '0'+aa%10;
	printf("%s",a);
}
int main()
{
	r = 0;
	int add,n,next;
	int pr = 0;
	scanf("%d%d",&head,&num);
	for(int i = 0;i<num;i++)
	{
		
		scanf("%d%d%d",&add,&n,&next);
		l[add].n = n;
		l[add].next = next;
		
		
	}
	int h = head;
	for(int i = 0;i<num;i++)
	{
		l[l[h].next].pr = h;
		//printf("%5d %5d %5d %5d\n",l[h].pr,h,l[h].n,l[h].next);
		h = l[h].next;
		
	}
	l[head].pr = -2;
	
	h = head;
	int path[10010];
	for(int i = 0;i<num;i++)
	{
		path[i] = l[h].n;
		for(int j = 0;j<i;j++)
		{
			if(abs(l[h].n)==abs(path[j]))
			{
				rbs[r++] = h;//printf("\n!!!%d %d\n",l[l[h].pr].next,l[h].next);
				l[l[h].pr].next = l[h].next;
				
			}
		}
		h = l[h].next;
	}
	h = head;
	for(int i = 0;i<num;i++)
	{
		l[l[h].next].pr = h;
		//printf("%5d %5d %5d %5d\n",l[h].pr,h,l[h].n,l[h].next);
		prin(h);
		printf(" ");
		printf("%d",l[h].n);
		printf(" ");
		prin(l[h].next);
		printf("\n");
		if(l[h].next == -1)
		 break;
		 h = l[h].next;
	}
	//printf("\n\n\n");
	prin(rbs[0]);
	printf(" %d ",l[rbs[0]].n);
	for(int i = 1;i<r-1;i++)
	 {
	 	//printf("%5d\n%5d %5d ",rbs[i],rbs[i],l[rbs[i]].n);
	 	prin(rbs[i]);
	 	printf("\n");
	 	prin(rbs[i]);
	 	printf(" %d ",l[rbs[i]].n);
	 }
	 printf("-1\n");
	
	
	
	
}
