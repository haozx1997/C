//有时候在scanf的缓存区有数据在菜单选择时会先把缓存输入导致 “输入错误请重新输入”但不确定缓存区是否有数据 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>

struct worker
{
	int num;
	char name[20];
	int basic,job,pay,medical,gong,total;//基本工资、职务工资、岗位津贴、医疗保险、公积金
};struct worker wo[100];
int work_num;//职工总人数 
int work_num_now;//现在输入的职工是第几个 
int i;
double a_basic,a_job,a_pay,a_medical,a_gong,a_total;
int s_basic,s_job,s_pay,s_medical,s_gong,s_total;

void menu_main();
void search_id();
void search_name();
void choose_search();
void choose_delete();
void delete_id();
void delete_name();
void choose_updata();
void updata_id();
void updata_name();


void input_record()//输入 
{
	system("cls");
	printf("                 输入职工信息\n");
	printf("请输入职工人数；");
	scanf("%d",&work_num);
	i=work_num;	
	work_num_now=0;
	while(i--)
	{
		printf("请输入职工ID：       ");
		scanf("%d",&wo[work_num_now].num); 
		printf("请输入职工姓名：     ");
		scanf("%s",&wo[work_num_now].name);		
		printf("请输入职工基本工资： "); 
		scanf("%d",&wo[work_num_now].basic);
		printf("请输入职工职务工资： ");
		scanf("%d",&wo[work_num_now].job);
		printf("请输入职工岗位津贴： ");
		scanf("%d",&wo[work_num_now].pay);
		printf("请输入职工医疗保险： ");
		scanf("%d",&wo[work_num_now].medical);
		printf("请输入职工公积金：   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;
        work_num_now++;

	}
	printf("\n\n录入完毕按任意键返回菜单");
	getch(); 
	menu_main();
}

void show_record()//查看 
{
	system("cls");
	printf("                 查看职工信息\n");
	printf("  ID号    姓名   基本工资   职务工资   岗位津贴   医疗保险   公积金    总工资\n");
	i=work_num;	
	work_num_now=0;
	while(i--)
	{
		
		printf("%6d",wo[work_num_now].num); 
		printf("%8s",wo[work_num_now].name);		
		printf("%11d",wo[work_num_now].basic);
		printf("%11d",wo[work_num_now].job);
		printf("%11d",wo[work_num_now].pay);
		printf("%11d",wo[work_num_now].medical);
		printf("%9d",wo[work_num_now].gong);
		printf("%10d\n",wo[work_num_now].total);		
	    work_num_now++;

    }
    printf("\n\n按任意键返回菜单");
	getch(); 
   	menu_main();
}


void search_record()//查询 
{
	system("cls");
	printf("                 查询职工信息\n\n");
	printf("1. 按ID查找\n");
	printf("2. 按姓名查找\n");
	printf("3. 返回主菜单\n");
    printf("请选择： ");
    choose_search();
	
}

void choose_search()//还不是因为用户要输错
{
	int how_search;
	scanf("%d",&how_search);
	switch(how_search)
	{
		case 1:search_id();break;
		case 2:search_name();break;
		case 3:menu_main();break; 
		default:printf("输入错误请重新输入: ");getchar();choose_search();
	}
 } 


void search_id()//按ID查找 
{
	system("cls");
	printf("                 按ID查找\n");
	
	int the_id,TF=0;//是否有此ID 
	printf("输入要查找的ID:"); 
	scanf("%d",&the_id);
	for(i=0;i<work_num;i++)
	{
		if(wo[i].num==the_id)
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
		printf("%6d",wo[i].num); 
		printf("%8s",wo[i].name);		
		printf("%11d",wo[i].basic);
		printf("%11d",wo[i].job);
		printf("%11d",wo[i].pay);
		printf("%11d",wo[i].medical);
		printf("%9d",wo[i].gong);
		printf("%10d\n",wo[i].total);	 	
	 }
	else printf("无此ID\n"); 
  	
    printf("\n\n按任意键返回上一级");
	getch();
	search_record();
}

void search_name()//按姓名查找 
{
	system("cls");
	printf("                 按姓名查找\n");
	
    char the_name[20];
    int TF=0;
	printf("输入要查找的姓名:"); 
	scanf("%s",the_name);
	for(i=0;i<work_num;i++)
	{
		
		if(!strcmp(the_name,wo[i].name))
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
	    printf("  ID号    姓名   基本工资   职务工资   岗位津贴   医疗保险   公积金    总工资\n");	 	
		printf("%6d",wo[i].num); 
		printf("%8s",wo[i].name);		
		printf("%11d",wo[i].basic);
		printf("%11d",wo[i].job);
		printf("%11d",wo[i].pay);
		printf("%11d",wo[i].medical);
		printf("%9d",wo[i].gong);
		printf("%10d\n",wo[i].total);	 	
	 }
	else printf("查无此人\n");	
  	
    printf("\n\n按任意键返回上一级");
	getch();
	search_record();
}





void add_record()//添加 
{
	system("cls");
	printf("                 添加职工信息\n");
	
	printf("请添加输入职工人数；");
	int add_num; 
	scanf("%d",&add_num);
	
	work_num_now=work_num;
	work_num+=add_num;
	while(add_num--)
	{
		printf("请输入职工ID：       ");
		scanf("%d",&wo[work_num_now].num); 
		printf("请输入职工姓名：     ");
		scanf("%s",&wo[work_num_now].name);		
		printf("请输入职工基本工资： "); 
		scanf("%d",&wo[work_num_now].basic);
		printf("请输入职工职务工资： ");
		scanf("%d",&wo[work_num_now].job);
		printf("请输入职工岗位津贴： ");
		scanf("%d",&wo[work_num_now].pay);
		printf("请输入职工医疗保险： ");
		scanf("%d",&wo[work_num_now].medical);
		printf("请输入职工公积金：   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;
        work_num_now++;

	}


    printf("\n\n按任意键返回菜单");
	getch();
	menu_main();
}

void delete_record()//删除 
{
	system("cls");
	printf("                 删除职工信息\n");
	
 	printf("1. 按ID删除\n");
	printf("2. 按姓名删除\n");
	printf("3. 返回主菜单\n");
    printf("请选择： ");
    choose_delete();
  	
    printf("\n\n按任意键返回菜单");
	getch();
	menu_main();
}

void choose_delete()//还不是因为用户要输错
{
	int how_search;
	scanf("%d",&how_search);
	switch(how_search)
	{
		case 1:delete_id();break;
		case 2:delete_name();break;
		case 3:menu_main();break; 
		default:printf("输入错误请重新输入: ");getchar();choose_delete();
	}
 }
 
 
void delete_id()//按ID删除 
{
	system("cls");
	printf("                 按ID删除\n");
	
	int the_id,TF=0;//是否有此ID 
	printf("输入要删除的ID:"); 
	scanf("%d",&the_id);
	for(i=0;i<work_num;i++)
	{
		if(wo[i].num==the_id)
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
        for(;i<work_num;i++)
         wo[i]=wo[i+1];
        work_num--; 
	}
	else printf("无此ID\n"); 
  	
    printf("\n\nID为%d的职工删除成功\n\n按任意键返回上一级",the_id);
	getch();
	delete_record();	
}

void delete_name()//按名字删除
{
	system("cls");
	printf("                 按姓名删除\n");
	
    char the_name[20];
    int TF=0;
	printf("输入要删除的姓名:"); 
	scanf("%s",the_name);
	for(i=0;i<work_num;i++)
	{
		
		if(!strcmp(the_name,wo[i].name))
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
        for(;i<work_num;i++)
         wo[i]=wo[i+1];
        work_num--; 	 	
	 }
	else printf("查无此人\n");	
  	
    printf("\n\n%s已删除\n\n按任意键返回上一级",the_name);
	getch();
	delete_record();
}	
 
 



void updata_record()//更新 
{
	system("cls");
	printf("                 更新职工信息\n");
	
	printf("1. 按ID更新\n");
	printf("2. 按姓名更新\n");
	printf("3. 返回主菜单\n");
    printf("请选择： ");
    choose_updata();

    printf("\n\n按任意键返回菜单");
	getch();	
	menu_main();
}

void choose_updata()//还不是因为用户要输错
{
	int how_search;
	scanf("%d",&how_search);
	switch(how_search)
	{
		case 1:updata_id();break;
		case 2:updata_name();break;
		case 3:menu_main();break; 
		default:printf("输入错误请重新输入: ");getchar();choose_updata();
	}
 }
 
 
void updata_id()//按ID更新 
{
	system("cls");
	printf("                 按ID更新\n");
	
	int the_id,TF=0;//是否有此ID 
	printf("输入要更新的ID:"); 
	scanf("%d",&the_id);
	for(i=0;i<work_num;i++)
	{
		if(wo[i].num==the_id)
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
	    printf("  ID号    姓名   基本工资   职务工资   岗位津贴   医疗保险   公积金    总工资\n");	 	
		printf("%6d",wo[i].num); 
		printf("%8s",wo[i].name);		
		printf("%11d",wo[i].basic);
		printf("%11d",wo[i].job);
		printf("%11d",wo[i].pay);
		printf("%11d",wo[i].medical);
		printf("%9d",wo[i].gong);
		printf("%10d\n",wo[i].total);
			 	
	 	printf("请更新该职工信息\n");
		printf("请输入职工ID：       ");
		scanf("%d",&wo[i].num); 
		printf("请输入职工姓名：     ");
		scanf("%s",&wo[i].name);		
		printf("请输入职工基本工资： "); 
		scanf("%d",&wo[i].basic);
		printf("请输入职工职务工资： ");
		scanf("%d",&wo[i].job);
		printf("请输入职工岗位津贴： ");
		scanf("%d",&wo[i].pay);
		printf("请输入职工医疗保险： ");
		scanf("%d",&wo[i].medical);
		printf("请输入职工公积金：   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;	 	
     }
	else printf("无此ID\n"); 
  	
    printf("\n\nID为%d的职工更新成功\n\n按任意键返回上一级",the_id);
	getch();
	updata_record();	
}

void updata_name()//按名字更新
{
	system("cls");
	printf("                 按姓名更新\n");
	
    char the_name[20];
    int TF=0;
	printf("输入要更新的姓名:"); 
	scanf("%s",the_name);
	for(i=0;i<work_num;i++)
	{
		
		if(!strcmp(the_name,wo[i].name))
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
	    printf("  ID号    姓名   基本工资   职务工资   岗位津贴   医疗保险   公积金    总工资\n");	 	
		printf("%6d",wo[i].num); 
		printf("%8s",wo[i].name);		
		printf("%11d",wo[i].basic);
		printf("%11d",wo[i].job);
		printf("%11d",wo[i].pay);
		printf("%11d",wo[i].medical);
		printf("%9d",wo[i].gong);
		printf("%10d\n",wo[i].total);
			 	
	 	printf("请更新该职工信息\n");
		printf("请输入职工ID：       ");
		scanf("%d",&wo[i].num); 
		printf("请输入职工姓名：     ");
		scanf("%s",&wo[i].name);		
		printf("请输入职工基本工资： "); 
		scanf("%d",&wo[i].basic);
		printf("请输入职工职务工资： ");
		scanf("%d",&wo[i].job);
		printf("请输入职工岗位津贴： ");
		scanf("%d",&wo[i].pay);
		printf("请输入职工医疗保险： ");
		scanf("%d",&wo[i].medical);
		printf("请输入职工公积金：   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;	 	
	 }
	else printf("查无此人\n");	
  	
    printf("\n\n%s已更新\n\n按任意键返回上一级",the_name);
	getch();
	updata_record();
}	

void statistics_record()//统计 
{
	system("cls");
	printf("                 统计职工信息\n");
	
	
	printf("  ID号    姓名   基本工资   职务工资   岗位津贴   医疗保险   公积金    总工资\n");
	i=work_num;	
	work_num_now=0;
	while(i--)
	{
		
		printf("%6d",wo[work_num_now].num); 
		printf("%8s",wo[work_num_now].name);		
		printf("%11d",wo[work_num_now].basic);
		printf("%11d",wo[work_num_now].job);
		printf("%11d",wo[work_num_now].pay);
		printf("%11d",wo[work_num_now].medical);
		printf("%9d",wo[work_num_now].gong);
		printf("%10d\n",wo[work_num_now].total);		
	    work_num_now++;

    }	
    s_basic=s_job=s_pay=s_medical=s_gong=s_total=0;
    for(i=0;i<work_num;i++)
    {
    	s_basic+=wo[i].basic;
    	s_job+=wo[i].job;
    	s_pay+=wo[i].pay;
    	s_medical+=wo[i].medical;
    	s_gong+=wo[i].gong;
    	s_total+=wo[i].total;
   	}
   	a_basic=(double)s_basic/(work_num);
   	a_job=(double)s_job/(work_num);
   	a_pay=(double)s_pay/(work_num);
   	a_medical=(double)s_medical/(work_num);
   	a_gong=(double)s_gong/(work_num);
   	a_total=(double)s_total/(work_num);
   	
    printf("各项平均工资    %9.2f%11.2f%11.2f%11.2f%9.2f%10.2f",a_basic,a_job,a_pay,a_medical,a_gong,a_total);
	
    printf("\n\n按任意键返回菜单");
	getch();
	menu_main();
}

void file_save()//导出 
{
	system("cls");
	printf("                 导出信息到文件\n");
	
	FILE *filep;
	int i;
	if((filep=fopen("F:\\C\\15C语言实训安排\\15zhigong.txt","wb"))==NULL)
	 {
	 	printf("cannot open file\n");
	 	return;
	  } 
	for(i=0;i<work_num;i++)
	 if(fwrite(&wo[i],sizeof(struct worker),1,filep)!=1)
	  {
	  	 printf("file write error\n");
	  	 getch();
	  	 return;
	  }  
	 fclose(filep);
	  
	
    printf("\n\n文件已保存\n\n按任意键返回菜单");
	getch();
	menu_main();
}


void file_in()//导入 
{
	system("cls");
	printf("                 导入信息文件\n");
	
	int i=0,F=2;//F用于关闭 
	FILE *filep;
	filep=fopen("F:\\C\\15C语言实训安排\\15zhigong.txt","rb");
	while(1)
	{
		if( feof(filep))break;
		
		fread(&wo[i],sizeof(struct worker),1,filep);
		
		i++;

	
		
	}
	work_num=--i;
	fclose(filep);
	
	
    printf("文件导入成功\n\n按任意键返回菜单");
	getch();
	menu_main();
}

void choose()//菜单选择 
{
	int menu ;
	scanf("%d",&menu);
	getchar();
	switch(menu)
	{
		case 1:input_record();break;
		case 2:show_record();break;
		case 3:search_record();break;
		case 4:add_record();break;
		case 5:delete_record();break;
		case 6:updata_record();break;
		case 7:statistics_record();break;
		case 8:file_save();break;
		case 9:file_in();break;
		case 0:exit(0);
		default:printf("输入错误请重新输入: ");choose();
	}
}


void menu_main()//显示菜单 
{
	system("cls");
	printf("               职工工资管理系统\n");
	printf("=======================================================\n");
	printf("                    菜单\n");
	printf("               1 输入职工信息\n");
	printf("               2 查看职工信息\n");
	printf("               3 查询职工信息\n");
	printf("               4 添加职工信息\n");
	printf("               5 删除职工信息\n");
	printf("               6 更新职工信息\n");
	printf("               7 统计职工信息\n");
	printf("               8 导出信息到文件\n");	
	printf("               9 导入信息文件\n");	
	printf("               0 退出系统\n\n");
	printf("请选择："); 
	choose();

}





int main()
{
	menu_main();	
}
