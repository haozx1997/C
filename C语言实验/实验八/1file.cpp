#include<stdio.h>
struct student
{
	int num;
	char name[20] ;
	int score[3];
	double average;
 } ;
struct student stud[5];
void saveinfor()
{
	FILE *filep;
	int i;
	if ((filep=fopen("g:\\file\\file2.txt","wb"))==NULL)
    {
    	printf("cannot open file\n");
        return;
	}
	for(i=0;i<5;i++)
	 if (fwrite(&stud[i],sizeof(struct student),1,filep)!=1)
	  {
	  	printf("fille write error\n");
	  	getchar();
	  	return;
	  }
	fclose(filep);
	filep=fopen("g:\\file\\file2.txt","rb");
	for(i=0;i<5;i++)
	{
		fread(&stud[i],sizeof(struct student),1,filep);
		printf("%4d%10s%8d%8d%8d     %.2f\n",stud[i].num,stud[i].name,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].average);
	    
	}
	fclose(filep);
}
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
	saveinfor();
	getchar();
	return 0;

}
