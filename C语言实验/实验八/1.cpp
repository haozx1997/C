#include<stdio.h>
struct student
{
	int num;
	char name[20] ;
	int score[3];
	double average;
 } ;
struct student stud[5];
int main()
{
	int i,j,sum;
	for(i=0;i<5;i++)
	  {
		scanf("%d%s%d%d%d",&stud[i].num,&stud[i].name,&stud[i].score[0],&stud[i].score[1],&stud[i].score[2]);
	  }
	for(i=0;i<6;i++)
	{
		for(sum=0,j=0;j<3;j++)
		    sum+=stud[i].score[j];
		stud[i].average=(double)sum/3;
	}
	printf("NO.       name    score1  score2  score3  averaga\n");
	for(i=0;i<5;i++)
	{
		printf("%4d%10s%8d%8d%8d     %.2f\n",stud[i].num,stud[i].name,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].average);
	}
	return 0;

}
