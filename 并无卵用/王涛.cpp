#include<stdio.h>
int main()
{
	char name[20];
	int a[20][5],i,j,sum,avep,avec,max,min,chu;
	printf("输入名字\n"); 
	for(i=0;i<20;i++)       //name[1-20]表示名字    qazwsxedcrfvtgbyhnuj 
	  scanf("%c",&name[i]);
	printf("输入成绩\n");
	for(i=0;i<20;i++)
	  for(j=0;j<5;j++)
	    scanf("%d",&a[i][j]);//输成绩 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
	printf("1 每人平均成绩\n 2 每科平均成绩\n 3 每科最高\n  4每科最低\n ");
	scanf("%d",&chu);
	printf("%d",chu);
	switch(chu)
 {
	case 1:
	{for(sum=0,i=0;i<20;i++)//每人平均成绩 
	 {
	  for(j=0;j<5;j++)
	  sum=sum+a[i][j];
	  printf("%c的平均成绩%d\n",name[i],sum/5);
     }};
     break;
     case 2:
    {for(sum=0,j=0;j<5;j++) //每科平均成绩
     {
     	for(i=0;i<20;i++)
     	sum=sum+a[i][j];
     	printf("此科平均成绩%d",sum/20);
	 }};
	 break;
	 case 3:
	 {for(max=0,j=0,i=0;j<5;j++) //每科最高 
     {
     	for(i=0;i<20;i++)
     	  {
     	  	if(max<a[i][j]) max=a[i][j];
		  }
     	printf("此科最高%d",max);
	 }
	 printf("\n");
	 for(min=0,j=0,i=0;j<5;j++) //每科最低
     {
     	for(i=0;i<20;i++)
     	  {
     	  	if(min>a[i][j]) min=a[i][j];
		  }
     	printf("此科最低%d",max);
	 }};
	 break;
	 case 4:
	{for(i=0;i<20;i++)//不及格 
	  for(j=0;j<5;j++)
	    if(a[i][j]<60) printf("%c不及格",name[i]);
	 };break;   
 }
} 
 
