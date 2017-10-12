#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TITLE "学生成绩管理系统"  /*标题文字*/
#define MAX 10 /* */

#define MENU_MAIN_COUNT 9 /* 主菜单的选项个数*/
#define MENU_SEARCH_COUNT 4 /*查询子菜单的选项个数 */
#define MENU_CALC_COUNT 3 /*统计子菜单的选项个数 */

typedef struct student{
	char name[MAX]; /*姓名*/
	char num[MAX];  /*学号*/
	char sex[MAX];  /*性别*/
	int chinese;    /*语文成绩*/
	int mathematic; /*数学成绩*/
	int english;    /*英语成绩*/
	int computer;   /*计算机成绩*/
	struct student *next;  /*指向下一个学生的指针*/
}stu;

stu *head = NULL; /*定义结构体链表的头指针*/ 

char menu_main[] = 
"|\n"
"| 1 输入学生成绩\n"
"| 2 显示学生成绩\n"
"| 3 查询学生成绩\n"
"| 4 更新学生成绩\n"
"| 5 删除学生成绩\n"
"| 6 计算学生成绩\n"
"| 7 保存文件\n"
"| 8 读取文件\n"
"| 9 退出系统\n"
"|\n"; 

void print_menu_tile(char *title){
	printf("=======================================\n");
	printf("| %s\n", title);
	printf("---------------------------------------\n");
}

/*
void input_record(){
	printf("正在执行input_record函数...\n");
	getch();
}
*/

void create_stu_by_input(stu *pNewStu){
	printf(">请输入学生信息（注：最大长度是10个字符）：\n");
	printf("学号："); scanf("%s",pNewStu->num);
	printf("姓名："); scanf("%s",pNewStu->name);
	printf("性别："); scanf("%s",pNewStu->sex);
	printf(">请输入%s的成绩（注：成绩范围是1-100）：\n", pNewStu->name);
	printf("语文："); scanf("%d",&(pNewStu->chinese));
	printf("数学："); scanf("%d",&(pNewStu->mathematic));
	printf("英语："); scanf("%d",&(pNewStu->english));
	printf("计算机："); scanf("%d",&(pNewStu->computer));
}

stu* get_last_student(stu *p){
	if(p->next == NULL){
		return p;
	}
	else{
		get_last_student(p->next);
	}
}

void input_record1(){
	void print_menu_main();
	char continue_input = 'N';
	stu *pLastStu = NULL;
	stu *pNewStu = (stu *)malloc(sizeof(stu));
	pNewStu->next = NULL;
	create_stu_by_input(pNewStu);
	if(head == NULL){
		head = pNewStu;
	}  
	else{
		pLastStu = get_last_student(head);
		pLastStu->next = pNewStu;
	}
	
	printf("继续输入学生成绩？(Y 继续， N 返回菜单)");
	getchar();
	continue_input = getchar();
	if (continue_input == 'n' || continue_input == 'N'){
		print_menu_main();
	}
	else{
		input_record1();
	}
}

/* 
void show_record(){
	printf("正在执行show_record函数...\n");
	getch();
}
*/
 
void print_table_head(){
	printf("+----------+----------+----------+----+----+----+------+\n");
	printf("|   学号   |   姓名   |  性别    |语文|数学|英语|计算机|\n");
	printf("+----------+----------+----------+----+----+----+------+\n");	
}

void print_table_buttom(){
	printf("+----------+----------+----------+----+----+----+------+\n");
}  

void print_table_row(stu *p){
	printf("|%10s|%10s|%10s|%4d|%4d|%4d|%6d|\n",
			p->num,p->name,p->sex,p->chinese,p->mathematic,p->english,p->computer);
}

void show_record1(){
	void print_menu_main();
	stu *p = head;
	print_table_head();
	while(p != NULL) {
		print_table_row(p);
		p = p->next;
	}
	print_table_buttom();
	printf("按任意键返回菜单...\n");
	getch();
//	getchar();
//	getchar();
	print_menu_main(); 
}

