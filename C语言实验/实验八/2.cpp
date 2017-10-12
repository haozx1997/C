#include<stdio.h>
struct student
{
	int num;
	char name[20] ;
	int score[3];
	double average;
 } ;
struct student stud[5];

void btos()
{
	int i,j,k;
	struct student t;
	for(i=0;i<4;i++)
	 {
	 	k=i;
	 	for(j=i+1;j<5;j++)
	 	  if(stud[j].average>stud[k].average)k=j;
	 	if(k!=i)
	 	  {
		    t=stud[i];stud[i]=stud[k];stud[k]=t;
		   }
     }
}

void openinfor()
{
	FILE*filep;
	int i;
	filep=fopen("s:\\file\\file1.txt","rb");
	printf("NO.       name    score1  score2  score3  averaga\n");
	for(i=0;i<5;i++)
	{
		fread(&stud[i],sizeof(struct student),1,filep);
		
	    printf("%4d%10s%8d%8d%8d     %.2f\n",stud[i].num,stud[i].name,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].average);
	    
	}
	fclose(filep);
}
void openinfor1()
{
	FILE*filep;
	int i;
	filep=fopen("s:\\file\\stuscore.dat","rb");
	printf("NO.       name    score1  score2  score3  averaga\n");
	for(i=0;i<5;i++)
	{
		fread(&stud[i],sizeof(struct student),1,filep);
		
	    printf("%4d%10s%8d%8d%8d     %.2f\n",stud[i].num,stud[i].name,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].average);
	    
	}
	fclose(filep);
}
void writeinfor()
{
	FILE *p;
	int i;
	if ((p=fopen("s:\\file\\stuscore.dat","wb"))==NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for(i=0;i<5;i++)
	if (fwrite(&stud[i],sizeof(struct student),1,p)!=1)
	{
		printf("file write error\n");
		getchar();
		return;
	}
	fclose(p);
}
int main()
{
	openinfor();//打开文件 
	btos();//排序 
	writeinfor();
	openinfor1();//打开新文件 
	getchar();
	return 0;
}
