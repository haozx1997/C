#include<bits/stdc++.h>

using namespace std;

int up[30] = 
{
	2 ,3, 5, 7, 11, 13, 17, 19, 23, 29,
	31, 37, 41, 43, 47, 53, 59, 61, 67, 71,73, 79, 83, 89, 97,
	101, 103, 107 
};

void trans(char a[],int aa[],int &an)
{
	int len = strlen(a);
	int d = 0;
	for(int i = 0;i < len;i++)
	{
		if(a[i] == ',')
		{
			d++;
			a[i] = '\0';
		}
	}
	 an = d;
	char* head = a;
	for(int i = 0;i<=d;i++)
	{
	//	printf("%d %d %s\n",d,an,head);
		sscanf(head,"%d",&aa[an--]);
		head+=(strlen(head)+1);
	}
	an = d+1;
	
	
}


int main()
{
	char a[100];
	char b[100];
	int aa[100];
	int bb[100];
	
	while(~scanf("%s%s",a,b))
	{
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		
		int lena = strlen(a);
		int lenb = strlen(b);
		if(lena<lenb)
		{
			swap(a,b);
			swap(lena,lenb);
		}
//		puts(a);
//		puts(b);
		int an,bn;
		trans(a,aa,an);
		trans(b,bb,bn);
		
		for(int i = 0;i<an;i++)
		{
			aa[i]+=bb[i];
		}
		
		for(int i = 0;i<an;i++)
		{
			aa[i+1] += (aa[i]/up[i]);
			aa[i] %= up[i]; 
		}
		if(aa[an]!=0)
		{
			an++;
		}
		for(int i = an-1;i>=0;i--)
		{
			if(aa[i] == 0)
			an--;
			else
			break;
		}
		for(int i = an-1;i>0;i--)
		{
			printf("%d,",aa[i]);
		}
		printf("%d\n",aa[0]);
		
		
//		printf("an %d\n",an);
//		for(int i = 0;i < an;i++)
//		{
//			printf("%d\n",aa[i]);
//		}
	}
}

