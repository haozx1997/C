#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int N;
char name[50];
map<string, int>TM;
int main()
{
    
    TM.clear();
    scanf("%d", &N);
    for(int i = 0;i < N;i ++)
	{
        scanf("%s",name);
        sort(name, name + strlen(name));
        if(!TM[string(name)]) 
		    TM[string(name)] = 0;
        printf("%d\n", TM[string(name)]);
        TM[string(name)] ++;
    }

    return 0;
}
