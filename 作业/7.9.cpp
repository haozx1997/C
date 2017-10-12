#include<stdio.h>
#include<string.h>
main()
{   //输入一个字符串，判断它是不是回文//
	char a[1024];
	int i,j,d=0;
	scanf("%s",&a);
	j=strlen(a)-1;
	for(i=0;i<j;i++,j--)
	    d=d+(a[i]==a[j]);
	if(d==(strlen(a)/2))
	    printf("YES");
	else
	    printf("NO");
	return 0;
}
	
	