/*
void search_record(){
	printf("正在执行search_record函数...\n");
	getch();
}
*/

void search_record1(){
	void print_menu_main();
	printf("正在执行search_record函数...\n");
	printf("执行完毕！\n");
	printf("按任意键返回菜单...\n");
	getch();
//	getchar();
//	getchar();
	print_menu_main(); 	
}
void update_record(){
	printf("正在执行update_record函数...\n");
	getch();
}

void delete_record(){
	printf("正在执行delete_record函数...\n");
	getch();
}

void calculate(){
	printf("正在执行calculate函数...\n");
	getch();
}

void save_to_file(){
	printf("正在执行save_to_file函数...\n");
	system("pause");
}

void save_to_file1(){
	void print_menu_main();
	FILE *fp;
	char file[100];
	stu *p= head;
	printf("请输入文件名：");
	scanf("%s", file);
	fp=fopen(file, "w");
	while(p != NULL){
		fprintf(fp, "%s %s %s %d %d %d %d\n",
					p->num, p->name, p->sex, p->chinese, p->mathematic, p->english, p->computer);
		p = p->next;
	}
	fclose(fp);
	printf("保存成功！\n按任意键返回菜单..\n");
	getchar();
	getchar();
	print_menu_main(); 	
}

void load_from_file1(){
	void print_menu_main();
    void clear_record(stu *p); 
	FILE *fp; 
	char file[100];
	clear_record(head); /*释放整个链表*/ 
	stu *p= head, *q;
	printf("请输入文件名：");
	scanf("%s", file);
	fp=fopen(file, "r");
	
	stu *pLastStu = NULL;
	
	while(!feof(fp)){
		stu *pNewStu = (stu *)malloc(sizeof(stu));
		pNewStu->next = NULL;
	
		fscanf(fp, "%s %s %s %d %d %d %d",
					pNewStu->num, pNewStu->name, pNewStu->sex, 
					&(pNewStu->chinese), &(pNewStu->mathematic), &(pNewStu->english), &(pNewStu->computer));
		
		if(head == NULL){
			head = pNewStu;
		}  
		else{
			pLastStu = get_last_student(head);
			pLastStu->next = pNewStu;
		}		
	}
	
	q = head;
	while(q->next->next != NULL){
		q = q->next;
	}
	free(q->next);
	q->next = NULL;

	fclose(fp);
	printf("装载成功！\n按任意键返回菜单..\n");
	getchar();
	getchar();
	print_menu_main(); 	
}

void exit_system(){
	printf("正在执行exit_system函数...\n");
	getch();
}

void clear_record(stu *p){
	if(p==NULL){
		return;
	}
	
	if(p->next ==NULL){
		free(p);
	}
	else{
		clear_record(p->next);
		free(p);
		p = NULL;
	}
} 

void exit_system1(){
	clear_record(head); /*释放整个链表*/ 
	printf("链表已经释放！\n"); 
	exit(0); 
}

void (* menu_main_func[])()= 
{
	input_record1,
	show_record1,
	search_record1,
	update_record,
	delete_record,
	calculate,
	save_to_file1,
	load_from_file1,
	exit_system1
};	

void print_menu_main(){
	int selected = 0;
	system("cls");
//	void (* menu_main_f0)() = input_record;
	print_menu_tile(TITLE);
	printf(menu_main);
	printf("=======================================\n");
	
	while(!(selected >= 1 && selected <= MENU_MAIN_COUNT)){
		printf(">请选择：");
		scanf("%d",&selected);
		if(selected >= 1 && selected <= MENU_MAIN_COUNT){
			break;
		}
		printf("\n>输入错误！（注：请选择 1 - %d)\n", MENU_MAIN_COUNT);
	}

	menu_main_func[selected-1]();  
}

int main(){
	print_menu_main();
}

