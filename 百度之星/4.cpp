#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n;
	multiset<string> v;
	scanf("%d",&n);
	char name[50];
	while(n--)
	{
		scanf("%s",name);
		sort(name,name+strlen(name));
		v.insert(name);
		int num = 0;
		num = count(v.begin(),v.end(),name);
		printf("%d\n",num-1);
	}
 } 
