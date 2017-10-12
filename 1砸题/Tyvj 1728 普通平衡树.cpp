#include<bits/stdc++.h>

using namespace std;

vector<int>s; 
vector<int>::iterator it; 

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			int op,nn;
			scanf("%d%d",&op,&nn);
			switch(op)
			{
				
				case 1:
					s.insert(lower_bound(s.begin(),s.end(),nn),nn);
					break;
				case 2:
					it = lower_bound(s.begin(),s.end(),nn);
					s.erase(it);
					break;
				case 3:
					it = lower_bound(s.begin(),s.end(),nn);
					printf("%d\n",it - s.begin()+1);
					break;
				case 4:
//					it = s.begin();
//					for(int i = 1;i<nn;i++)
//					{
//						it++;
//					}
					printf("%d\n",s[--nn]);
					//printf("	%d\n",*it);
					
					break;
				case 5:
					it = lower_bound(s.begin(),s.end(),nn);
					printf("%d\n",*(--it));
					break;
				case 6:
					it = upper_bound(s.begin(),s.end(),nn);
					printf("%d\n",*(it));
					break;
					
				
				
			}
			
			
			
			
		}
		
		
	}




 return 0;
}


