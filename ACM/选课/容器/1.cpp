#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	
	while(T--)
	{
		stack<int> S;
		char a[2000];
		gets(a);
		
		int F=0;
	
		for(int i=0;i<strlen(a);i++) 
		 {
		 	if(a[i]=='(')
		 	 S.push(1);
		 	if(a[i]=='[')
		 	 S.push(2);		 	 
		 	if(a[i]==')')
		 	 {
		 	 	if(S.empty()){F=1;break;}
		 	 	if(S.top()==1)
		 	 	S.pop();
			  }
		 	if(a[i]==']')
		 	 {
		 	 	if(S.empty()){F=1;break;}
		 	 	if(S.top()==2)
		 	 	S.pop();
			  }	
			  		  
		 }
		 if(F)
		 {
		 	printf("No\n"); continue;
		 }
		 if(S.empty())
		  printf("Yes\n");
		 else 
		  printf("No\n"); 
		  
	}
 } 
