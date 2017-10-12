#include<stdio.h>
#define ll long long

ll tim(char c)  
{  
    if(c=='f')  
    return 1;  
    if(c=='e')  
    return 2;  
    if(c=='d')  
    return 3;  
    if(c=='a')  
    return 4;  
    if(c=='b')  
    return 5;  
    if(c=='c')  
    return 6;  
} 

int main()
{
	ll n;
	char s[20];
	while(~scanf("%I64d%s",&n,&s))
	{
		ll walk = (n-1)/4;
		ll set = n%4;
		set = set ? set : 4;
		ll time = walk*(12+4);
		if(!(set%2))
		{
			time += 7;
		}
		time += tim(s[0]);
		printf("%I64d\n",time);
	}
 } 
