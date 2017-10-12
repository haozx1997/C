/*
5
i qwe
i qwe
i wer
i ert
i erty

*/

#include<stdio.h>
#include<string.h>
#include<iostream> 
#include<set> 
#include <string>;
using namespace std;
//std::set<std::string> S;



set<string>::const_iterator it;
char ord[10];
char word[50];
set<string> S;
void i()
{
	S.insert(word);	
	
}



void d()
{
	
}

void s()
{
	
}

int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{

		scanf("%s",ord);
		scanf("%s",word);
		
		switch(ord[0])
		{
			case 'i':i();break;
			case 'd':d();break;
			case 's':s();break;
			
		}
		
	}
	it = S.begin();
	//const char *c_str();
//	char c[20];
//strcpy(c,S.begin().c_str());
	printf("##%S\n",S.begin());
	char a[10];
	
	//a=it;
	printf("$$%d\n",a);
	   
    for(it=S.begin();it!=S.end();it++) 
    {
//    	printf("@%s\n",*it);
	
	cout<<*it<<endl;
	}
 } 
