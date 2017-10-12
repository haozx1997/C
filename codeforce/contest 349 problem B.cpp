#include<bits/stdc++.h>

using namespace std;
struct node
{
	int a,na,v;
}in[20];

int cmp(node aa,node b)
{
	if(aa.na == b.na)
	{
		return aa.a>b.a;
	}
	return aa.na>b.na;
}
int cmp1(node aa,node b)
{
	
	return aa.a<b.a;
}

int main()
{
	int n,now;
	
	
	
	while(~scanf("%d",&n))
	{
		node wtf ;
		wtf.v = 100000001;
		for(int i = 1; i < 10;i++)
		{
			scanf("%d",&in[i].v);
			in[i].a = i;
			in[i].na = n/in[i].v;
			if(in[i].v<wtf.v )
			{
				wtf = in[i];
			}
			else if((in[i].v==wtf.v )&&(in[i].a>wtf.a ))
			{
				wtf = in[i];
			}
		}
		
//		for(int i = 1; i < 10;i++)
//		{
//			printf("%d %d %d\n",in[i].a,in[i].na,in[i].v);
//		}
		
		if(wtf.na == 0)
		{
			printf("-1\n");
			continue;
		}
		if(n%wtf.v)
		{
			int len = wtf.na;
			sort(in+1,in+10,cmp1);
		//			for(int i = 1; i < 10;i++)
//		{
//			printf("%d %d %d\n",in[i].a,in[i].na,in[i].v);
//		}
			int sum = n;
			while(sum>0)
	        {  
	        //	printf("%d %d %d\n",wtf.v,len,sum);
	        	if(!len)
	        	{
	        		break;
				}
	            int x = 0;  
	            for(int i = 1; i<=9; i++)  
	            {  
	            	
	                int s = sum-in[i].v;
					 
	                if(s<0)
	                    continue;  
	                if(s/wtf.v== len-1 && x<i)
	                    x = i;  
	                    
	            }  
	            if(x)  
	            {  
	                sum-=in[x].v;
	                len--; 
	                printf("%d",x);
	            }  
	        }  
		}
		else
		{
			for(int i = 0; i < wtf.na;i++)
			{
				printf("%d",wtf.a);
			}
		}
		printf("\n");
		
	}




 return 0;
}
/*
100

1 3 4 5 5 5 6 7 7 


*/

