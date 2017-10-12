//有时候在scanf的缓存区有数据在菜单选择时会先把缓存输入导致 “输入错误请重新输入”但不确定缓存区是否有数据 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct worker
{
	int num;
	char name[20];
	int basic,job,pay,medical,gong,total;//基本工资、职务工资、岗位津贴、医疗保险、公积金
};struct worker wo[100];
int work_num;//职工总人数 
int work_num_now;//现在输入的职工是第几个 
int i;

void menu_main();

void input_record()//输入 
{
	system("cls");
	printf("                 输入职工信息\n");
	printf("请输入职工人数；");
	scanf("%d",&work_num);
	work_num_now=work_num;	
	
	while(work_num_now--)
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


	}
	printf("\n\n录入完毕按任意键返回菜单");
	getchar(); 
	menu_main();
}

void show_record()//查看 
{
	system("cls");
	printf("                 查看职工信息\n");
	printf("  ID号    姓名   基本工资   职务工资   岗位津贴   医疗保险   公积金    总工资\n");
	work_num_now=work_num;	
	while(work_num_now--)
	{
		
		printf("%6d",wo[work_num_now].num); 
		printf("%8s",wo[work_num_now].name);		
		printf("%11d",wo[work_num_now].basic);
		printf("%11d",wo[work_num_now].job);
		printf("%11d",wo[work_num_now].pay);
		printf("%11d",wo[work_num_now].medical);
		printf("%9d",wo[work_num_now].gong);
		printf("%10d\n",wo[work_num_now].total);		
	

    }
    printf("\n\n按任意键返回菜单");
	getchar(); 
   	menu_main();
}


void search_record()//查询 
{
	system("cls");
	printf("                 查询职工信息\n");
    
	
	printf("\n\n按任意键返回菜单");
	getchar(); 	
	menu_main();
}

void add_record()//添加 
{
	system("cls");
	printf("                 添加职工信息\n");
	

    printf("\n\n按任意键返回菜单");
	getchar(); 
	menu_main();
}

void delete_record()//删除 
{
	system("cls");
	printf("                 删除职工信息\n");
	

    printf("\n\n按任意键返回菜单");
	getchar(); 
	menu_main();
}

void updata_record()//更新 
{
	system("cls");
	printf("                 更新职工信息\n");

    printf("\n\n按任意键返回菜单");
	getchar(); 	
	menu_main();
}

void statistics_record()//统计 
{
	system("cls");
	printf("                 统计职工信息\n");
	
    printf("\n\n按任意键返回菜单");
	getchar(); 
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
		case 8:exit(0);
		default:printf("输入错误请重新输入: ");;choose();
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
	printf("               8 退出系统\n\n");
	printf("请选择："); 
	choose();

}





int main()
{
	menu_main();	
}
