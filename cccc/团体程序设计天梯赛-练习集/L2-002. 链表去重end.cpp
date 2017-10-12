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
}l[100010];

int head,num;
int hav[100010],h;
int ans1[100110],ans2[100010];
int a1,a2;
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
	
	int add,n,next;
	scanf("%d%d",&head,&num);
	for(int i = 0;i<num;i++)
	{
		
		scanf("%d%d%d",&add,&n,&next);
		l[add].n = n;
		l[add].next = next;
	}
	memset(hav,0,sizeof(hav));
	for(int i =  head;i != -1;i = l[i].next)
	{
		int t = abs(l[i].n);
		if(!hav[t])
		{
			ans1[a1++] = i;
			hav[t]++;
		}
		else
		{
			ans2[a2++] = i;
		}
	}
	prin(ans1[0]);
	printf(" %d ",l[ans1[0]].n);
	for(int i = 1;i < a1;i++)
	{
		prin(ans1[i]);
		printf("\n");
		prin(ans1[i]);
		printf(" %d ",l[ans1[i]].n);
		
	}
	printf("-1\n");
	
	if(a2)
	{
		prin(ans2[0]);
		printf(" %d ",l[ans2[0]]);
		for(int i = 1;i < a2;i++)
		{
			prin(ans2[i]);
			printf("\n");
			prin(ans2[i]);
			printf(" %d ",l[ans2[i]].n);
		
		}
		printf("-1\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
