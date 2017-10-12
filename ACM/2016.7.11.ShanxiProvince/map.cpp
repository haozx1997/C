#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;


int main()
{
	map<int,string>mm;
	mm.insert(pair<int,string>(159,"Tom"));
	mm.insert(pair<int,string>(170,"Mike"));
	mm.insert(pair<int,string>(168,"Eva"));
	mm.insert(pair<int,string>(160,"Qwe"));
	mm.insert(pair<int,string>(190,"Asd"));
	mm.erase(159);
	mm.insert(pair<int,string>(168,"Zxc"));
	mm.insert(pair<int,string>(175,"Wer"));
	mm.insert(pair<int,string>(186,"Sdf"));
	mm.insert(pair<int,string>(159,"Xcv"));
	map<int,string>::iterator it;
	for(it = mm.begin();it != mm.end();it++)
	{
		cout<<(*it).first<<"  "<<(*it).second<<endl;
	}
}

