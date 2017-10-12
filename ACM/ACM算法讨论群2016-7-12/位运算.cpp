#include<stdio.h>

int main()
{
	int ans =7 ^6;
	printf("%d\n",ans);
	
	ans = ans |5;
	printf("%d\n",ans);
	ans = ans & 10;
	printf("%d\n",ans);
    printf("!%d\n",((10&5)|6)^7);
    printf("!%d\n",((5&10)|6)^7);
    printf("!%d\n",((6|5&10))^7);
    printf("!%d\n",7^((6|5&10)));
    printf("!%d\n",7^6|5&10);
	printf("!%d\n",((7^6)|5)&10);
//	printf("%d\n",10&5);
//	printf("%d\n",5&10);
//	printf("%d\n",10|5);
//	printf("%d\n",5|10);
//	printf("%d\n",10^5);
//	printf("%d\n",5^10);
	printf("%d\n",(((((12&12)|6454)^654)&564)|56)^123);
	printf("%d\n",123^56|564&654^6454|12&12);
		
}
