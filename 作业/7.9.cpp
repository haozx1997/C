#include<stdio.h>
#include<string.h>
main()
{   //����һ���ַ������ж����ǲ��ǻ���//
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
	
	
