#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<map>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	std::map<string,int> ma;
	ma.insert(pair<string,int>("Cleveland Cavaliers",1));
	ma.insert(pair<string,int>("Golden State Warriors",2));
	ma.insert(pair<string,int>("San Antonio Spurs",5));
	ma.insert(pair<string,int>("Miami Heat",3));
	ma.insert(pair<string,int>("Dallas Mavericks",1));
	ma.insert(pair<string,int>("L.A. Lakers",11));
	ma.insert(pair<string,int>("Boston Celtics",17));
	ma.insert(pair<string,int>("Detroit Pistons",3));
	ma.insert(pair<string,int>("Chicago Bulls",6));
	ma.insert(pair<string,int>("Houston Rockets",2));
	ma.insert(pair<string,int>("Seattle Sonics",1));
	ma.insert(pair<string,int>("Washington Bullets",1));
	ma.insert(pair<string,int>("Portland Trail Blazers",1));
	ma.insert(pair<string,int>("New York Knicks",2));
	ma.insert(pair<string,int>("Milwaukee Bucks",1));
	ma.insert(pair<string,int>("Philadelphia 76ers",2));
	ma.insert(pair<string,int>("St. Louis Hawks",1));
	ma.insert(pair<string,int>("Philadelphia Warriors",2));
	ma.insert(pair<string,int>("Syracuse Nats",1));
	ma.insert(pair<string,int>("Minneapolis Lakers",5));
	ma.insert(pair<string,int>("Rochester Royals",1));
	ma.insert(pair<string,int>("Baltimore Bullets",1));
	std::map<std::string,int>::iterator it;
	
	getchar();
	for(int TT = 0;TT < T;TT++)
	{
		char ss[100];
		
		gets(ss);
		string s;
		s.assign(ss);
		
		it = ma.find(s);
		int ans;
		if(it!=ma.end())
		ans = it->second;
		else 
		ans = 0;
		printf("Case #%d: %d\n",TT+1,ans);
		
	}
}
