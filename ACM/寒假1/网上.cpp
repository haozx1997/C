#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct student{
    char id[10];
    char name[12];
    int score;
}stu[100005];
int cmp1(const void *a,const void *b){  //按学号排序
    student* ta=(student *)a;
    student* tb=(student *)b;
    return strcmp(ta->id,tb->id);
}
int cmp2(const void *a,const void *b){   //按姓名排序
    student* ta=(student *)a;
    student* tb=(student *)b;
    if(strcmp(ta->name,tb->name)==0)
        return strcmp(ta->id,tb->id);
    return strcmp(ta->name,tb->name);
}
int cmp3(const void *a,const void *b){      //按成绩排序
    student* ta=(student *)a;
    student* tb=(student *)b;
    if(ta->score==tb->score)
        return strcmp(ta->id,tb->id);
    return ta->score-tb->score;
}
int main(){
    int n,c;
    int i,j;
    int cases=1;
    while(cin>>n>>c && n){
        for(i=0;i<n;i++)
            cin>>stu[i].id>>stu[i].name>>stu[i].score;
        cout<<"Case "<<cases<<":"<<endl;
        if(c==1){
            qsort(stu,n,sizeof(student),cmp1);
            for(i=0;i<n;i++)
                cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
        }else if(c==2){
            qsort(stu,n,sizeof(student),cmp2);
            for(i=0;i<n;i++)
                cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
        }else{
            qsort(stu,n,sizeof(student),cmp3);
            for(i=0;i<n;i++)
                cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
        }
        cases++;
    }
    return 0;
}
