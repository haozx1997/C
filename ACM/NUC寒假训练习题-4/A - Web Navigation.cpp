#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
struct url
{
	char ur[100];
};

int main()
{
	char com[10];
    int f=1;
	stack<url> s1,s2;
	struct url a={"http://www.acm.org/"};
	s1.push(a);

    while(f)
    {
	    scanf("%s",&com);
     	switch(com[0])
	      {
		       case 'V':scanf("%s",a.ur);s1.push(a);a=s1.top();printf("%s\n",a.ur);
			                while(!s2.empty()) s2.pop();
			                break;
		       case 'B' :s2.push(s1.top());s1.pop();
			                 if(s1.empty()) 
			                  {
			                    	printf("Ignored\n");
			                    	url a={"http://www.acm.org/"};
			                    	s1.push(a);
			                    	s2.pop();
							  }
			                 else
							  {
			                 	a=s1.top();printf("%s\n",a.ur);
							  }
			                 
							 break;
		       case 'F':
			                  if(s2.empty()) printf("Ignored\n");
			                  else
			                  {
			                  	s1.push(s2.top());s2.pop();
			                  	a=s1.top();printf("%s\n",a.ur);
							  }
							  break;
		       case 'Q' :f=0;break;
	      }    	
	      
	}

}
