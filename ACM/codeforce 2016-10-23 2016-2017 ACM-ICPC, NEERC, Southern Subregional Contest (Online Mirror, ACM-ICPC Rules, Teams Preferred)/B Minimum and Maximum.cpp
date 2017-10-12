#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

int maxx[200];
int minx[200];
int the[10];
int thn = 0;
char res[5];
int nowx;
int nown;

void domax()
{
	for(int i = 1;i < nowx;i+=2)
	{
		printf("? %d %d\n",maxx[i],maxx[i+1]);thn++;
		fflush(stdout);
		scanf("%s",res);
		if(strcmp("<", res) == 0)
		{
			maxx[(i+1)/2] = maxx[i+1];
			
		}
		else if(strcmp(">", res) == 0)
		{
			maxx[(i+1)/2] = maxx[i];
		}
		else if(strcmp("=", res) == 0)
		{
			maxx[(i+1)/2] = maxx[i+1];
		}
	}
	
	if(nowx%2)
	{
		maxx[(nowx+1)/2] = maxx[nowx];
	}
	nowx = (nowx+1)/2;
}

void domin()
{
	for(int i = 1;i < nown;i+=2)
	{
		printf("? %d %d\n",minx[i],minx[i+1]);thn++;
		fflush(stdout);
		scanf("%s",res);
		if(strcmp(">", res) == 0)
		{
			minx[(i+1)/2] = minx[i+1];
			
		}
		else if(strcmp("<", res) == 0)
		{
			minx[(i+1)/2] = minx[i];
		}
		else if(strcmp("=", res) == 0)
		{
			minx[(i+1)/2] = minx[i+1];
		}
	}
	
	if(nown%2)
	{
		minx[(nown+1)/2] = minx[nown];
	}
	nown = (nown+1)/2;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int n;
		
		scanf("%d",&n);
		nown = n;
		for(int i = 1 ; i <= n;i++)
		{
			maxx[i] = minx[i] = i;
		}
		for(int i = 1 ; i < n;i+=2)
		{
			printf("? %d %d\n",maxx[i],maxx[i+1]);thn++;
			fflush(stdout);
			scanf("%s",res);
			if(strcmp("<", res) == 0)
			{
				maxx[(i+1)/2] = maxx[i+1];
				minx[(i+1)/2] = minx[i];
				
			}
			else if(strcmp(">", res) == 0)
			{
				maxx[(i+1)/2] = maxx[i];
				minx[(i+1)/2] = minx[i+1];				
			}
			else if(strcmp("=", res) == 0)
			{
				maxx[(i+1)/2] = maxx[i+1];
				minx[(i+1)/2] = minx[i];				
			}
		}
		nown = (n+1)/2;
		nowx = nown;
		if(n%2)
		{
			maxx[nown]=minx[nown]=n;
		}
		while(1)
		{
			domax();
			domin();
			if(nowx == 1&&nown == 1)
			{
				break;
			}
		}
		printf("! %d %d\n",minx[1],maxx[1]);
		fflush(stdout);
	//	printf("%d %d\n\n",(int)ceil(n*3.0/2)-2,thn);
	}
}
