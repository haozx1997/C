//��ʱ����scanf�Ļ������������ڲ˵�ѡ��ʱ���Ȱѻ������뵼�� ������������������롱����ȷ���������Ƿ������� 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct worker
{
	int num;
	char name[20];
	int basic,job,pay,medical,gong,total;//�������ʡ�ְ���ʡ���λ������ҽ�Ʊ��ա�������
};struct worker wo[100];
int work_num;//ְ�������� 
int work_num_now;//���������ְ���ǵڼ��� 
int i;

void menu_main();

void input_record()//���� 
{
	system("cls");
	printf("                 ����ְ����Ϣ\n");
	printf("������ְ��������");
	scanf("%d",&work_num);
	work_num_now=work_num;	
	
	while(work_num_now--)
	{
		printf("������ְ��ID��       ");
		scanf("%d",&wo[work_num_now].num); 
		printf("������ְ��������     ");
		scanf("%s",&wo[work_num_now].name);		
		printf("������ְ���������ʣ� "); 
		scanf("%d",&wo[work_num_now].basic);
		printf("������ְ��ְ���ʣ� ");
		scanf("%d",&wo[work_num_now].job);
		printf("������ְ����λ������ ");
		scanf("%d",&wo[work_num_now].pay);
		printf("������ְ��ҽ�Ʊ��գ� ");
		scanf("%d",&wo[work_num_now].medical);
		printf("������ְ��������   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;


	}
	printf("\n\n¼����ϰ���������ز˵�");
	getchar(); 
	menu_main();
}

void show_record()//�鿴 
{
	system("cls");
	printf("                 �鿴ְ����Ϣ\n");
	printf("  ID��    ����   ��������   ְ����   ��λ����   ҽ�Ʊ���   ������    �ܹ���\n");
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
    printf("\n\n����������ز˵�");
	getchar(); 
   	menu_main();
}


void search_record()//��ѯ 
{
	system("cls");
	printf("                 ��ѯְ����Ϣ\n");
    
	
	printf("\n\n����������ز˵�");
	getchar(); 	
	menu_main();
}

void add_record()//��� 
{
	system("cls");
	printf("                 ���ְ����Ϣ\n");
	

    printf("\n\n����������ز˵�");
	getchar(); 
	menu_main();
}

void delete_record()//ɾ�� 
{
	system("cls");
	printf("                 ɾ��ְ����Ϣ\n");
	

    printf("\n\n����������ز˵�");
	getchar(); 
	menu_main();
}

void updata_record()//���� 
{
	system("cls");
	printf("                 ����ְ����Ϣ\n");

    printf("\n\n����������ز˵�");
	getchar(); 	
	menu_main();
}

void statistics_record()//ͳ�� 
{
	system("cls");
	printf("                 ͳ��ְ����Ϣ\n");
	
    printf("\n\n����������ز˵�");
	getchar(); 
	menu_main();
}

void choose()//�˵�ѡ�� 
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
		default:printf("�����������������: ");;choose();
	}
}


void menu_main()//��ʾ�˵� 
{
	system("cls");
	printf("               ְ�����ʹ���ϵͳ\n");
	printf("=======================================================\n");
	printf("                    �˵�\n");
	printf("               1 ����ְ����Ϣ\n");
	printf("               2 �鿴ְ����Ϣ\n");
	printf("               3 ��ѯְ����Ϣ\n");
	printf("               4 ���ְ����Ϣ\n");
	printf("               5 ɾ��ְ����Ϣ\n");
	printf("               6 ����ְ����Ϣ\n");
	printf("               7 ͳ��ְ����Ϣ\n");
	printf("               8 �˳�ϵͳ\n\n");
	printf("��ѡ��"); 
	choose();

}





int main()
{
	menu_main();	
}
