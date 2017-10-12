#include<stdio.h>
#include<stdlib.h>
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
	filep=fopen("g:\\file\\file2.txt","rb");
	for(i=0;i<5;i++)
	{
		fread(&stud[i],sizeof(struct student),1,filep);
		printf("%4d%10s%8d%8d%8d     %.2f\n",stud[i].num,stud[i].name,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].average);
	    
	}
	fclose(filep);
}

int cmp( const void *a , const void *b ) 
{ 
struct student *c = (student *)a; 
struct student *d = (student *)b; 
if(c->average != d->average) return d->average - c->average; 
else return c->name - d->name; 
} 

int main()
{
	int i;
	
	printf("NO.       name    score1  score2  score3  averaga\n");
	
	saveinfor();
	getchar();
	qsort(stud,5,sizeof(stud[0]),cmp);
		for(i=0;i<5;i++)
	{
		
		printf("%4d%10s%8d%8d%8d     %.2f\n",stud[i].num,stud[i].name,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].average);
	    
	}
	return 0;
}

