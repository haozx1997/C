#include<stdio.h>
int main()
{
	char name[20];
	int a[20][5],i,j,sum,avep,avec,max,min,chu;
	printf("��������\n"); 
	for(i=0;i<20;i++)       //name[1-20]��ʾ����    qazwsxedcrfvtgbyhnuj 
	  scanf("%c",&name[i]);
	printf("����ɼ�\n");
	for(i=0;i<20;i++)
	  for(j=0;j<5;j++)
	    scanf("%d",&a[i][j]);//��ɼ� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
	printf("1 ÿ��ƽ���ɼ�\n 2 ÿ��ƽ���ɼ�\n 3 ÿ�����\n  4ÿ�����\n ");
	scanf("%d",&chu);
	printf("%d",chu);
	switch(chu)
 {
	case 1:
	{for(sum=0,i=0;i<20;i++)//ÿ��ƽ���ɼ� 
	 {
	  for(j=0;j<5;j++)
	  sum=sum+a[i][j];
	  printf("%c��ƽ���ɼ�%d\n",name[i],sum/5);
     }};
     break;
     case 2:
    {for(sum=0,j=0;j<5;j++) //ÿ��ƽ���ɼ�
     {
     	for(i=0;i<20;i++)
     	sum=sum+a[i][j];
     	printf("�˿�ƽ���ɼ�%d",sum/20);
	 }};
	 break;
	 case 3:
	 {for(max=0,j=0,i=0;j<5;j++) //ÿ����� 
     {
     	for(i=0;i<20;i++)
     	  {
     	  	if(max<a[i][j]) max=a[i][j];
		  }
     	printf("�˿����%d",max);
	 }
	 printf("\n");
	 for(min=0,j=0,i=0;j<5;j++) //ÿ�����
     {
     	for(i=0;i<20;i++)
     	  {
     	  	if(min>a[i][j]) min=a[i][j];
		  }
     	printf("�˿����%d",max);
	 }};
	 break;
	 case 4:
	{for(i=0;i<20;i++)//������ 
	  for(j=0;j<5;j++)
	    if(a[i][j]<60) printf("%c������",name[i]);
	 };break;   
 }
} 
 
