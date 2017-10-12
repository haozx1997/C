#include<stdio.h>
#include<string.h> 

int tree[15][1000];
int trn[] = {1,3,7,15,31,63,127,255,511,1023};
int trhn[] = {1,2,4,8,16,32,64,128,256,512,1024};
int all_h;
void see();


int cmp(int h,int l)
{
	int t ;
	if(tree[h][l]==1000000)
	 return 0;
//	printf("%d %d %d\n",h,l,tree[h][l]);
	if(tree[h][l]>tree[h+1][(l+1)*2-2])
	{
		
		t = tree[h][l];
		tree[h][l] = tree[h+1][(l+1)*2-2];
		tree[h+1][(l+1)*2-2] = t;
	}
	if(tree[h][l]>tree[h+1][(l+1)*2-1])
	{
		t = tree[h][l];
		tree[h][l] = tree[h+1][(l+1)*2-1];
		tree[h+1][(l+1)*2-1] = t;
	}
	cmp(h+1,(l+1)*2-2);
	cmp(h+1,(l+1)*2-1);
	
	
}

void see()
{
	printf("************\n");
		for(int i = 0;i<=all_h;i++)
		{
			for(int j = 0;j<trhn[i];j++)
			{
				printf("%d ",tree[i][j]);
			}
			printf("\n");
		}
			printf("************\n");

}

int ans1,ans2;
void find(int asd)
{
	for(int i = 0;i<=all_h;i++)
		{
			for(int j = 0;j<trhn[i];j++)
			{
				if(tree[i][j] == asd)
				 {
				 	ans1 = i;
				 	ans2 = j;
				 	return;
				 }
			}
			
		}
}
void one(int q)
{
	if(q == tree[0][0])
	 printf("T\n");
	else 
	 printf("F\n"); 
}

void two(int q1,int q2)
{
	find(q1);
	if(ans2%2)
	{
		if(tree[ans1][ans2-1] == q2)
		{
			printf("T\n");
		}
		else
		{
			printf("F\n");
		}
	}
	else
	{
		if(tree[ans1][ans2+1] == q2)
		{
			printf("T\n");
		}
		else
		{
			printf("F\n");
		}
	}
}

void three(int q1,int q2)
{
	find(q1);
	if(tree[ans1+1][(ans2+1)*2-2] == q2||tree[ans1+1][(ans2+1)*2-1] == q2)
	 {
			printf("T\n");
		}
		else
		{
			printf("F\n");
		}
}

void four(int q2,int q1)
{
	find(q1);
	if(tree[ans1+1][(ans2+1)*2-2] == q2||tree[ans1+1][(ans2+1)*2-1] == q2)
	 {
			printf("T\n");
		}
		else
		{
			printf("F\n");
		}
}



int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int qn;
		scanf("%d",&qn);
		
		for(all_h = 0;all_h<11;all_h++)
		{
			if(n<=trn[all_h])
			 break;
		}
		int endh = n - trn[all_h-1];
	//	printf("%d\n",all_h);
		for(int i = 0;i<all_h;i++)
		{
			for(int j = 0;j<trhn[i];j++)
			{
				scanf("%d",&tree[i][j]);
			}
		}
		for(int j = 0;j<endh;j++)
			{
				scanf("%d",&tree[all_h][j]);
			}
		for(int j = endh;j<trhn[all_h];j++)
			{
				tree[all_h][j] = 1000000;
			}
		for(int j = 0;j<trhn[all_h+1];j++)
			{
				tree[all_h+1][j] = 1000000;
			}
				
			
//		for(int i = 0;i<=all_h+1;i++)
//		{
//			for(int j = 0;j<trhn[i];j++)
//			{
//				printf("%3d %3d %3d ",i,j,tree[i][j]);
//			}
//			printf("\n");
//		}
		for(int i = 0;i<=all_h;i++)
		{
			cmp(0,0);
			
		}
		

		
		while(qn--)
		{
			int q1,q2;
			char qs[10][10];
			scanf("%d",&q1);
			scanf("%s",qs[0]);
			if(qs[0][0] == 'a')
			{
				scanf("%d",&q2);
				scanf("%s",qs[1]);
				scanf("%s",qs[1]);
				two(q1,q2);
				continue;
			}
			scanf("%s",qs[1]);
			scanf("%s",qs[2]);
			switch(qs[2][0])
			{
				case 'r' :
					one(q1);
					break;
				case 'p' :
					
					scanf("%s",qs[3]);
					scanf("%d",&q2);
					three(q1,q2);
					break;
				case 'c' :
					
					scanf("%s",qs[3]);
					scanf("%d",&q2);
					four(q1,q2);
					break;
				
			}
			
		}
		
	}
}
