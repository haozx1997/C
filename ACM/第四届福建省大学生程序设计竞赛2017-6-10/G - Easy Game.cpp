#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{	
	int T;
	scanf("%d",&T);
	for(int II = 0;II < T;II++)
	{
		char s[1000];
		scanf("%s",s);
		
		if(!(strlen(s)%2))
		{
			printf("Case %d: Even\n",II+1);
		}
		else
		{
			printf("Case %d: Odd\n",II+1);
		}
	}





 return 0;
}


