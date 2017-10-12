#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10
#define MAXN 100000
struct Student{	
int no;
	char name[LEN];
	int grade;}stu[MAXN];
int sortByNo(const void *a,const void *b)
{	struct Student *aa=(struct Student *)a;
	struct Student *bb=(struct Student *)b;
	return aa->no-bb->no;}
int sortByName(const void *a,const void *b){
	struct Student *aa=(struct Student *)a;
	struct Student *bb=(struct Student *)b;	if(strcmp(aa->name,bb->name)){
		return strcmp(aa->name,bb->name);	}
	else{
		return aa->no-bb->no;	}}
int sortByGrade(const void *a,const void *b){
	struct Student *aa=(struct Student *)a;
	struct Student *bb=(struct Student *)b;
	if(aa->grade-bb->grade){
		return aa->grade-bb->grade;
	}
	else{
		return aa->no-bb->no;	}}
int display(int n,struct Student stu[]){
	int i;	for(i=0;i<n;i++){			printf("%06d %s %d/n",stu[i].no,stu[i].name,stu[i].grade);	}}
int main(int argc, char** argv)
 {	int n,c,j=1;
	while(scanf("%d%d",&n,&c)&&n)
	{
		int i;
		for(i=0;i<n;i++){
			scanf("%d%s%d",&stu[i].no,stu[i].name,&stu[i].grade);
		}
 		switch(c){
			case 1:qsort(stu,n,sizeof(stu[0]),sortByNo);
				   printf("Case %d:/n",j);	
			   display(n,stu);				   break;

			case 2:qsort(stu,n,sizeof(stu[0]),sortByName);
			 	   printf("Case %d:/n",j);
			 	   display(n,stu);
				   break;
			case 3:qsort(stu,n,sizeof(stu[0]),sortByGrade);
                   printf("Case %d:/n",j);	
			       display(n,stu);
				   break;
				}
		j++;
			}
	return 0;
}

