#include<stdio.h>

int plist[10010],pcount=0;

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++)
		if (!(n%plist[i]))
			return 0;
	return n>1;
}

void initprime(){
	int i;
	for (plist[pcount++]=2,i=3;i<5000000;i++)
		if (prime(i))
			plist[pcount++]=i;
}

int main()
{
	initprime();
	printf("%d\n",sizeof(plist));
	getchar();
	for(int i = 0;i < 10000;i++)
	{
		printf("%d %d\n",i,plist[i]);
		if(!(i%100))
		 getchar();
	}
}
