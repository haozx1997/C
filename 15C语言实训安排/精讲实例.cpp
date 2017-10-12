#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TITLE "ѧ���ɼ�����ϵͳ"  /*��������*/
#define MAX 10 /* */

#define MENU_MAIN_COUNT 9 /* ���˵���ѡ�����*/
#define MENU_SEARCH_COUNT 4 /*��ѯ�Ӳ˵���ѡ����� */
#define MENU_CALC_COUNT 3 /*ͳ���Ӳ˵���ѡ����� */

typedef struct student{
	char name[MAX]; /*����*/
	char num[MAX];  /*ѧ��*/
	char sex[MAX];  /*�Ա�*/
	int chinese;    /*���ĳɼ�*/
	int mathematic; /*��ѧ�ɼ�*/
	int english;    /*Ӣ��ɼ�*/
	int computer;   /*������ɼ�*/
	struct student *next;  /*ָ����һ��ѧ����ָ��*/
}stu;

stu *head = NULL; /*����ṹ�������ͷָ��*/ 

char menu_main[] = 
"|\n"
"| 1 ����ѧ���ɼ�\n"
"| 2 ��ʾѧ���ɼ�\n"
"| 3 ��ѯѧ���ɼ�\n"
"| 4 ����ѧ���ɼ�\n"
"| 5 ɾ��ѧ���ɼ�\n"
"| 6 ����ѧ���ɼ�\n"
"| 7 �����ļ�\n"
"| 8 ��ȡ�ļ�\n"
"| 9 �˳�ϵͳ\n"
"|\n"; 

void print_menu_tile(char *title){
	printf("=======================================\n");
	printf("| %s\n", title);
	printf("---------------------------------------\n");
}

/*
void input_record(){
	printf("����ִ��input_record����...\n");
	getch();
}
*/

void create_stu_by_input(stu *pNewStu){
	printf(">������ѧ����Ϣ��ע����󳤶���10���ַ�����\n");
	printf("ѧ�ţ�"); scanf("%s",pNewStu->num);
	printf("������"); scanf("%s",pNewStu->name);
	printf("�Ա�"); scanf("%s",pNewStu->sex);
	printf(">������%s�ĳɼ���ע���ɼ���Χ��1-100����\n", pNewStu->name);
	printf("���ģ�"); scanf("%d",&(pNewStu->chinese));
	printf("��ѧ��"); scanf("%d",&(pNewStu->mathematic));
	printf("Ӣ�"); scanf("%d",&(pNewStu->english));
	printf("�������"); scanf("%d",&(pNewStu->computer));
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
	
	printf("��������ѧ���ɼ���(Y ������ N ���ز˵�)");
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
	printf("����ִ��show_record����...\n");
	getch();
}
*/
 
void print_table_head(){
	printf("+----------+----------+----------+----+----+----+------+\n");
	printf("|   ѧ��   |   ����   |  �Ա�    |����|��ѧ|Ӣ��|�����|\n");
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
	printf("����������ز˵�...\n");
	getch();
//	getchar();
//	getchar();
	print_menu_main(); 
}

/*
void search_record(){
	printf("����ִ��search_record����...\n");
	getch();
}
*/

void search_record1(){
	void print_menu_main();
	printf("����ִ��search_record����...\n");
	printf("ִ����ϣ�\n");
	printf("����������ز˵�...\n");
	getch();
//	getchar();
//	getchar();
	print_menu_main(); 	
}
void update_record(){
	printf("����ִ��update_record����...\n");
	getch();
}

void delete_record(){
	printf("����ִ��delete_record����...\n");
	getch();
}

void calculate(){
	printf("����ִ��calculate����...\n");
	getch();
}

void save_to_file(){
	printf("����ִ��save_to_file����...\n");
	system("pause");
}

void save_to_file1(){
	void print_menu_main();
	FILE *fp;
	char file[100];
	stu *p= head;
	printf("�������ļ�����");
	scanf("%s", file);
	fp=fopen(file, "w");
	while(p != NULL){
		fprintf(fp, "%s %s %s %d %d %d %d\n",
					p->num, p->name, p->sex, p->chinese, p->mathematic, p->english, p->computer);
		p = p->next;
	}
	fclose(fp);
	printf("����ɹ���\n����������ز˵�..\n");
	getchar();
	getchar();
	print_menu_main(); 	
}

void load_from_file1(){
	void print_menu_main();
    void clear_record(stu *p); 
	FILE *fp; 
	char file[100];
	clear_record(head); /*�ͷ���������*/ 
	stu *p= head, *q;
	printf("�������ļ�����");
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
	printf("װ�سɹ���\n����������ز˵�..\n");
	getchar();
	getchar();
	print_menu_main(); 	
}

void exit_system(){
	printf("����ִ��exit_system����...\n");
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
	clear_record(head); /*�ͷ���������*/ 
	printf("�����Ѿ��ͷţ�\n"); 
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
		printf(">��ѡ��");
		scanf("%d",&selected);
		if(selected >= 1 && selected <= MENU_MAIN_COUNT){
			break;
		}
		printf("\n>������󣡣�ע����ѡ�� 1 - %d)\n", MENU_MAIN_COUNT);
	}

	menu_main_func[selected-1]();  
}

int main(){
	print_menu_main();
}

